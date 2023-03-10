/*
 * This file is a part of the TChecker project.
 *
 * See files AUTHORS and LICENSE for copyright details.
 *
 */

#include <vector>

#include "tchecker/expression/expression.hh"
#include "tchecker/fsm/details/builder.hh"
#include "tchecker/fsm/details/output.hh"
#include "tchecker/fsm/system.hh"
#include "tchecker/statement/statement.hh"
#include "tchecker/system/output.hh"

namespace tchecker {
  
  namespace fsm {
    
    // system_t
    
    void system_t::add_edge(std::string const & process_name,
                            std::string const & src_name,
                            std::string const & tgt_name,
                            std::string const & event_name,
                            tchecker::expression_t * guard,
                            tchecker::statement_t * statement,
                            bool stop,
                            bool push_or_pop,
                            std::string symbol,
                            int constraint,
                            int fin)
    {
      tchecker::fsm::edge_t * edge = nullptr;
      
      try {
        // Process identifier
        tchecker::process_id_t pid = _processes.key(process_name);
        
        // Identifier
        tchecker::edge_id_t id = next_edge_id();
        
        // Locations and event
        tchecker::fsm::loc_t * src = this->location(process_name, src_name);
        tchecker::fsm::loc_t * tgt = this->location(process_name, tgt_name);
        tchecker::event_id_t event_id = _events.key(event_name);
        
        // Create the edge
        edge = new tchecker::fsm::edge_t(pid, id, src, tgt, event_id, guard, statement, stop, push_or_pop, symbol, constraint, fin);
        
        // Add the edge
        tchecker::fsm::details::system_t<tchecker::fsm::loc_t, tchecker::fsm::edge_t>::add_edge(edge, src, tgt);
      }
      catch (...) {
        delete edge;
        throw;
      }
    }
    
    
    
    
    // System builder
    
    /*!
     \class location_attributes_parser_t
     \brief Parser for location attributes
     \note Interpreted attributes: initial, invariant and labels
     */
    class location_attributes_parser_t final : public tchecker::fsm::details::location_attributes_parser_t {
    public:
      using tchecker::fsm::details::location_attributes_parser_t::location_attributes_parser_t;
    };
    
    
    
    
    /*!
     \class edge_attributes_parser_t
     \brief Parser for edge attributes
     \note Interpreted attributes: do and provided
     */
    class edge_attributes_parser_t final : public tchecker::fsm::details::edge_attributes_parser_t {
    public:
      using tchecker::fsm::details::edge_attributes_parser_t::edge_attributes_parser_t;
    };
    
    
    
    
    /*!
     \class system_builder_t
     \brief Fills system from declarations
     \note Interpreted location attributes: initial, invariant and labels
     \note Interpreted edge attributes: do and provided
     */
    class system_builder_t final : public tchecker::fsm::details::system_builder_t<tchecker::fsm::system_t> {
    public:
      /*!
       \brief Constructor
       */
      system_builder_t(tchecker::log_t & log) : tchecker::fsm::details::system_builder_t<tchecker::fsm::system_t>(log)
      {}
      
      
      /*!
       \brief Copy constructor (DELETED)
       */
      system_builder_t(tchecker::fsm::system_builder_t const &) = delete;
      
      
      /*!
       \brief Move constructor (DELETED)
       */
      system_builder_t(tchecker::fsm::system_builder_t &&) = delete;
      
      
      /*!
       \brief Destructor
       */
      virtual ~system_builder_t() = default;
      
      
      /*!
       \brief Assignment operator (DELETED)
       */
      tchecker::fsm::system_builder_t & operator= (tchecker::fsm::system_builder_t const &) = delete;
      
      
      /*!
       \brief Move assignment operator (DELETED)
       */
      tchecker::fsm::system_builder_t & operator= (tchecker::fsm::system_builder_t &&) = delete;
      
      
      /*!
       \brief Add clock variable
       */
      virtual void visit(tchecker::parsing::clock_declaration_t const & d)
      {
        this->_log.warning("", "ignoring clock declaration " + d.name());
      }
      
      
      /*!
       \brief Add location
       \note Intepreted attributes: initial, invariant and labels
       */
      virtual void visit(tchecker::parsing::location_declaration_t const & d)
      {
        bool initial = false;
        tchecker::expression_t * invariant = nullptr;
        std::vector<std::string> labels;
        
        try {
          tchecker::fsm::location_attributes_parser_t
          attr_parser(this->_log, initial, invariant, labels);
          
          attr_parser.parse(d.attributes());
          
          // index new labels
          for (std::string const & label : labels)
            if (this->_system->labels().find_value(label) == this->_system->labels().end_value_map())
              this->_system->add_label(label);
          
          this->_system->add_location(d.process().name(), d.name(), initial, invariant,
                                      tchecker::make_range(labels.begin(), labels.end()));
        }
        catch (std::exception const & e) {
          this->_log.error("location " + d.name() + " in process " + d.process().name(), e.what());
          delete invariant;
          throw;
        }
      }
      
      
      /*!
       \brief Add edges
       \note Intepreted attributes: provided and do
       */
      virtual void visit(tchecker::parsing::edge_declaration_t const & d)
      {
        tchecker::expression_t * guard = nullptr;
        tchecker::statement_t * statement = nullptr;
        
        try {
          tchecker::fsm::edge_attributes_parser_t attr_parser(this->_log, guard, statement);
          
          attr_parser.parse(d.attributes());
          tchecker::parsing::stack_op sop = d.stack_operation();
          std::cout << "STACK OPERATION:\t" << sop.key() << " " << sop.value() << "\n";
          bool stop = 0;
          bool push_or_pop;
          std::string symbol = "";
          int constraint;
          int fin;
          if(sop.key() == "push"){
            stop = 1;
            push_or_pop = 0;
            symbol = sop.value();
          } else if (sop.key() == "pop"){
            stop = 1;
            push_or_pop = 1;
            std::string full_expr = sop.value();
            int i = 0;
            for(; i < full_expr.size() ; i++){
              if(full_expr[i] == '<' || full_expr[i] == '>')  break;
              symbol += full_expr[i];
            }
            if(full_expr[i] == '<'){
              if(full_expr[i + 1] == '='){
                constraint = 1;
                i += 2;
              }
              else{
                constraint = 0;
                i++;
              }
            } else {
              if(full_expr[i + 1] == '='){
                constraint = 2;
                i += 2;
              }
              else{
                constraint = 3;
                i++;
              }
            }
            std::string temp = "";
            for(; i < full_expr.size() ; i++){
              temp += full_expr[i];
            }
            fin = stoi(temp);
          }
          this->_system->add_edge(d.process().name(), d.src().name(), d.tgt().name(), d.event().name(), guard, statement, stop, push_or_pop, symbol, constraint, fin);
        }
        catch (std::exception const & e) {
          this->_log.error("edge " + d.src().name() + "->" + d.tgt().name() + " in process " + d.process().name(), e.what());
          delete guard;
          delete statement;
          throw;
        }
      }
      
      
      // Other methods visit()
      using tchecker::fsm::details::system_builder_t<tchecker::fsm::system_t>::visit;
    };
    
    
    
    // build_system
    
    tchecker::fsm::system_t * build_system(tchecker::parsing::system_declaration_t const & sysdecl, tchecker::log_t & log)
    {
      tchecker::fsm::system_builder_t v(log);
      
      try {
        sysdecl.visit(v);
      }
      catch (...) {
        throw;
      }
      
      return v.release();
    }
    
    
    
    
    // Output system
    
    void tchecker_output_location(std::ostream & os, tchecker::fsm::system_t const & s, tchecker::fsm::loc_t const & loc)
    {
      tchecker::tchecker_output_location(os, s, loc);
      os << "{";
      if (loc.initial()) {
        tchecker::fsm::details::tchecker_output_location_initial_flag(os, s, loc);
        os << " : ";
      }
      tchecker::fsm::details::tchecker_output_location_invariant(os, s, loc);
      os << " : ";
      tchecker::fsm::details::tchecker_output_location_labels(os, s, loc);
      os << "}";
      os << std::endl;
    }
    
    
    void tchecker_output_edge(std::ostream & os, tchecker::fsm::system_t const & s, tchecker::fsm::edge_t const & edge)
    {
      tchecker::tchecker_output_edge(os, s, edge);
      os << "{";
      tchecker::fsm::details::tchecker_output_edge_guard(os, s, edge);
      os << " : ";
      tchecker::fsm::details::tchecker_output_edge_statement(os, s, edge);
      os << "}";
      os << std::endl;
    }
    
    
    void tchecker_output(std::ostream & os, tchecker::fsm::system_t const & system)
    {
      tchecker::tchecker_output_system_name(os, system);
      tchecker::tchecker_output_system_events(os, system);
      tchecker::tchecker_output_system_processes(os, system);
      tchecker::tchecker_output_system_synchronizations(os, system);
      tchecker::fsm::details::tchecker_output_system_intvars(os, system);
      tchecker::tchecker_output_system_locations
      (os, system, tchecker::fsm::tchecker_output_location);
      tchecker::tchecker_output_system_edges
      (os, system, tchecker::fsm::tchecker_output_edge);
    }
    
  } // end of namespace fsm
  
} // end of namespace tchecker
