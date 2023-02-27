/*
 * This file is a part of the TChecker project.
 *
 * See files AUTHORS and LICENSE for copyright details.
 *
 */

#ifndef TCHECKER_FIND_GRAPH_HH
#define TCHECKER_FIND_GRAPH_HH

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <tuple>

#include "tchecker/basictypes.hh"
#include "tchecker/graph/builder.hh"

/*!
 \file find_graph.hh
 \brief Graph with node finding
 */

namespace tchecker {
  
  namespace graph {

    template <class NODE_PTR, class TS>
    class FullNode{
    public:
      NODE_PTR node;
      std::string parent_name; int parent_idx;
      std::string root_name; int root_idx;
      typename TS::outgoing_edges_iterator_value_t transition;

      FullNode(NODE_PTR n, std::string pname, int pidx, std::string prname, int pridx, typename TS::outgoing_edges_iterator_value_t t){
        node = n;
        parent_name = pname;
        parent_idx = pidx;
        root_idx = pridx;
        root_name = prname;
        transition = t;
      }
      FullNode(NODE_PTR n){
        node = n;
      }
    };
    
    /*!
     \class find_graph_t
     \brief Graph with node finding
     \tparam NODE_PTR : type of pointer to node
     \tparam HASH : hash function on NODE_PTR (see std::hash)
     \tparam EQUAL : equality function on NODE_PTR (see std::equal_to)
     \note this graph implementation stores nodes and answers find queries.
     It does not store edges
     \note each node has a unique instance in this graph w.r.t. EQUAL
     */
    template <class NODE_PTR, class HASH, class EQUAL, class TS>
    class find_graph_t {
    public:
      /*!
       \brief Type of pointers of node
       */
      using node_ptr_t = NODE_PTR;
      
      /*!
       \brief Type of hash function
       */
      using hash_t = HASH;
      
      /*!
       \brief Type of equality predicate
       */
      using equal_t = EQUAL;

      using full_node_t = FullNode<NODE_PTR, TS>;
      
      /*!
       \brief Clear
       \post The graph is empty
       \note No destructor call on nodes
       */
      inline void clear()
      {
        _nodes.clear();
        all_nodes.clear();
      }
      
      /*!
       \brief Accessor
       \param n : a node
       \return the node in the graph equivalent to n w.r.t. HASH and EQUAL if any,
       n otherwise
       */
      NODE_PTR const & find(NODE_PTR const & n)
      {
        auto it = _nodes.find(n);
        if (it != _nodes.end())
          return *it;
        return n;
      }
      
      /*!
       \brief Add node
       \param n : a node
       \post n has been added to the graph unless it already contains an equivalent
       node w.r.t. HASH and EQUAL
       \return true if n has been added to the graph, false otherwise
       */
      bool add_node(NODE_PTR const & n)
      {
        try {
          _nodes.insert(n);
          all_nodes.push_back(n);
          return true;
        }
        catch (...)
        {}
        return false;
      }
<<<<<<< HEAD
=======

      bool add_node(NODE_PTR const & n, std::string &state){
        // try{
        //   if(TLM.find(state) == TLM.end()){
        //     // _full_graph[state] = std::vector<NODE_PTR>();
        //     TLM[state] = std::vector<std::pair<std::unordered_map<std::string, std::vector<NODE_PTR>>, NODE_PTR>>();
        //     // _full_graph[state] = std::vector<std::pair<std::unordered_map<std::string, std::vector<NODE_PTR>>::iterator, NODE_PTR>>();
        //     // std::vector<std::pair<std::unordered_map<std::string, std::vector<NODE_PTR>>::iterator, NODE_PTR>> vect;
        //   }
        //   std::unordered_map<std::string, std::vector<NODE_PTR>> temp;
        //   temp[state] = std::vector<NODE_PTR>();
        //   temp[state].push_back(n);


        //   TLM[state].push_back(make_pair(temp, n));
        //   // _nodes.insert(n);
        //   // all_nodes.push_back(n);
        //   // _full_graph[state].push_back(n);
        //   // std::cout << "MAP SIZE START\n";
        //   // for(auto it = _full_graph.begin() ; it != _full_graph.end() ; it++){
        //   //   std::cout << it->first << " " << (it->second).size() << "\n";
        //   // }
        //   // std::cout << "MAP SIZE END\n";
        //   return true;
        // } catch(...){
        //   return false;
        // }
      }
>>>>>>> 78b1f60 (First commit.)
      
      /*!
       \brief Type of iterator on nodes
       */
      using const_iterator_t = typename std::unordered_set<NODE_PTR, HASH, EQUAL>::const_iterator;
      
      /*!
       \brief Accessor
       \return iterator on first node if any, past-the-end iterator otherwise
       */
      inline tchecker::graph::find_graph_t<NODE_PTR, HASH, EQUAL, TS>::const_iterator_t begin() const
      {
        return _nodes.begin();
      }
      
      /*!
       \brief Accessor
       \return past-the-end iterator
       */
      inline tchecker::graph::find_graph_t<NODE_PTR, HASH, EQUAL, TS>::const_iterator_t end() const
      {
        return _nodes.end();
      }
      std::unordered_set<NODE_PTR, HASH, EQUAL> _nodes;
      std::vector<NODE_PTR> all_nodes;

<<<<<<< HEAD

      /*!
        \brief FULL_TLM as described in the paper. Contains Second Level Map as first pointer, Pushes As second Pointer, Pops as third pointer, and fourth a node pointer.
      */
      std::unordered_map<std::string, std::vector<std::tuple<std::unordered_map<std::string, std::vector<NODE_PTR>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<NODE_PTR>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<NODE_PTR>>>, NODE_PTR>>> FULL_TLM;
=======
      std::unordered_map<std::string, std::vector<std::tuple<std::unordered_map<std::string, std::vector<NODE_PTR>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<NODE_PTR>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<NODE_PTR>>>, NODE_PTR>>> FULL_TLM;
      // std::unordered_map<std::string, std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<int, std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t>>>, int>>> witness_slm;
      // std::unordered_map<std::string, std::vector<std::pair<std::unordered_map<std::string, std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t>>, int>>> witness_pushes;
      // std::unordered_map<std::string, std::vector<std::pair<std::unordered_map<std::string, std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t>>, int>>> witness_pops;
      
      std::unordered_map<std::string, std::vector<std::tuple<std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string, int, typename TS::outgoing_edges_iterator_value_t, NODE_PTR>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, NODE_PTR>>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::tuple<std::string, int, typename TS::outgoing_edges_iterator_value_t, NODE_PTR>>>>, NODE_PTR>>> TLM;
      // std::unordered_map<std::string, std::vector<std::tuple<std::unordered_map<std::string, std::vector<full_node_t>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<full_node_t>>>, std::unordered_map<std::string, std::unordered_map<std::string, std::vector<full_node_t>>>, full_node_t>>> TLM;
    // protected:
>>>>>>> 78b1f60 (First commit.)
    };
    
  } // end of namespace graph
  
} // end of namespace tchecker

#endif // TCHECKER_FIND_GRAPH_HH

