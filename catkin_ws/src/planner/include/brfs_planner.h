#ifndef BRFS_PLANNER_INCLUDED
#define BRFS_PLANNER_INCLUDED

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

//BRFS_Planner
  #include <aptk/brfs.hxx>
// BRFS_Planner

using	aptk::STRIPS_Problem;
using	aptk::agnostic::Fwd_Search_Problem;

// BRFS_Planner
using	aptk::search::brfs::BRFS;
// BRFS_Planner

// BRFS_Planner
typedef		BRFS< Fwd_Search_Problem > BRFS_Fwd;
// BRFS_Planner

extern void output_Plan (const aptk::Action& action);

// BRFS_Planner
/** The OUTPUT ORDER has been reversed to simplify the arrangement of sub-goals.
  *
  */
template <typename Search_Engine>
float BRFS_do_search( Search_Engine& engine, STRIPS_Problem& plan_prob, float budget, std::string logfile ){

	//	std::ofstream out( logfile.c_str() );

	engine.start();

	std::vector< aptk::Action_Idx > plan;
	float				cost;

	float ref = aptk::time_used();
	float t0 = aptk::time_used();

	unsigned expanded_0 = engine.expanded();
	unsigned generated_0 = engine.generated();

	if ( engine.find_solution( cost, plan ) ) {
		std::cout << "Plan found with cost: " << cost << std::endl;
		for ( unsigned k = 0; k < plan.size(); k++ ) {
//			std::cout << k+1 << ". ";
      output_Plan(*(plan_prob.actions()[ plan[k] ]));
//			const aptk::Action& a = *(plan_prob.actions()[ plan[k] ]);
//			std::cout << a.signature();
//			std::cout << std::endl;
		}
		float tf = aptk::time_used();
		unsigned expanded_f = engine.expanded();
		unsigned generated_f = engine.generated();
		std::cout << "Time: " << tf - t0 << std::endl;
		std::cout << "Generated: " << generated_f - generated_0 << std::endl;
		std::cout << "Expanded: " << expanded_f - expanded_0 << std::endl;
		t0 = tf;
		expanded_0 = expanded_f;
		generated_0 = generated_f;
		plan.clear();
	}
 	float total_time = aptk::time_used() - ref;
//	std::cout << "Total time: " << total_time << std::endl;
//	std::cout << "Nodes generated during search: " << engine.generated() << std::endl;
//	std::cout << "Nodes expanded during search: " << engine.expanded() << std::endl;
//	std::cout << "Nodes Closed Pruned during search: " << engine.pruned_closed() << std::endl;

	//out.close();

	return total_time;
}
// BRFS_Planner

#endif // BRFS_PLANNER_INCLUDED
