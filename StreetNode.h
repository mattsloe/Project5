//
//  StreetNode.h
//  Project5
//  StreetNode is a metaphor for an Edge Node in an adjacency list. It has
//  a name, a pointer to the adjacent Intersection(vertex) and a pointer to
//  the next StreetNode in the Linked list.
//
//  Some of the data will be public accessable. Encapsulation is not an issue
//  since implementation of the graph will be opaque to the client. The name field
//  will stay private for data purposes.
//  Created by Matt Loera on 12/2/21.
//

#ifndef StreetNode_h
#define StreetNode_h

#include <stdio.h>
#include "Intersection.h"

class StreetNode
{
public:
  /*Data Members*/
  Intersection* adjacent;
  StreetNode* next;
  
  /*ConstructorDestructor*/
  StreetNode(const Intersection*,const char*,const StreetNode*);
  ~StreetNode();
  
  /*Accessors*/
  //@post dest is populated with the name of the StreetNode
  int getName(char* dest)const;
  
  /*Functions*/
  //displays StreetNode to the user
  int display()const;
  
  
private:
  /*Private Data Members*/
  char* streetName;
  
  /*Private Functions*/
};

#endif /* StreetNode_h */
