//
//  Map.cpp
//  Project5
//
//  Map is a metaphor for an ADT that will handle an adjacency table
//  for Streets and Intersections (for navigation purposes.)
//
//  Created by Matt Loera on 12/2/21.
//

#include "Map.h"
#include <iostream>
#include <fstream>

Map::Map()
  :array(nullptr),graphSize(0)
{
  
}

Map::~Map()
{
  //delete the array
  for(int i=0;i<graphSize;i++){
    delete array[i];
  }
}


int Map::addIntersection(const char* name)
{
  Intersection** newArray = new Intersection*[graphSize+1]; //make bigger array
  for(int i=0;i<graphSize;i++){
    newArray[i] = array[i];
  }
  newArray[graphSize] = new Intersection(name); //add in new intersection as last element
  delete array; //shallow delete
  array = newArray;
  graphSize++;
  return 1;
}

int Map::addStreet(const char* name, int intersection1, int intersection2)
{
  //check bounds
  if(intersection1 >= graphSize || intersection2 >= graphSize ||
     intersection1 < 0 || intersection2 < 0){
    std::cout << "Invalid Intersection!" << std::endl;
    return 0;
  }
  array[intersection1]->addStreet(name,array[intersection2],intersection2);
  array[intersection2]->addStreet(name,array[intersection1],intersection1);
  return 1;
}

int Map::traverse()const
{
  return 1;
}


int Map::displayIntersections()const
{
  for(int i=0;i<graphSize;i++){ //iterate through array
    std::cout<<i+1<<'|';
    array[i]->display();
    std::cout<< std::endl;
  }
  return 1;
}

int Map::displayIntersection(int index)const
{
  if(index<0 || index>=graphSize) return 0;
  std::cout<< "--------" << std::endl;
  array[index]->display();
  std::cout << std::endl <<"--------"<<std::endl;
  array[index]->displayStreets();
  return 1;
}

int Map::getSize()const
{
  return graphSize;
}

int Map::dft(int index)const
{
  index--; //change to 0-index
  if(index < 0 || index >= graphSize){ //check bounds
    std::cout << "Index out of bounds." << std::endl;
    return 0;
  }
  bool* visited = new bool[graphSize];
  for(int i=0;i<graphSize;i++){
    visited[i] = false; //initialize the array
  }
  dft(index,visited);
  delete[] visited;
  return 1;
}

//for visiting an Intersection
int Map::dft(int i,bool* visited)const
{
  //mark as visited and print
  visited[i] = true;
  array[i]->display();
  std::cout << "->";
  
  //recursion
  //for all of the edges
  return _dft(array[i]->adjList,visited);
}

int Map::_dft(StreetNode* edge,bool* visited)const
{
  //Base: edge=null
  if(!edge)return 0;
  //if not visited, dft this intersection
  if(!visited[edge->adj]){
    std::cout<<'[';
    edge->display();
    std::cout << "]->";
    dft(edge->adj,visited);
  }else{
    std::cout << "\n<<==";
  }
  //dft the next edge
  return _dft(edge->next,visited);
}
