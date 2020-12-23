#include "tspsolver.hpp"

//copy constructor
TSPSolver::TSPSolver(ListOfPoints &list) {

  m_list.head = NULL;
  m_list.tail = NULL;

  node* n = list.head;

  while(n!=NULL){

   m_list.addPoint(n->p);
   n = n->next;
 }

}

void TSPSolver::solve() {

  node* n = m_list.head;

  //count the number of nodes in linked list
  int count = 0;
  while(n){
    count++;
    n = n->next;
  }


  node* a = m_list.head;// point that is being compared
  node* b;//iterates from a->next to end of linked list 
  node* track_b; //stores the node that is the shortest distance from point a

  /*Starts with the  first point (head), compares it to [a->next....n] and stores the point 
  which his shortest distance. Then, swaps a->next with shortest point which was found. Repeats 
  the process for each node in linked list */
  for(int i = 0; i < count-1; i++){

    b = a->next; 
    float short_dis = a->p.getDistance(b->p);
    track_b = b;

    while(b)
    {
     if(a->p.getDistance(b->p) < short_dis){
      short_dis = a->p.getDistance(b->p);
      track_b = b;
    }

    b = b->next;
  }

  //swap a->next with the shortest point
  int temp_x = a->next->p.getX();
  int temp_y = a->next->p.getY();
  string temp_name = a->next->p.getName();

  a->next->p.setX(track_b->p.getX());
  a->next->p.setY(track_b->p.getY());
  a->next->p.setName(track_b->p.getName());

  track_b->p.setX(temp_x);
  track_b->p.setY(temp_y);
  track_b->p.setName(temp_name);

  a = a->next;
}
}

void TSPSolver::printSolution() {

  node* n = m_list.head;

  while(n)
  {
   cout << "" << n->p.getName();
   if(n->next)
    cout << "->";

  n = n->next;
}
cout << endl;
}

float TSPSolver::getLength(){

  //if there are less than 2 point on the list, return 0
  if(m_list.head == NULL || m_list.head->next == NULL)
    return 0;
  
  float length = 0;

  //Iterate through linked list(which is now in the correct order) and find the length
  //between each point that next to one another. Add the length to total length.
  node*n = m_list.head;
  while(n->next){

    length = length + n->p.getDistance(n->next->p);
    n = n->next;
  }

  //find length between last point and first point
  length = length + m_list.head->p.getDistance(m_list.tail->p);

  return length;



}

