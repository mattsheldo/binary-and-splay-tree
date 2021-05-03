#include "SplayTree.h"
//#include "Timer.h"

#include <list>
#include <random>

using namespace std;

int main(int argc, char* argv[]){

  int  values[]  = {10, 15, 12};
  int  values2[]  = {15, 9, 5};

  SplayTree tree;//TODO: put here the constructor of your Splay tree
  for(int i = 0; i < 3; i++){
      tree = splayInsert(values[i], tree);//TODO: call the insert function on your splay tree
  }

  //search numbers in binary tree
  for(int i = 0; i < 3; i++){
      tree = splaySearch(values2[i], tree);//TODO: call the search function on your splay tree
  }
  //TODO: print the content of your Splay tree
  tree.printTree(tree.getRoot());
}
