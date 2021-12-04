//
//  Map.h
//  Project5
//
//  Map is an ADT to handle the data associated with a group of places called
//  Intersections, and the Streets that connect them.
//
//  Created by Matt Loera on 12/2/21.
//

#ifndef Map_h
#define Map_h

#include <stdio.h>
#include "StreetNode.h"
#include "Intersection.h"

class Map
{
public:
  /*ConstructorDestructor*/
  Map();
  ~Map();
  
  /*Functions*/
  //Adds an intersection with the given name.
  //@post returns the index of the intersection
  int addIntersection(const char* name);
  
  //adds a street between two intersections
  //@param name is the name of the street, intersection1 and intersection2 are
  //      the intersections that the street connects to. intersections must be references
  //      to valid indices of streets.
  //@post return false if referenced intersections do not exist. Street gets added
  //      to the map
  int addStreet(const char* name,int intersection1, int intersection2);
  
  //a program that allows the client to visually traverse the graph
  int traverse()const;
  
  //to display the intersections
  int displayIntersections()const;
  
  //to display a specific intersection
  int displayIntersection(int index)const;
  
  //return the number of intersections
  int getSize()const;
  
  
private:
  /*Data Members*/
  Intersection** array; //adjacency table
  int graphSize; //number of Intersections in the graph
  
};

#endif /* Map_h*/
