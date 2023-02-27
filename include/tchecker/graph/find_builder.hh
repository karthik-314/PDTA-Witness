/*
 * This file is a part of the TChecker project.
 *
 * See files AUTHORS and LICENSE for copyright details.
 *
 */

#ifndef TCHECKER_GRAPH_FIND_BUILDER_HH
#define TCHECKER_GRAPH_FIND_BUILDER_HH

#include <tuple>
#include <utility>
#include <unordered_map>
#include <vector>
#include <stack>

#include "tchecker/basictypes.hh"
#include "tchecker/graph/builder.hh"

/*!
 \file find_builder.hh
 \brief Find graph builder
 */

namespace tchecker {
  
  namespace graph {
    
    /*!
     \class ts_find_builder_t
     \brief Build a find graph from a transition system
     \tparam TS : type of transition system (see tchecker::ts::ts_t)
     \tparam FIND_GRAPH : type of find graph, should derive from tchecker::graph::find_graph_t, and
     should be a graph allocator (see tchecker::graph::graph_allocator_t)
     */
    template <class TS, class FIND_GRAPH>
    class ts_find_builder_t : protected tchecker::graph::ts_builder_t<TS, FIND_GRAPH> {
    public:
      /*!
       \brief Type of pointer to node
       */
      using node_ptr_t = typename tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::node_ptr_t;
      
      /*!
       \brief Type of pointer to edge
       */
      using edge_ptr_t = typename tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::edge_ptr_t;
      
      /*!
       \brief Constructor
       \param ts : a transition system
       \param find_graph : a find graph with allocation
       \note see tchecker::graph::ts_builder_t::ts_builder_t
       */
      ts_find_builder_t(TS & ts, FIND_GRAPH & find_graph)
      : tchecker::graph::ts_builder_t<TS, FIND_GRAPH>(ts, find_graph)
      {}
      
      /*!
       \brief Copy constructor
       */
      ts_find_builder_t(tchecker::graph::ts_find_builder_t<TS, FIND_GRAPH> const &) = default;
      
      /*!
       \brief Move constructor
       */
      ts_find_builder_t(tchecker::graph::ts_find_builder_t<TS, FIND_GRAPH> &&) = default;
      
      /*!
       \brief Destructor
       */
      ~ts_find_builder_t() = default;
      
      /*!
       \brief Assignment operator
       */
      tchecker::graph::ts_find_builder_t<TS, FIND_GRAPH> &
      operator= (tchecker::graph::ts_find_builder_t<TS, FIND_GRAPH> const &) = default;
      
      /*!
       \brief Move assignment operator
       */
      tchecker::graph::ts_find_builder_t<TS, FIND_GRAPH> &
      operator= (tchecker::graph::ts_find_builder_t<TS, FIND_GRAPH> &&) = default;
      
      /*!
       \brief Compute initial node
       \param v : initial iterator value from the transition system
       \param nargs : parameters to FIND_GRAPH::allocate_node()
       \param eargs : parameters to FIND_GRAPH::allocate_edge()
       \return a quadruple <node, edge, status, is_new_node> where
       status is the tchecker::state_status_t status of node,
       node and edge are the initial nodes and edges computed from v,
       and is_new_node tells if node is a new node of an existing node.
       node points to nullptr if status != tchecker::STATE_OK
       */
      template <class ... NARGS, class ... EARGS>
      std::tuple<node_ptr_t, edge_ptr_t, tchecker::state_status_t, bool>
      initial_node(typename TS::initial_iterator_value_t const & v, std::tuple<NARGS...> && nargs, std::tuple<EARGS...> && eargs)
      {
        node_ptr_t node;
        edge_ptr_t edge;
        tchecker::state_status_t status;
        
        std::tie(node, edge, status)
        = tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::initial_node(v,
                                                                      std::forward<std::tuple<NARGS...>>(nargs),
                                                                      std::forward<std::tuple<EARGS...>>(eargs));
        
        if (status != tchecker::STATE_OK)
          return std::make_tuple(node, edge, status, false);
        
        node_ptr_t actual_node = this->_graph.find(node);
        bool is_new_node = (actual_node == node);
        return std::make_tuple(actual_node, edge, status, is_new_node);
      }
      
      /*!
       \brief Just Compute next node
       \param node : source node
       \param v : outgoing edges iterator value from the transition system
       \param nargs : parameters to FIND_GRAPH::allocate_node()
       \param eargs : parameters to FIND_GRAPH::allocate_edge()
       \return a quadruple <next_node, edge, status, is_new_node> where status
       describes whether next_node is empty or not,
       next_node and edges are the next node and outgoing edge of node
       corresponding to v, and is_new_node does not serve any purpose currently, but was
       added since it was previously part of tchecker.
       status != tchecker::STATE_OK
       */
      template <class ... NARGS, class ... EARGS>
      std::tuple<node_ptr_t, edge_ptr_t, tchecker::state_status_t, bool>
      next_node(node_ptr_t & node,
                typename TS::outgoing_edges_iterator_value_t const & v,
                std::tuple<NARGS...> && nargs,
                std::tuple<EARGS...> && eargs)
      {
        node_ptr_t next_node;
        edge_ptr_t edge;
        tchecker::state_status_t status;
        
        std::tie(next_node, edge, status)
        = tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::next_node(node,
                                                                   v,
                                                                   std::forward<std::tuple<NARGS...>>(nargs),
                                                                   std::forward<std::tuple<EARGS...>>(eargs));
<<<<<<< HEAD
        return std::make_tuple(next_node, edge, status, 1);
=======
        return std::make_tuple(next_node, edge, status, 1);//Remove this line
>>>>>>> 78b1f60 (First commit.)
      }


      /*!
        \brief Return stack operation details of edge.
        \param v: outgoing edges iterator value from transition system.
        \return a triplet in the form of pair of pair. The first bool, i.e. first of outer pair,
        describes whether the stack operation is NOP or (Push/Pop). The bool inside inner pair,
        describes whether the stack operation if (Push/Pop) is either Push or Pop, and the string
        which is in the inner pair is the string to be either pushed or popped in case operation is
        (Push/Pop).
        Go To graph/builder.hh for more details.
      */
      std::pair<bool, std::pair<bool, std::string>> edge_name(typename TS::outgoing_edges_iterator_value_t const & v){
      	return tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::edge_name(v);
      }

<<<<<<< HEAD

      /*!
        \brief Return name of state of the node.
        \param node: Reference to the node (say, (q,Z)) in question.
        \return Return state q as a string.
      */
=======
      int get_event_id(typename TS::outgoing_edges_iterator_value_t const & v){
        return tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::get_event_id(v);
      }

>>>>>>> 78b1f60 (First commit.)
      std::string node_name(node_ptr_t & node){
        return tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::node_name(node);
      }

<<<<<<< HEAD
      /**
        \brief Determine if two nodes subsume each other.
        \param n1: Node say, (q,Z)
        \param n2: Node say, (q',Z')
        \return If Z~Z' (regardless of q,q', as global bounds used currently)
        then return 1, else return 0.
      */
=======
      std::pair<node_ptr_t, node_ptr_t> get_node(std::string rname, int rnode, std::string name, int node){
        std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>> &flm = this->_graph.TLM[rname];
        std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t> &t = flm[rnode];
        node_ptr_t f = std::get<3>(t);
        std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>> &slm = std::get<0>(t);
        std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t> x = slm[name][node];
        node_ptr_t s = std::get<5>(x);
        return std::make_pair(f, s);
      }

>>>>>>> 78b1f60 (First commit.)
      bool equal(const node_ptr_t &n1, const node_ptr_t &n2){
      	return !tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::equal(n1, n2, 0);
      }

      /**
        \brief Determine if two nodes are exactly equal.
        \param n1: Node say, (q,Z)
        \para n2: Node say, (q',Z')
        \return If Z=Z' (every cell in DBMs), return 1, else return 0.
      */
      bool exact_equal(const node_ptr_t &n1, const node_ptr_t &n2){
        return tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::exact_equal(n1, n2);
      }

<<<<<<< HEAD

      /**
        \brief Simply add node to TLM second level map and ToDo list.
        \param state1: q1 in (q1,Z1)
        \param n1: (q1,Z1)
        \param state2: q2 in (q2,Z2)
        \param n2: (q2,Z2)
        \param to_do: ToDo list
        \return Add [(q1,Z1),(q2,Z2)] to ToDo list and add (q2,Z2) to second level map of
        (q1,Z1) unconditionally (i.e. Don't check if the node (root or internal) exists,
        just add).
      */
      void just_add_node(const std::string &state1, const node_ptr_t &n1, const std::string &state2, const node_ptr_t &n2, std::stack<std::pair<node_ptr_t, node_ptr_t>> &to_do){
        bool x = this->_graph.FULL_TLM.find(state1) == this->_graph.FULL_TLM.end();
        if(x){
          this->_graph.FULL_TLM[state1] = std::vector<std::tuple<std::unordered_map<std::string, std::vector<node_ptr_t>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<node_ptr_t>>>, node_ptr_t>>();
=======
      void add_initial_node(const std::string &state1, const node_ptr_t &n1, std::stack<std::tuple<std::string, int, std::string, int>> &to_do, typename TS::outgoing_edges_iterator_value_t edge){
        //Witness Generation Start
        this->_graph.TLM[state1] = std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>>();
        std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>> &flm = this->_graph.TLM[state1];
        std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>> slmtemp;
        slmtemp[state1] = std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>();
        slmtemp[state1].push_back(std::make_tuple("", 0, "", 0, edge, n1));
        std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>> pstemp;
        std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>> pptemp;
        flm.push_back(std::make_tuple(slmtemp, pstemp, pptemp, n1));
        to_do.push(std::make_tuple(state1, 0, state1, 0));
        //Witness Generation End
      }

      void just_add_node(const std::string &src_root_name, int src_root_node, const std::string &src_name, int src_node, const std::string &state1, const node_ptr_t &n1, const std::string &state2, const node_ptr_t &n2, std::stack<std::tuple<std::string, int, std::string, int>> &to_do, typename TS::outgoing_edges_iterator_value_t edge){
        //Witness Generation Start
        bool y = this->_graph.TLM.find(state1) == this->_graph.TLM.end();
        if(y){
          this->_graph.TLM[state1] = std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>>();
>>>>>>> 78b1f60 (First commit.)
        }
        std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>> &flm = this->_graph.TLM[state1];
        y = 0;
        int first = 0;
        for(auto & [slm, pushes, pops, nt] : flm){
          if(tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::exact_equal(nt, n1)){
            if(slm.find(state2) == slm.end()){
              slm[state2] = std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>();
            }
            slm[state2].push_back(std::make_tuple(src_root_name, src_root_node, src_name, src_node, edge, n2));
            to_do.push(std::make_tuple(state1, first, state2, slm[state2].size() - 1));
            y = 1;
            break;
          }
          first++;
        }
<<<<<<< HEAD
        if(x == 0){
          std::unordered_map<std::string, std::vector<node_ptr_t>> mptemp;
          mptemp[state2] = std::vector<node_ptr_t>(1, n2);
          std::unordered_map<std::string, std::unordered_map<std::string, std::vector<node_ptr_t>>> push_temp, pop_temp;
          flm_tgt.push_back(make_tuple(mptemp, push_temp, pop_temp, n1));
          to_do.push(std::make_pair(n1, n2));
=======
        if(y == 0){
          std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>> slmtemp;
          slmtemp[state2] = std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>();
          slmtemp[state2].push_back(std::make_tuple(src_root_name, src_root_node, src_name, src_node, edge, n2));
          std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>> pstemp;
          std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>> pptemp;
          flm.push_back(make_tuple(slmtemp, pstemp, pptemp, n1));
          to_do.push(std::make_tuple(state1, flm.size() - 1, state2, 0));
>>>>>>> 78b1f60 (First commit.)
        }
        //Witness Generation End
      }

<<<<<<< HEAD
      /**
        \brief Add node to Pushes Map, and then match pop.
        \param state1: q1 in (q1,Z1)
        \param n1: (q1,Z1)
        \param state2: q2 in (q2, Z2)
        \param n2: (q2,Z2)
        \param symbol: a in q1 ->(push a) q2
        \param to_do: ToDo list
        \return Given (q1,Z1) ->(push a) (q2,Z2') with Z2'~Z2, add (q2,Z2) to pushes list of
        (q1,Z1), then add all nodes in pops map of (q2,Z2) to second level
        map of (q1,Z1) (match pop).
      */
      void append_push_and_match_pop(const std::string &state1, const node_ptr_t &n1, const std::string &state2, const node_ptr_t &n2, const std::string &symbol, std::stack<std::pair<node_ptr_t, node_ptr_t>> &to_do, bool eqOrSim){
        bool x = this->_graph.FULL_TLM.find(state2) == this->_graph.FULL_TLM.end();
        if(x){
          this->_graph.FULL_TLM[state2] = std::vector<std::tuple<std::unordered_map<std::string, std::vector<node_ptr_t>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<node_ptr_t>>>, node_ptr_t>>();
=======
      //n1 -> n1'~n2
      //[(src_root_name, src_root_node/n1),(src_name, src_node/-)] -> [(state2, n2),(state2, n2)]
      void append_push_and_match_pop(const std::tuple<std::string, int, std::string, int> &top, int newRootPlace, const node_ptr_t &n1, const std::string &state2, const node_ptr_t &n2, const std::string &symbol, std::stack<std::tuple<std::string, int, std::string, int>> &to_do, typename TS::outgoing_edges_iterator_value_t const &edge){
        //Witness Generation Start
        std::string src_root_name = std::get<0>(top), src_name = std::get<2>(top);
        int src_root_node = std::get<1>(top), src_node = std::get<3>(top);
        bool y = this->_graph.TLM.find(state2) == this->_graph.TLM.end();
        if(y){
          this->_graph.TLM[state2] = std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>>();
>>>>>>> 78b1f60 (First commit.)
        }
        std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>> &flm = this->_graph.TLM[state2];
        y = 0;
        for(auto & [slm, pushes, pops, nt] : flm){
          // if(pops.find(symbol) == pops.end()){
          //   std::cout << state2 << " POPS EMPTY\n";
          // } else {
          //   std::cout << state2 << " POPS NOT EMPTY\n";
          // }
          if(tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::exact_equal(nt, n2) && state2 == node_name(nt)){
            // std::cout << "EXACT EQUAL\n";
            if(pushes.find(symbol) != pushes.end() && pushes[symbol].find(src_root_name) != pushes[symbol].end()){
              for(auto it = pushes[symbol][src_root_name].begin() ; it != pushes[symbol][src_root_name].end() ; it++){
                std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t> i = *it;
                if(tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::exact_equal(std::get<3>(i), n1)){
                  y = 1;
                  break;
                }
              }
            }
<<<<<<< HEAD
            if(x == 0){
                if(pushes.find(symbol) == pushes.end()) pushes[symbol] = std::unordered_map<std::string, std::vector<node_ptr_t>>();
                if(pushes[symbol].find(state1) == pushes[symbol].end()) pushes[symbol][state1] = std::vector<node_ptr_t>(1, n1);
                else  pushes[symbol][state1].push_back(n1);
                if(pops.find(symbol) != pops.end()){
                  for(auto it = pops[symbol].begin() ; it != pops[symbol].end() ; it++){
                    std::string q2 = it->first;
                    std::vector<node_ptr_t> vec_z2 = it->second;
                    for(auto z2 = vec_z2.begin() ; z2 != vec_z2.end() ; z2++){
                      if(isNewNode(state1, n1, q2, *z2, eqOrSim)){
                        just_add_node(state1, n1, q2, *z2, to_do);
                      }
=======
            if(y == 0){
              // std::cout << state2 << "\n";
              if(pushes.find(symbol) == pushes.end()) pushes[symbol] = std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>();
              if(pushes[symbol].find(src_root_name) == pushes[symbol].end()) pushes[symbol][src_root_name] = std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>();
              pushes[symbol][src_root_name].push_back(std::make_tuple(src_name, src_node, edge, n1));
              // std::cout << state2 << " " << symbol << "\n";
              if(pops.find(symbol) != pops.end()){
                // std::cout << state2 << " " << src_root_name << "\n";
                for(auto it = pops[symbol].begin() ; it != pops[symbol].end() ; it++){
                  std::string q2 = it->first;
                  std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>> vec_z2 = it->second;
                  for(auto z2 = vec_z2.begin() ; z2 != vec_z2.end() ; z2++){
                    std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t> tup = *z2;
                    node_ptr_t zone2 = std::get<3>(tup);
                    if(isNewNode(src_root_name, n1, q2, zone2)){
                      just_add_node(state2, newRootPlace, std::get<0>(tup), std::get<1>(tup), src_root_name, n1, q2, zone2, to_do, std::get<2>(tup));
>>>>>>> 78b1f60 (First commit.)
                    }
                  }
                }
              }
            }
            break;
          }
        }
        //Witness Generation End
      }
<<<<<<< HEAD

      /**
        \brief Add node to Pops map, and match pushes.
        \param state1: q1 in (q1,Z1)
        \param n1: (q1,Z1)
        \param state2: q2 in (q2,Z2)
        \param n2: (q2,Z2)
        \param symbol: a in q1' ->(pop a) q2
        \param to_do: ToDo list
        \return Given (q1',Z1') in second level map of (q1,Z1), if we have
        (q1',Z1')->(pop a)(q2,Z2), then add (q2,Z2) to pops map of (q1,Z1),
        and add (q2,Z2) to second level map of all nodes in pushes map of (q1,Z1) (match push).
      */
      void append_pop_and_match_push(const std::string &state1, const node_ptr_t &n1, const std::string &state2, const node_ptr_t &n2, const std::string &symbol, std::stack<std::pair<node_ptr_t, node_ptr_t>> &to_do, bool eqOrSim){
        std::vector<std::tuple<std::unordered_map<std::string, std::vector<node_ptr_t>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<node_ptr_t>>>, node_ptr_t>> &temp = this->_graph.FULL_TLM[state1];
        for(auto & [slm, pushes, pops, nt] : temp){
          if(tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::exact_equal(nt, n1) && state1 == node_name(nt)){
            bool x = 0;
            if(pops.find(symbol) == pops.end()) pops[symbol] = std::unordered_map<std::string, std::vector<node_ptr_t>>();
            if(pops[symbol].find(state2) == pops[symbol].end()){
              pops[symbol][state2] = std::vector<node_ptr_t>();
=======
      //1. Subsumption -> Simulation
      //n1 -> n2
      void append_pop_and_match_push(const std::tuple<std::string, int, std::string, int> &top, const node_ptr_t &n1, const std::string &state2, const node_ptr_t &n2, const std::string &symbol, std::stack<std::tuple<std::string, int, std::string, int>> &to_do, typename TS::outgoing_edges_iterator_value_t const &edge){
        //Witness Generation Start
        std::string src_root_name = std::get<0>(top), src_name = std::get<2>(top);
        int src_root_node = std::get<1>(top), src_node = std::get<3>(top);
        std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>> &flm = this->_graph.TLM[src_root_name];
        for(auto & [slm, pushes, pops, nt] : flm){
          if(tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::exact_equal(nt, n1) && src_root_name == node_name(nt)){
            bool y = 0;
            if(pops.find(symbol) == pops.end()){
              pops[symbol] = std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>();
            }
            if(pops[symbol].find(state2) == pops[symbol].end()){
              pops[symbol][state2] = std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>();
>>>>>>> 78b1f60 (First commit.)
            } else {
              for(auto it = pops[symbol][state2].begin() ; it != pops[symbol][state2].end() ; it++){
                std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t> tup = *it;
                if(!tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::equal(std::get<3>(tup), n2, 0)){
                  y = 1;
                  break;
                }
              }
            }
            if(y == 0){
              // std::cout << src_root_name << " " << symbol << " HERE\n";
              pops[symbol][state2].push_back(std::make_tuple(src_name, src_node, edge, n2));
              if(pushes.find(symbol) != pushes.end()){
                // std::cout << "PUSHES NOT EMPTY \n";
                for(auto it = pushes[symbol].begin() ; it != pushes[symbol].end() ; it++){
                  std::string q3 = it->first;
                  std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>> vec_z3 = it->second;
                  // std::cout << src_root_name << " " << symbol << " " << q3 << " " << vec_z3.size() << " PUSHES ON SYMBOL NOT EMPTY\n";
                  for(auto z3 = vec_z3.begin() ; z3 != vec_z3.end() ; z3++){
<<<<<<< HEAD
                    if(isNewNode(q3, *z3, state2, n2, eqOrSim)){
                      just_add_node(q3, *z3, state2, n2, to_do);
=======
                    std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t> zone3 = *z3;
                    if(isNewNode(q3, std::get<3>(zone3), state2, n2)){
                      just_add_node(src_root_name, src_root_node, src_name, src_node, q3, std::get<3>(zone3), state2, n2, to_do, edge);
>>>>>>> 78b1f60 (First commit.)
                    }
                  }
                }
              }
            }
            break;
          }
        }
        //Witness Generation End
      }

<<<<<<< HEAD
      /**
        \brief Is a node new in a subtree, or does a node that subsumes it present.
        \param state1: q1 in (q1,Z1)
        \param n1: (q1,Z1)
        \param state2: q2 in (q2,Z2)
        \param n2: (q2,Z2)
        \return False if a node (q2,Z2') is in second level map of (q1,Z1), such that,
        Z2' simulates Z2. True otherwise.
      */
      bool isNewNode(const std::string &state1, const node_ptr_t &n1, const std::string &state2, const node_ptr_t &n2, bool eqOrSim){
        if(this->_graph.FULL_TLM.find(state1) == this->_graph.FULL_TLM.end()){
=======
      bool isNewNode(const std::string &state1, const node_ptr_t &n1, const std::string &state2, const node_ptr_t &n2){
        if(this->_graph.TLM.find(state1) == this->_graph.TLM.end()){
>>>>>>> 78b1f60 (First commit.)
          return 1;
        }
        std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>> &flm = this->_graph.TLM[state1];
        for(auto & [slm, pushes, pops, nt] : flm){
          if(tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::exact_equal(nt, n1)){
            if(slm.find(state2) == slm.end()) return 1;
            for(auto i = slm[state2].begin() ; i != slm[state2].end() ; i++){
<<<<<<< HEAD
              if(!tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::equal(*i, n2, eqOrSim)){
=======
              std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t> tup = *i;
              if(!tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::equal(std::get<5>(tup), n2, 1)){
>>>>>>> 78b1f60 (First commit.)
                return 0;
              }
            }
          }
        }
        return 1;
      }

<<<<<<< HEAD
      /**
        \brief Is a node new in the first level map or not.
        \param state: q in (q,Z)
        \param node: (q,Z)
        \return If there is a node (q,Z') in first level map, such that Z'~Z, then return
        pair [false, (q,Z)], else return [true, (q,Z')].
      */
      std::pair<bool, node_ptr_t> isNewRoot(const std::string &state, const node_ptr_t &node){
        if(this->_graph.FULL_TLM.find(state) == this->_graph.FULL_TLM.end()){
          return std::make_pair(true, node);
=======
      std::tuple<bool, int, node_ptr_t> isNewRoot(const std::string &state, const node_ptr_t &node){
        int first = 0;
        if(this->_graph.TLM.find(state) == this->_graph.TLM.end()){
          return std::make_tuple(true, first, node);
>>>>>>> 78b1f60 (First commit.)
        }
        std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>> &flm = this->_graph.TLM[state];
        for(auto & [slm, pushes, pops, nt] : flm){
          if(!tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::equal(nt, node, 0))  return std::make_tuple(false, first, nt);
          first++;
        }
        return std::make_tuple(true, first, node);
      }
<<<<<<< HEAD
=======

      void get_witness(std::tuple<std::string, int, std::string, int> const &curr, std::stack<std::tuple<std::string, int, std::string, int>> &zone_witness, std::stack<typename TS::outgoing_edges_iterator_value_t> &transitions){
        std::string root_name = std::get<0>(curr), curr_name = std::get<2>(curr);
        int root_idx = std::get<1>(curr), curr_idx = std::get<3>(curr);
        // std::cout << root_name << " " << root_idx << " " << curr_name << " " << curr_idx << "\n";
        if(root_name == curr_name && curr_idx == 0) return;
        std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>> &flm = this->_graph.TLM[root_name];
        std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t> lists = flm[root_idx];
        std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>> &slm = std::get<0>(lists);
        std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t> current = slm[curr_name][curr_idx];
        std::string prev_root = std::get<0>(current), prev_int = std::get<2>(current);
        int prev_root_idx = std::get<1>(current), prev_int_idx = std::get<3>(current);
        typename TS::outgoing_edges_iterator_value_t transition = std::get<4>(current);
        transitions.push(transition);
        std::pair<bool, std::pair<bool, std::string>> tr_details = edge_name(transition);
        std::tuple<std::string, int, std::string, int> prev = std::make_tuple(prev_root, prev_root_idx, prev_int, prev_int_idx);
        zone_witness.push(prev);
        if(!tr_details.first){
          //Internal Rule
          get_witness(prev, zone_witness, transitions);
        } else {
          //Pop Rule
          get_witness(prev, zone_witness, transitions);
          std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>> &flm_prev = this->_graph.TLM[prev_root];
          std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>> &pushes = std::get<1>(flm_prev[prev_root_idx]);
          std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>> &vec_ps = pushes[tr_details.second.second][root_name];
          node_ptr_t root_node = std::get<3>(lists);
          for(auto & [same_curr, same_idx, transitionp, root] : vec_ps){
            if(tchecker::graph::ts_builder_t<TS, FIND_GRAPH>::exact_equal(root_node, root)){
              std::tuple<std::string, int, std::string, int> temp = std::make_tuple(root_name, root_idx, same_curr, same_idx);
              zone_witness.push(temp);
              transitions.push(transitionp);
              get_witness(temp, zone_witness, transitions);
              break;
            }
          }
        }
      }

      void get_general_witness(bool root_call, std::tuple<std::string, int, std::string, int> const &curr, std::stack<std::tuple<std::string, int, std::string, int>> &zone_witness, std::stack<typename TS::outgoing_edges_iterator_value_t> &transitions){
	std::string root_name = std::get<0>(curr), curr_name = std::get<2>(curr);
        int root_idx = std::get<1>(curr), curr_idx = std::get<3>(curr);

	if(root_name == curr_name && curr_idx == 0){
	  if(root_call == true){
	    zone_witness.push(curr);
	  } else {
	    std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>> &flm = this->_graph.TLM[root_name];
	    std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t> lists = flm[root_idx];
	    std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>> &slm = std::get<0>(lists);
	    std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t> current = slm[curr_name][curr_idx];
	    std::string prev_root = std::get<0>(current), prev_int = std::get<2>(current);
	    int prev_root_idx = std::get<1>(current), prev_int_idx = std::get<3>(current);
	    typename TS::outgoing_edges_iterator_value_t transition = std::get<4>(current);
	    general_witness(false, std::make_tuple(prev_root, prev_root_idx, prev_int, prev_int_idx), zone_witness, transitions);
	    transitions.push(transition);
	  }
	} else {
	  std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t>> &flm = this->_graph.TLM[root_name];
	  std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>>>, node_ptr_t> lists = flm[root_idx];
	  std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t>>> &slm = std::get<0>(lists);
	  std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, node_ptr_t> current = slm[curr_name][curr_idx];
	  std::string prev_root = std::get<0>(current), prev_int = std::get<2>(current);
	  int prev_root_idx = std::get<1>(current), prev_int_idx = std::get<3>(current);
	  typename TS::outgoing_edges_iterator_value_t transition = std::get<4>(current);
	  std::pair<bool, std::pair<bool, std::string>> tr_details = edge_name(transition);
	  if(!tr_details.first){
	    // Internal operation
	    general_witness()
	  }
	  
	}

      }


>>>>>>> 78b1f60 (First commit.)
    };
    
  } // end of namespace graph
  
} // end of namespace tchecker

#endif // TCHECKER_GRAPH_FIND_BUILDER_HH
