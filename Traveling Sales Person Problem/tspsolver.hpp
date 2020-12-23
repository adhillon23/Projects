#ifndef _TSP_SOLVER_HPP
#define _TSP_SOLVER_HPP

#include <iostream>

#include "listofpoints.hpp"

using namespace std;

// the class implement the TSP solver
class TSPSolver
{
   public:
   ListOfPoints m_list;
   
   TSPSolver(ListOfPoints &list);
   
   void solve();
   
   void printSolution(); 
   
   float getLength();//gets the length of the cycle 

};

#endif
