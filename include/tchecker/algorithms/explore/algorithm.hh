/*
 * This file is a part of the TChecker project.
 *
 * See files AUTHORS and LICENSE for copyright details.
 *
 */

#ifndef TCHECKER_ALGORITHMS_EXPLORE_ALGORITHM_HH
#define TCHECKER_ALGORITHMS_EXPLORE_ALGORITHM_HH

#include <tuple>
#include <typeinfo>
#include <stack>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <assert.h>
#include <cmath>
#include <glpk.h>

#include "tchecker/basictypes.hh"
#include "tchecker/algorithms/explore/builder.hh"

/*!
 \file algorithm.hh
 \brief Explore algorithm
 */

namespace tchecker {
  
  namespace explore {
    /*!
     \class algorithm_t
     \brief Explore algorithm
     \tparam TS : type of transition system, should derive from tchecker::ts::ts_t
     \tparam GRAPH : type of graph, should derive from tchecker::explore::graph_t
     \tparam WAITING : type of waiting container, should derive from tchecker::utils::waiting_t
     */
    template <class TS, class GRAPH, template <class NPTR> class WAITING>
    class algorithm_t {
    public:
      /*!
       \brief Create a Full TLM (Zone Graph) given a Transition System
       \param ts : a transition system
       \param graph : a graph
       \post TLM is built from a traversal of ts. Currently the entire zone graph/TLM
       is constructed, but we could stop in between by providing breaking when seeing a final
       state.
       */
      void run(TS & ts, GRAPH & graph, bool eqOrSim)
      {
      void run(TS & ts, GRAPH & graph, std::unordered_map<std::string, int> &clocks){
        using namespace std::chrono;
        auto start = high_resolution_clock::now(); 
        using node_ptr_t = typename GRAPH::node_ptr_t;
        using edge_ptr_t = typename GRAPH::edge_ptr_t;

        tchecker::explore::builder_t<TS, GRAPH> builder(ts, graph);
        WAITING<node_ptr_t> waiting;

        std::stack<std::tuple<std::string, int, std::string, int>> to_do;
        
        node_ptr_t initial_node, next_node;
        edge_ptr_t edge;
        tchecker::state_status_t status;
        bool is_new_node;
        int count = 0;

        auto initial_range = ts.initial();
        for (auto it = initial_range.begin(); ! it.at_end(); ++it) {
          std::tie(initial_node, status, is_new_node) = builder.initial_node(*it);
          std::string name = builder.node_name(initial_node);
          if (is_new_node) {
            builder.just_add_node(name, initial_node, name, initial_node, to_do);
            // to_do.push(std::make_pair(initial_node, initial_node));
          	auto vedges_range = ts.outgoing_edges(*initial_node);
          	auto x = vedges_range.begin();
          	typename TS::outgoing_edges_iterator_value_t f = *x;
            builder.add_initial_node(name, initial_node, to_do, f);
          }
        }

        std::string init_state = builder.node_name(initial_node);

        //Last Version Start ###################################################################################
        std::vector<std::string> reachable;
        std::unordered_set<std::string> all_reachable;
        std::unordered_set<std::string> reachable;
        std::unordered_set<std::string> F({"q4"});
        bool non_empty = 0;
        std::tuple<std::string, int, std::string, int> fin_top;

        while(!to_do.empty()){
          std::tuple<std::string, int, std::string, int> top = to_do.top();
          to_do.pop();
          count++;
          std::pair<node_ptr_t, node_ptr_t> to = builder.get_node(std::get<0>(top), std::get<1>(top), std::get<2>(top), std::get<3>(top));
          node_ptr_t root = to.first, tgt_node;
          node_ptr_t sub = to.second;
          std::string state1 = builder.node_name(root);
          std::string fin_state = builder.node_name(sub);
          if(state1 == init_state && builder.equal(root, initial_node)){
            if(all_reachable.find(fin_state) == all_reachable.end()){
            	reachable.push_back(fin_state);
            	all_reachable.insert(fin_state);
            }
          if(F.find(fin_state) != F.end() && state1 == init_state && builder.equal(root, initial_node)){
          	std::cout << "NON EMPTY LANGUAGE\n";
          	non_empty = 1;
          	fin_top = top;
          	break;
          }
          auto vedges_range = ts.outgoing_edges(*sub);
          for(auto it = vedges_range.begin() ; !it.at_end() ; ++it){
            std::pair<bool, std::pair<bool, std::string>> ed_details = builder.edge_name(*it);
            std::tie(tgt_node, edge, status, is_new_node) = builder.next_node(sub, *it);
            if(status == tchecker::STATE_OK){
              std::string tgt_name = builder.node_name(tgt_node);
              if(!ed_details.first){
                //NOP Operation
                if(builder.isNewNode(state1, root, tgt_name, tgt_node, eqOrSim)){
                  builder.just_add_node(state1, root, tgt_name, tgt_node, to_do);
                if(builder.isNewNode(state1, root, tgt_name, tgt_node)){
                  builder.just_add_node(std::get<0>(top), std::get<1>(top), std::get<2>(top), std::get<3>(top), state1, root, tgt_name, tgt_node, to_do, *it);
                }
              } else {
                if(!ed_details.second.first){
                  //Push Operation
                  std::tuple<bool, int, node_ptr_t> z_1 = builder.isNewRoot(tgt_name, tgt_node);
                  node_ptr_t n = std::get<2>(z_1);
                  if(std::get<0>(z_1)){
                    builder.just_add_node(std::get<0>(top), std::get<1>(top), std::get<2>(top), std::get<3>(top), tgt_name, tgt_node, tgt_name, tgt_node, to_do, *it);
                  }
                  builder.append_push_and_match_pop(state1, root, tgt_name, n, ed_details.second.second, to_do, eqOrSim);
                } else {
                  //Pop Operation
                  builder.append_pop_and_match_push(state1, root, tgt_name, tgt_node, ed_details.second.second, to_do, eqOrSim);
                  builder.append_push_and_match_pop(top, std::get<1>(z_1), root, tgt_name, n, ed_details.second.second, to_do, *it);
                } else {
                  //Pop Operation
                  builder.append_pop_and_match_push(top, root, tgt_name, tgt_node, ed_details.second.second, to_do, *it);
                }
              }
            }
          }
        }

        // std::cout << "REACHABLE (WELL NESTED) STATES START\n";
        // std::cout << "REACHABLE (WELL NESTED) STATES END\n";
        std::cout << "[nodes, time(microseconds), states] = ";
        std::cout << "[" << count << ", ";
        //Get Witness
        if(non_empty){
        	std::stack<std::tuple<std::string, int, std::string, int>> zone_witness_1;
        	zone_witness_1.push(fin_top);
        	std::stack<typename TS::outgoing_edges_iterator_value_t> transitions;
        	builder.get_witness(fin_top, zone_witness_1, transitions);
        	std::cout << zone_witness_1.size() << "\t" << transitions.size() << "\n";
        	std::cout << "ZONE GRAPH NODES START\n";
        	while(!zone_witness_1.empty()){
        		std::tuple<std::string, int, std::string, int> t = zone_witness_1.top();
        		zone_witness_1.pop();
        		std::pair<node_ptr_t, node_ptr_t> np = builder.get_node(std::get<0>(t), std::get<1>(t), std::get<2>(t), std::get<3>(t));
        		graph.output_node(np.second);
        	}
        	std::cout << "ZONE GRAPH NODES END\n";


        	node_ptr_t x = initial_node;
        	typename TS::outgoing_edges_iterator_value_t ed = transitions.top();
        	edge_ptr_t edtemp;
        	int vars = transitions.size();
        	int curr_var = 1;
        	int guard_count = 1;

        	glp_prob *lp = glp_create_prob();
        	int ia[1+1000], ja[1+1000], icount = 1, jcount = 1, arcount = 1;
        	double ar[1+1000];
        	double epsilon = 0.1;
        	std::vector<std::pair<int, double>> gbounds;
        	auto evs = ts.model().system().events();
        	std::vector<std::string> all_events;
        	glp_term_out(GLP_OFF);

          std::vector<std::vector<std::tuple<std::string, int, int>>> all_guards;
          std::vector<std::vector<std::string>> all_resets;

        	std::cout << "ZONE WITNESS START\n";
        	graph.output_node(x);
        	while(!transitions.empty()){
        		ed = transitions.top();
        		std::tie(x, edtemp, status, is_new_node) = builder.next_node(x, ed);
        		std::pair<bool, std::pair<bool, std::string>> st_details = builder.edge_name(ed);
        		int event_id = builder.get_event_id(ed);
        		std::string event_name = evs.value(event_id);
        		all_events.push_back(event_name);
        		std::cout << "Event: " << event_name << "\tStack Operation: ";
        		if(!st_details.first){
        			std::cout << "NOP\t";
        		} else if(!st_details.second.first){
        			std::cout << "push " << st_details.second.second << "\t";
        		} else {
        			std::cout << "pop " << st_details.second.second << "\t";
        		}
        		graph.output_edge(edtemp);

	        	std::pair<std::vector<std::tuple<std::string, int, int>>, std::vector<std::string>> gnr = graph.get_g_n_r(edtemp);

	        	std::vector<std::tuple<std::string, int, int>> &g = gnr.first;
	        	std::vector<std::string> &r = gnr.second;

            all_guards.push_back(gnr.first);
            all_resets.push_back(gnr.second);

	        	for(auto it = g.begin() ; it != g.end() ; it++){
	        		std::tuple<std::string, int, int> grd = *it;
	        		int cmp = std::get<1>(grd);
	        		int val = std::get<2>(grd);
	        		int &vali = clocks[std::get<0>(grd)];
	        		double value = val;
	        		if(cmp >= 2){
	        			if(cmp == 3)	value += epsilon;
	        		} else {
	        			if(cmp == 0)	value -= epsilon;
	        		}
	        		for(int i = vali ; i <= curr_var ; i++){
	        			ia[icount++] = guard_count;
	        			ja[jcount++] = i;
	        			ar[arcount++] = 1;
	        		}
	        		gbounds.push_back(std::make_pair(cmp, value));
	        		guard_count++;
	        	}
	        	for(auto it = r.begin() ; it != r.end() ; it++){
	        		clocks[*it] = curr_var + 1;
	        	}
        		graph.output_node(x);
        		transitions.pop();
        		curr_var++;
        	}
        	std::cout << "ZONE WITNESS END\n";

        	int gsize = gbounds.size();
        	glp_add_rows(lp, gsize);
        	std::string rowstart = "p";
        	for(int i = 0 ; i < gsize ; i++){
        		std::pair<int, double> temp = gbounds[i];
        		glp_set_row_name(lp, i + 1, (rowstart + std::to_string(i + 1)).c_str());
        		if(temp.first >= 2)	glp_set_row_bnds(lp, i + 1, GLP_LO, temp.second, 0.0);
        		else	glp_set_row_bnds(lp, i + 1, GLP_UP, 0.0, temp.second);
        	}
        	glp_add_cols(lp, vars);
        	rowstart = "t";
        	for(int i = 1 ; i <= vars ; i++){
        		glp_set_col_name(lp, i, (rowstart + std::to_string(i)).c_str());
        		glp_set_col_bnds(lp, i, GLP_LO, 0.0, 0.0);
        		glp_set_obj_coef(lp, i, 0.0);
        	}
        	glp_load_matrix(lp, icount - 1, ia, ja, ar);
        	glp_simplex(lp, NULL);

        	std::cout << "TIMED WITNESS START\n";
        	double sol;
          std::vector<double> valuation(clocks.size(), 0);
          std::vector<std::string> clock_names;
          std::unordered_map<std::string, int> clock_indices;
          int cntt = 0;
          for(std::unordered_map<std::string, int>::iterator it = clocks.begin() ; it != clocks.end() ; it++){
            clock_names.push_back(it->first);
            clock_indices[it->first] = cntt++;
          }
        	std::cout << "Event\t" << "Time\t" << "Valuation before transition\t" << "Transition Guards\t\t\t" << "Transition Resets\n";
        	for(int i = 1 ; i <= vars ; i++){
        		sol = glp_get_col_prim(lp, i);
        		std::cout << all_events[i - 1] << "\t" << sol << "\t";
            for(int j = 0 ; j < valuation.size() ; j++) valuation[j] += sol;
            std::cout << "[";
            for(int j = 0 ; j < clock_names.size() - 1; j++){
              std::cout << clock_names[j] << "=" << valuation[j] << ", ";
            }
            std::cout << clock_names[clock_names.size() - 1] << "=" << valuation[clocks.size() - 1] << "]\t\t";
            std::vector<std::string> &resets = all_resets[i - 1];
            for(auto str : resets){
              valuation[clock_indices[str]] = 0;
            }
            std::vector<std::tuple<std::string, int, int>> &guards = all_guards[i - 1];
            if(guards.size() > 0){
              for(int j = 0 ; j < guards.size() ; j++){
                std::tuple<std::string, int, int> grd = guards[j];
                std::string clock = std::get<0>(grd);
                int cmp = std::get<1>(grd);
                int val = std::get<2>(grd);
                std::cout << clock << " ";
                if(cmp == 0)  std::cout << "< ";
                else if(cmp == 1)  std::cout << "<= ";
                else if(cmp == 2)  std::cout << ">= ";
                else if(cmp == 3)  std::cout << "> ";
                std::cout << val;
                if(j < guards.size() - 1) std::cout << " && ";
              }
              std::cout << "\t\t\t";
            }
            if(resets.size() > 0){
              std::cout << "{";
              for(int j = 0 ; j < resets.size() - 1 ; j++)  std::cout << resets[j] << ", ";
              std::cout << resets[resets.size() - 1];
              std::cout << "}";
            }
            std::cout << "\n";
        	}
        	std::cout << "TIMED WITNESS END\n";

        	glp_delete_prob(lp);
        } else {
          std::cout << "Empty Language\n";
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        std::cout << duration.count() << ", {";
        int reach_count = 0;
        for(auto it = reachable.begin() ; it != reachable.end() ; ){
        	std::cout << *it;
			it++;
			if(it != reachable.end())	std::cout << ", ";
        }
        std::cout << "}]\n\n";
        std::exit(0);
      }
    };
    
  } // end of namespace explore
  
} // end of namespace tchecker

#endif // TCHECKER_ALGORITHMS_EXPLORE_ALGORITHM_HH
