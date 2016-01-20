#ifndef BFS_HMAX_H_INCLUDED
#define BFS_HMAX_H_INCLUDED

/**
Lightweight Automated Planning Toolkit
Copyright (C) 2012
Miquel Ramirez <miquel.ramirez@rmit.edu.au>
Nir Lipovetzky <nirlipo@gmail.com>

Adapted to the Idempotent Planning Protocol Demonstration by
Dimitri Joukoff <dimitri.joukoff@griffithuni.edu.au>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <ff_to_aptk.hxx>
#include <strips_prob.hxx>
#include <fluent.hxx>
#include <action.hxx>
#include <cond_eff.hxx>
#include <strips_state.hxx>
#include <fwd_search_prob.hxx>
#include <aptk/string_conversions.hxx>


//(BFS_HMAX_Planner) (DASPLANNER_Planner)
  #include <h_1.hxx>
  #include <aptk/open_list.hxx>
  #include <aptk/at_bfs.hxx>
// BFS_HMAX_Planner

using	aptk::STRIPS_Problem;
using	aptk::agnostic::Fwd_Search_Problem;

// BFS_HMAX_Planner
using	aptk::Action;
using	aptk::search::bfs::AT_BFS_SQ_SH;
// BFS_HMAX_Planner

// (BFS_HMAX_Planner) (DASPLANNER_Planner)
using aptk::agnostic::H1_Heuristic;
using	aptk::agnostic::H_Add_Evaluation_Function;
using	aptk::agnostic::H_Max_Evaluation_Function;
using aptk::search::Open_List;
using	aptk::search::Node_Comparer;
// BFS_HMAX_Planner

// BFS_HMAX_Planner
//NIR: We start defining the type of nodes for our planner
typedef		aptk::search::bfs::Node< aptk::State >	Search_Node;
//NIR: Then we define the type of the tie-breaking algorithm
// for the open list we are going to use
typedef		Node_Comparer< Search_Node >					Tie_Breaking_Algorithm;
//NIR: Now we define the Open List type by combining the types we have defined before
typedef		Open_List< Tie_Breaking_Algorithm, Search_Node >		BFS_Open_List;
//NIR: Now we define the heuristics
typedef 	H1_Heuristic<Fwd_Search_Problem, H_Max_Evaluation_Function>	H_Max_Fwd;
//NIR: Now we're ready to define the BFS algorithm we're going to use
typedef		AT_BFS_SQ_SH< Fwd_Search_Problem, H_Max_Fwd, BFS_Open_List >		BFS_H_Max_Fwd;
// BFS_HMAX_Planner

extern void output_Plan (const aptk::Action& action);

/** The OUTPUT ORDER has been reversed to simplify the arrangement of sub-goals.
  *
  */
float BFS_HMAX_do_search(  Fwd_Search_Problem& search_prob, float& cost,std::ofstream& details, std::string plan_filename,  bool anytime, bool delayed, bool greedy  )
{
	std::vector< aptk::Action_Idx > plan;
	cost = infty;

	float ref = aptk::time_used();
	float t0 = aptk::time_used();

	BFS_H_Max_Fwd engine( search_prob );
	engine.set_greedy( greedy );
	engine.set_delay_eval( delayed );
	engine.start();

	unsigned expanded_0 = engine.expanded();
	unsigned generated_0 = engine.generated();

	while ( engine.find_solution( cost, plan ) ) {
		if ( !plan.empty() ) {
			details << "Plan found with cost: " << cost << std::endl;
			if( anytime ) std::cout << "Plan found with cost: " << cost << std::endl;
			std::ofstream plan_stream( plan_filename.c_str() );
//			output_Plan(*(search_prob.task().actions()),plan.size() );
			for ( unsigned k = 0; k < plan.size(); k++ ) {
//				details << k+1 << ". ";
        output_Plan(*(search_prob.task().actions()[ plan[k] ]));
//				const aptk::Action& a = *(search_prob.task().actions()[ plan[k] ]);
//				details << a.signature();
//				details << std::endl;
//				plan_stream << a.signature() << std::endl;
			}
			plan_stream.close();
		}
		else
			details << "No plan found" << std::endl;
		float tf = aptk::time_used();
		unsigned expanded_f = engine.expanded();
		unsigned generated_f = engine.generated();
		details << "Time: " << tf - t0 << std::endl;
		details << "Generated: " << generated_f - generated_0 << std::endl;
		details << "Expanded: " << expanded_f - expanded_0 << std::endl;
		if(anytime){
			std::cout << "Time: " << tf - t0 << std::endl;
			std::cout << "Generated: " << generated_f - generated_0 << std::endl;
			std::cout << "Expanded: " << expanded_f - expanded_0 << std::endl << std::endl;
		}
		t0 = tf;
		expanded_0 = expanded_f;
		generated_0 = generated_f;
		plan.clear();

		if(!anytime) break;
	}

	float total_time = aptk::time_used() - ref;
	std::cout << "Total time: " << total_time << std::endl;
	std::cout << "Nodes generated during search: " << engine.generated() << std::endl;
	std::cout << "Nodes expanded during search: " << engine.expanded() << std::endl;
	std::cout << "Nodes pruned by bound: " << engine.pruned_by_bound() << std::endl;
	std::cout << "Dead-end nodes: " << engine.dead_ends() << std::endl;
	std::cout << "Plan found with cost: " << cost << std::endl;

	return total_time;

}


#endif // BFS_HMAX_H_INCLUDED
