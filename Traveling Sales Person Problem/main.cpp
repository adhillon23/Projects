#include <iostream>
#include <cstdlib>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"

using namespace std;

void testPoint() {
  Point origin(0,0,"ORIGIN");
  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;
  
  Point q(3,4,"Q");
  cout << "--Creating new point Q:" << endl;
  q.printPoint();
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;


}


// gets a list of points and runs the solver on this list
// used in test1 and test2 below
void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;

  TSPSolver solver(input);
  solver.solve();

  cout << "Solution found is: " << endl;
  solver.printSolution();

 cout << "the length of the solution is: " << solver.getLength() << endl;
}

void test1() {
  Point p[4] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of random points:" << endl;

  for (int i=0;i<10;i++) {
    p = Point(i,0,"P"+to_string(i));
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test3() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of 20 random points betwen 0 and 20:" << endl;


  for (int i=0;i<20;i++) {
    p = Point(rand() % 20, rand() % 19,"P"+to_string(i));
    inputTSP.addPoint(p);
  }

  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  
  
  testSolver(inputTSP);
}

void test4() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of 200 random points with any value between 0 and 1000:" << endl;


  for (int i=0;i<200;i++) {
    p = Point(rand() % 1000, rand() % 1000,"P"+to_string(i));
    inputTSP.addPoint(p);
  } 
  
  testSolver(inputTSP);
}

void test5() {
  ListOfPoints inputTSP;

  cout << "Creating a list of 1 point:" << endl;

  Point p(15,15,"A");
  inputTSP.addPoint(p);

  cout << "Printing the list:" << endl;
  inputTSP.printList(); 
  inputTSP.draw();  
  
  testSolver(inputTSP);
}



int main() {

  cout << "****test point**" << endl;
  testPoint();
  cout << "****End of test point**" << endl << endl;

   cout << "****test1**:" << endl;
  test1();
  cout << "****end of test1**:" << endl << endl;
 
  cout << "****test2**:" << endl;
  test2();
  cout << "****end of test2**:" << endl << endl;

  cout << "****test3**:" << endl;
  test3();
  cout << "****end of test 3**:" << endl << endl;

  cout << "****test4**:" << endl;
  test4();
  cout << "****end of test 4**:" << endl << endl;

  cout << "****test5**:" << endl;
  test5();
  cout << "****end of test 5**:" << endl << endl;


  return 0;
}