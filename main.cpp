//
//  main.cpp
//  Project5
//
//  Created by Matt Loera on 12/2/21.
//

#include <iostream>
#include "Map.h"
#include <fstream>

const char* FILENAME="data.dat";

void testStreetNode();
void testIntersection();
void testMap();
void loadFromFile(Map&);
void displayTotalMap(Map&);
void testTraversal(Map&);

int main() {
//  testStreetNode();
//  std::cout << std::endl;
//  testIntersection();
//  std::cout << std::endl;
//  testMap();
  
  Map* aMap = new Map();
  Map& m = *aMap;
  
  loadFromFile(m);
  
  m.displayIntersections();
  displayTotalMap(m);
  
  testTraversal(m);
  
  return 0;
}

void testStreetNode()
{
  StreetNode aStreet(nullptr,"Yolo Street",nullptr,0);
  aStreet.display();
}

void testIntersection()
{
  char placeName[] = "Pound Town";
  Intersection aPlace(placeName);
  aPlace.display();
  
  StreetNode* aStreet = new StreetNode(nullptr,"Yolo Street",nullptr,0);
  aPlace.addStreet(*aStreet);
  aPlace.adjList->display();
}

void testMap()
{
  Map aMap;
  int intersectionAdded = aMap.addIntersection("Home");
  if(intersectionAdded) std::cout << "Success!\n";
  else std::cout << "Error!\n";
  
  //try adding a another intersection
  intersectionAdded = aMap.addIntersection("Midpoint");
  if(intersectionAdded) std::cout << "Success!\n";
  else std::cout << "Error!\n";
  
  intersectionAdded = aMap.addIntersection("destination");
  if(intersectionAdded) std::cout << "Success!\n";
  else std::cout << "Error!\n";
  
  aMap.displayIntersections();
  
  aMap.displayIntersection(1);
  aMap.displayIntersection(2);
  aMap.displayIntersection(3);
  
  aMap.addStreet("Route 1",0,1);
  aMap.addStreet("Route 2",1,2);
  aMap.addStreet("route 3",2,0);
  aMap.addStreet("Invalid Route",0,3);
  
  for(int i=0;i<3;i++) aMap.displayIntersection(i);
  

}

//Load from the file FILENAME into the data structure
//Phase 1: Load in Intersections
//Phase 2: Load in streets
void loadFromFile(Map& m)
{
  using namespace std;
  cout << "Initializing from file..";
  ifstream infile;
  char buf[1000]; //to hold input fields from file
  int int1=0,int2=0;
  
  infile.open(FILENAME);
  if(!infile) cout << "error opening file" << endl;
  while(infile){
    //Phase 1
    infile.ignore(1000,'\n'); //ignore first line
    infile.getline(buf,1000,'\n'); //read in first line
    while(buf[0]!='%'){
      //add the Intersection to the map
      m.addIntersection(buf);
      infile.getline(buf,1000,'\n'); //read in next line
    }
    //infile.ignore(); //ignore the \n
    //Phase 2
    while(infile.getline(buf,1000,',')){ //repeat until EOF
      infile >> int1;
      infile.ignore();
      infile >> int2;
      infile.ignore();//ignore the \n
      //add the Street to the map
      //cout<<buf<<','<<int1<<' '<<int2<<endl;
      m.addStreet(buf,int1-1,int2-1); //Convert from 1-indexing to 0-indexing
    }
    
  }
  infile.close();
  
  cout << "Success!" << endl;
}

void displayTotalMap(Map& m)
{
  int size = m.getSize();
  for(int i=0;i<size;i++){
    m.displayIntersection(i);
  }
}

void testTraversal(Map& m)
{
  m.dft(6); //dft from first node
}
