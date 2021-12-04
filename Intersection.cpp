//
//  Intersection.cpp
//  Project5
//
//  Created by Matt Loera on 12/2/21.
//

#include "Intersection.h"
#include <cstring>
#include <iostream>
#include "StreetNode.h"

Intersection::Intersection(const char* _name)
  :adjList(nullptr),name(new char[strlen(_name)+1])
{
  strcpy(name,_name);
}

Intersection::~Intersection()
{
  delete[] name;
  //delete the Linked List of Streets
  deleteStreets(adjList);
}

int Intersection::getName(char* dest)const
{
  strcpy(dest,name);
  return 1;
}

int Intersection::display()const
{
  std::cout << name;
  return 1;
}

int Intersection::displayStreets()const
{
  
  return displayStreets(adjList,1);
}
int Intersection::addStreet( StreetNode& toAdd)
{
  addStreet(&toAdd,adjList);
  return 1;
}

int Intersection::addStreet(const char* name, Intersection* destination)
{
  StreetNode* newStreet = new StreetNode(destination,name,nullptr);
  addStreet(*newStreet);
  return 1;
}

/*PRIVATE*/

int Intersection::addStreet(StreetNode* toAdd, StreetNode*& root)
{
  if(!root){ //if list is empty, add here
    root = toAdd;
  }else{
    return addStreet(toAdd,root->next); //move down the list
  }
  
  root->next = nullptr;
  return 1;
}

int Intersection::deleteStreets(StreetNode* root)
{
  if(!root){ //end of list reached stop recursion
    return 0;
  }
  StreetNode* nxt = root->next;
  delete root;
  return 1+deleteStreets(nxt); //move to next element
}

//recursive function to display LLL
int Intersection::displayStreets(StreetNode* root,int counter)const
{
  if(!root) return 0;
  std::cout<<'\t'<<counter<<'|';
  root->display();
  std::cout<<std::endl;
  return displayStreets(root->next,counter+1);
}
