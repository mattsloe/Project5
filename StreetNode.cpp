//
//  StreetNode.cpp
//  Project5
//
//  Created by Matt Loera on 12/2/21.
//

#include "StreetNode.h"
#include <cstring>
#include <iostream>

StreetNode::StreetNode(Intersection* destination,const char* name,StreetNode* nextStreet)
  :streetName(new char[strlen(name)+1]),adjacent(destination),next(nextStreet)
{
  strcpy(streetName,name);
}

StreetNode::~StreetNode()
{
  delete[] streetName;
}

int StreetNode::getName(char* dest)const
{
  strcpy(dest,streetName);
  return 1;
}

int StreetNode::display()const
{
  std::cout << streetName;
  return 1;
}
