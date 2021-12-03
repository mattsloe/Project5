//
//  Intersection.h
//  Project5
//
//  An Intersection is a metaphor for a Graph Vertex. Each Intersection contains
//  a pointer to a linked list of StreetNodes. It also has a name.
//  Created by Matt Loera on 12/2/21.
//

#ifndef Intersection_h
#define Intersection_h

#include <stdio.h>
class StreetNode;

class Intersection
{
public:
  /*Public Data Members*/
  StreetNode* adjList;
  
  /*ConstructorDestructor*/
  Intersection(char* name);
  ~Intersection();
  
  /*accessor*/
  //@pre
  //@post dest is populated with the name of the Intersection
  int getName(char* dest)const;
  
  /*functions*/
  //displays the Intersection to the user
  int display()const;
  
  
private:
  /*Private Data Members*/
  char* name;
};

#endif /* Intersection_h */
