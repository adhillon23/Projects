#include "listofpoints.hpp"
#include <assert.h> 
#include<stdio.h>


//iterate through each node of the linked list and delete node on the heap.
ListOfPoints::~ListOfPoints() {

	node* n = head;

	while(n){
		node* temp = n->next;
		delete n;
		n = temp;
	}

}

//create a new node for each point and add it to the linked list
void ListOfPoints::addPoint(Point &newPt)  {

	node* n = new node(newPt);
	assert(n);


	if(head == NULL) 
	{
		head = n;
		tail = n;
	}
	else if(head != NULL) //else append the node
	{
		
		tail->next = n;
		tail = n;

	}

}

void ListOfPoints::printList() const {

	node* n = head;

	while(n!=NULL){

		printf("(%d, %d)\n", n->p.getX(), n->p.getY());
		n= n->next;

	}

}

void ListOfPoints::draw() const {

	cout << "drawing the points..." << endl;

  if(head == NULL)
    cout << "list is empty..." << endl;
  else{


	node* n = head;


  //find the min and max value for x and y out of all the points
  int x_min = n->p.getX();
  int x_max = n->p.getX();

  int y_min = n->p.getY();
  int y_max = n->p.getY();

  while(n!=NULL)
  {
  	if(n->p.getX() < x_min)
  		x_min = n->p.getX();

  	if(n->p.getX() > x_max)
  		x_max = n->p.getX();

  	if(n->p.getY() < y_min)
  		y_min = n->p.getX();

  	if(n->p.getY() > y_max)
  		y_max = n->p.getY();

  	n = n->next;
  }

  //each point is between 0 and 20 so set rows and
  //cols equal to max
  int rows= 20;
  int cols = 20;

  char draw_graph[rows][cols];//initialize 2d array

  //fill array with -'s
  for(int i = 0; i < rows; i++)
  {
  	for(int j = 0; j< cols; j++)
  	{
  		draw_graph[i][j] = '-';
  	}
  }

  //iterate through linked list and insert the letter corresponding to the point
  //into the 2d array at the correct index. 
  n = head;
  while(n!=NULL)
  {
  	draw_graph[(rows-1)-n->p.getY()][n->p.getX()] = n->p.getName()[0];
  	n = n->next;
  }

  //print the relevant portion of the graph
  n= head;
  for(int i = rows-(y_max+2); i < rows; i++)
  {
  	for(int j = 0; j< x_max+1; j++)
  	{
  		cout << " " << draw_graph[i][j];
  	}
  	printf("\n");
  }
}

}
