#ifndef DASPLANNER_H_INCLUDED
#define DASPLANNER_H_INCLUDED

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

//DASPLANNER_Planner
  #include <rp_heuristic.hxx>
  #include <aptk/das.hxx>
// DASPLANNER_Planner

using	aptk::STRIPS_Problem;
using	aptk::agnostic::Fwd_Search_Problem;

// (BFS_HMAX_Planner) (DASPLANNER_Planner)
using aptk::agnostic::H1_Heuristic;
using	aptk::agnostic::H_Add_Evaluation_Function;
using	aptk::agnostic::H_Max_Evaluation_Function;
using aptk::search::Open_List;
using	aptk::search::Node_Comparer;
// BFS_HMAX_Planner

// DASPLANNER_Planner
using	aptk::agnostic::Relaxed_Plan_Heuristic;
using aptk::search::das::Node;
using	aptk::search::das::Deadline_Aware_Search;
// DASPLANNER_Planner

// DASPLANNER_Planner
// MRJ: Now we define the heuristics
typedef		H1_Heuristic<	Fwd_Search_Problem, H_Add_Evaluation_Function, aptk::agnostic::H1_Cost_Function::LAMA>				H_Add_Fwd;

typedef		Relaxed_Plan_Heuristic< Fwd_Search_Problem, H_Add_Fwd >				H_Add_Rp_Fwd;

typedef 	H1_Heuristic<	Fwd_Search_Problem, H_Max_Evaluation_Function, aptk::agnostic::H1_Cost_Function::Ignore_Costs >		H_Max_Unit_Fwd;

typedef		Relaxed_Plan_Heuristic< Fwd_Search_Problem, H_Max_Unit_Fwd, aptk::agnostic::RP_Cost_Function::Ignore_Costs >	H_FF;

typedef		Node< aptk::State >						DAS_Search_Node;
typedef		Node_Comparer< DAS_Search_Node >					DAS_Tie_Breaking_Algorithm;
typedef		Open_List< DAS_Tie_Breaking_Algorithm, DAS_Search_Node >		DAS_Open_List;

typedef		Deadline_Aware_Search< Fwd_Search_Problem, H_Add_Rp_Fwd, H_FF, DAS_Open_List > DAS;
// DASPLANNER_Planner

extern void output_Plan (const aptk::Action& action);

/** The OUTPUT ORDER has been reversed to simplify the arrangement of sub-goals.
  *
  */
template <typename Search_Engine>
float DASPLANNER_do_search( Search_Engine& engine, const STRIPS_Problem& plan_prob, float budget, std::string logfile )
{

	std::ofstream out( logfile.c_str() );

	engine.set_budget( budget );
	engine.start();

	std::vector< aptk::Action_Idx > plan;
	float				cost;

	float ref = aptk::time_used();
	float t0 = aptk::time_used();

  std::ofstream myout( "dimitri.problem" );
  plan_prob.print(myout);

	unsigned expanded_0 = engine.expanded();
	unsigned generated_0 = engine.generated();


	while ( engine.find_solution( cost, plan ) ) {
		out << "Plan found with cost: " << cost << std::endl;
		for ( unsigned k = 0; k < plan.size(); k++ ) {
//			out << k+1 << ". ";
			output_Plan(*(plan_prob.actions()[ plan[k] ]));
//			const aptk::Action& a = *(plan_prob.actions()[ plan[k] ]);
//			out << a.signature();
//			out << std::endl;
		}
		float tf = aptk::time_used();
		unsigned expanded_f = engine.expanded();
		unsigned generated_f = engine.generated();
		out << "Time: " << tf - t0 << std::endl;
		out << "Generated: " << generated_f - generated_0 << std::endl;
		out << "Expanded: " << expanded_f - expanded_0 << std::endl;
		t0 = tf;
		expanded_0 = expanded_f;
		generated_0 = generated_f;
		plan.clear();
	}
	float total_time = aptk::time_used() - ref;
	out << "Total time: " << total_time << std::endl;
	out << "Nodes generated during search: " << engine.generated() << std::endl;
	out << "Nodes expanded during search: " << engine.expanded() << std::endl;
	out << "Nodes pruned by bound: " << engine.pruned_by_bound() << std::endl;
	out << "Dead-end nodes: " << engine.dead_ends() << std::endl;
	out << "Nodes in OPEN replaced: " << engine.open_repl() << std::endl;

	out.close();

	return total_time;
}


#endif // DASPLANNER_H_INCLUDED
