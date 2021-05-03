#include "BinaryTree.h"

//class implementing the Splay tree
class SplayTree : public BinaryTree{

  //extending the Binary you raughly have everything you need

public:
  //TODO:
  //a new function for inserting a node into the tree
  SplayTree splayInsert(int val, SplayTree tree);
  //a new function for searching a node into the tree
  SplayTree splaySearch(int val, SplayTree tree);
  //a new function for performing splay
  SplayTree splay(Node* node, SplayTree tree);

  //Zig left and right functions
  SplayTree zig(Node* node, SplayTree tree);
  SplayTree zag(Node* node, SplayTree tree);

  //Zigzag left and right functions
  SplayTree zigzag(Node* node, SplayTree tree);
  SplayTree zagzig(Node* node, SplayTree tree);

  //Zigzig left and right functions
  SplayTree zigzig(Node* node, SplayTree tree);
  SplayTree zagzag(Node* node, SplayTree tree);

  void inOrderPrint(Node* root);
};

/***********************************ZIGS AND ZAGS***************************************/

/*
                y                                     x
               / \     Zig (Right Rotation)          /  \
              x   T3   – - – - – - – - - ->         T1   y
             / \                                        / \
            T1  T2                                    T2   T3
In this function node is representing x and parentNode is representing y
For this rotation T1 and T3 do not get touched so we dont have to worry about them*/
SplayTree zig(Node* node, SplayTree tree){
  //Create a parent node (y)
  Node* parentNode = node->getParent();
  //Checks to see if T2 exists in the tree
  if(node->getRight() != NULL){
    //Move T2 from x's right child to y's left child
    parentNode->setLeft(node->getRight());
    node->getRight()->setParent(parentNode);
  }
  //T2 does not exist in the tree so we make y's left null
  else{
    parentNode->setLeft(new Node(0));
    parentNode->setLeft(NULL);
  }
  //Make x the parent of y and set the root to now be x
  node->setRight(parentNode);
  node->setParent(new Node(0));
  node->setParent(NULL);
  parentNode->setParent(node);
  tree.setRoot(node);
  return tree;
}

/*
                y                                    x
               / \     Zag (Left Rotation)         /  \
            T3   x   – - – - – - – - - ->         y   T1
                / \                              / \
              T2  T1                           T3   T2
In this function node is representing x and parentNode is representing y
For this rotation T1 and T3 do not get touched so we dont have to worry about them*/
SplayTree zag(Node* node, SplayTree tree){
  //Create a temp node (y)
  Node* parentNode = node->getParent();
  //Checks to see if T2 exists in the tree
  if(node->getLeft() != NULL){
    //Move T2 from x's left child to y's right child
    parentNode->setRight(node->getLeft());
    node->getLeft()->setParent(parentNode);
  }
  //T2 does not exist in the tree so we make y's right null
  else{
    parentNode->setRight(new Node(0));
    parentNode->setRight(NULL);
  }
  //Make x the parent of y and set the root to now be x
  node->setLeft(parentNode);
  node->setParent(new Node(0));
  node->setParent(NULL);
  parentNode->setParent(node);
  tree.setRoot(node);
  return tree;
}

/*
                z                      z                      x
               / \     Zig Zag       /  \     Zig Zag        / \
              y  T4   – - – - ->    x   T4   - - - - ->    y     z
            / \                    / \                    / \   / \
          T1   x                  y   T3                 T1 T2 T3 T4
              / \               / \
             T2 T3             T1 T2
In this function node is representing x, parentNode is representing y, and grandParentNode is representing z
For the first rotation T1 T3 and T4 do not get touched so we dont have to worry about them
and for the second rotation T1 T2 and T4 do not get touched so we dont have to worry about them.*/
SplayTree zigzag(Node* node, SplayTree tree){

  //First Rotation//

  //Create temp nodes for y and z
  Node* parentNode = node->getParent();
  Node* grandParentNode = node->getParent()->getParent();
  //Check to see if there is a T2
  if(node->getLeft() != NULL){
    //Move T2 from x's left to y's right
    parentNode->setRight(node->getLeft());
    node->getLeft()->setParent(parentNode);
  }
  //There is no T2 so make y's right null
  else{
    parentNode->setRight(new Node(0));
    parentNode->setRight(NULL);
  }
  //x is moved above y
  node->setLeft(parentNode);
  node->setParent(grandParentNode);
  parentNode->setParent(node);
  grandParentNode->setLeft(node);

  //Second Rotation//

  //Check to see if T3 exists
  if(node->getRight() != NULL){
    //Move T3 from x's right to z's left
    node->getRight()->setParent(grandParentNode);
    grandParentNode->setLeft(node->getRight());
  }
  //T3 doesn't exist so make z's left null
  else{
    grandParentNode->setLeft(NULL);
  }
  //move x above z and make x new root
  node->setRight(grandParentNode);
  node->setParent(new Node(0));
  node->setParent(NULL);
  grandParentNode->setParent(node);
  tree.setRoot(node);
  return tree;
}

/*
                z                      z                      x
               / \     Zag Zig       /  \     Zag Zig        / \
              T1  y   – - – - ->    T1   x   - - - - ->    z    y
                / \                    / \                / \  / \
               x  T4                  T2  y             T1 T2 T3 T4
              / \                        / \
             T2 T3                      T3 T4
In this function node is representing x, parentNode is representing y, and grandParentNode is representing z
For the first rotation T1 T2 and T4 do not get touched so we dont have to worry about them
and for the second rotation T1 T3 and T4 do not get touched so we dont have to worry about them.*/
SplayTree zagzig(Node* node, SplayTree tree){

  //First Rotation//

  //Create temp nodes for y and z
  Node* parentNode = node->getParent();
  Node* grandParentNode = node->getParent()->getParent();
  //Check to see if T3 exists
  if(node->getRight() != NULL){
    //Move T3 from x's right to y's left
    node->getRight()->setParent(parentNode);
    parentNode->setLeft(node->getRight());
  }
  //T3 doesn't exist so y's left is null
  else{
    parentNode->setLeft(0);
    parentNode->setLeft(NULL);
  }
  //Move x above y
  node->setParent(grandParentNode);
  node->setRight(parentNode);
  grandParentNode->setRight(node);
  parentNode->setParent(node);

  //Second Rotation//

  //Check if T2 exists
  if(node->getLeft() != NULL){
    //Move T2 from x's left to z's right
    node->getLeft()->setParent(grandParentNode);
    grandParentNode->setRight(node->getLeft());
  }
  //T2 does not exist so z's right is null
  else{
    grandParentNode->setRight(new Node(0));
    grandParentNode->setRight(NULL);
  }
  //Move x above z and make x the new root
  node->setLeft(grandParentNode);
  grandParentNode->setParent(node);
  node->setParent(new Node(0));
  node->setParent(NULL);
  tree.setRoot(node);
  return tree;
}

/*
                z                      y                   x
               / \     Zig Zig       /  \     Zig Zig     / \
              y  T4   – - – - ->    x    z  - - - - ->   T1  y
            / \                   / \   / \                 / \
           x  T3                 T1 T2 T3 T4               T2  z
         / \                                                  / \
        T1 T2                                                T3  T4
In this function node is representing x, parentNode is representing y, and grandParentNode is representing z
For the first rotation T1 T2 and T4 do not get touched so we dont have to worry about them
and for the second rotation T1 T3 and T4 do not get touched so we dont have to worry about them.*/
SplayTree zigzig(Node* node, SplayTree tree){

  //First Rotation//

  //Create temp nodes for y and z
  Node* parentNode = node->getParent();
  Node* grandParentNode = node->getParent()->getParent();
  //Check to see if T3 exists
  if(parentNode->getRight() != NULL){
    //Move T3 from y's right to z's left
    parentNode->getRight()->setParent(grandParentNode);
    grandParentNode->setLeft(parentNode->getRight());
  }
  else{
    //T3 doesn't exist so make z's left null
    grandParentNode->setLeft(new Node(0));
    grandParentNode->setLeft(NULL);
  }
  //Move y above z and make y new root
  parentNode->setRight(grandParentNode);
  parentNode->setParent(new Node(0));
  parentNode->setParent(NULL);
  grandParentNode->setParent(parentNode);
  tree.setRoot(parentNode);

  //Second Rotation//

  //Check to see if T2 exists
  if(node->getRight() != NULL){
    //Move T2 from x's right to y's left
    node->getRight()->setParent(parentNode);
    parentNode->setLeft(node->getRight());
  }
  //T2 doesn't exist so make y's left null
  else{
    parentNode->setLeft(new Node(0));
    parentNode->setLeft(NULL);
  }
  //Move x above y and make x the new root
  node->setRight(parentNode);
  node->setParent(new Node(0));
  node->setParent(NULL);
  parentNode->setParent(node);
  tree.setRoot(node);
  return tree;
}

/*
           z                      y                   x
          / \     Zag Zag       /  \     Zag Zag     / \
        T1   y   – - – - ->    z    x  - - - - ->   y   T4
            / \              / \   / \             / \
           T2  x            T1 T2 T3 T4           z  T3
              / \                                / \
             T3 T4                             T1  T2
In this function node is representing x, parentNode is representing y, and grandParentNode is representing z
For the first rotation T1 T3 and T4 do not get touched so we dont have to worry about them
and for the second rotation T1 T2 and T4 do not get touched so we dont have to worry about them.*/
SplayTree zagzag(Node* node, SplayTree tree){

//First Rotation//

  //Create temp nodes for y and z
  Node* parentNode = node->getParent();
  Node* grandParentNode = node->getParent()->getParent();
  //Check to see if T2 exists
  if(parentNode->getLeft() != NULL){
    //Move T2 from y's left to z's right
    parentNode->getLeft()->setParent(grandParentNode);
    grandParentNode->setRight(parentNode->getLeft());
  }
  //T2 doesn't exist so z's right is null
  else{
    grandParentNode->setRight(new Node(0));
    grandParentNode->setRight(NULL);
  }
  //Move y above z and make y the new root
  parentNode->setParent(new Node(0));
  parentNode->setParent(NULL);
  grandParentNode->setParent(parentNode);
  parentNode->setLeft(grandParentNode);
  tree.setRoot(parentNode);

  //Second Rotation//

  //Check to see if T3 exists
  if(node->getLeft() != NULL){
    //Move T3 from x's left to y's right
    node->getLeft()->setParent(parentNode);
    parentNode->setRight(node->getLeft());
  }
  //T3 doesn't exist so make y's right null
  else{
    parentNode->setRight(new Node(0));
    parentNode->setRight(NULL);
  }
  //Move x above y and make x the new root
  node->setLeft(parentNode);
  node->setParent(new Node(0));
  node->setParent(NULL);
  parentNode->setParent(node);
  tree.setRoot(node);
  return tree;
}

/***********************************SPlAY FUNCTION**************************************/

SplayTree splay(Node* node, SplayTree tree){
  //While the current node is not root
  while(node->getParent() != NULL){
    //If the node does not have a grand parent
    if(node->getParent()->getParent() == NULL){
      //If the node is on the left of their parent zig
      if(node == node->getParent()->getLeft()){
        tree = zig(node, tree);
        return tree;
      }
      //If the node is on the right of their parent zag
      else{
        tree = zag(node, tree);
        return tree;
      }
    }
    //If the current node and its parent are both left children zig zig
    else if(node == node->getParent()->getLeft() and node->getParent() == node->getParent()->getParent()->getLeft()){
      tree = zigzig(node, tree);
      return tree;
    }
    //If the current node and its parent are both right children zag zag
    else if(node == node->getParent()->getRight() and node->getParent() == node->getParent()->getParent()->getRight()){
      tree = zagzag(node, tree);
      return tree;
    }
    //If the current node is a right child and its parent is a left child zig zag
    else if(node == node->getParent()->getRight() and node->getParent() == node->getParent()->getParent()->getLeft()){
      tree = zigzag(node, tree);
      return tree;
    }
    //If the current node is a left child and its parent is a right child zag zig
    else{
      tree = zagzig(node, tree);
      return tree;
    }
  }
  return tree;
}

/***********************************INSERT FUNCTION*************************************/

SplayTree splayInsert(int val, SplayTree tree){
  Node* last = tree.insert(val);
  tree = splay(last, tree);
  return tree;
}

/***********************************SEARCH FUNCTION*************************************/

SplayTree splaySearch(int val, SplayTree tree){
  Node* last = tree.search(val);
  tree = splay(last, tree);
  return tree;
}

/************************************INORDER PRINT**************************************/

void inOrderPrint(Node* root){
  if(root){
    inOrderPrint(root->getLeft());
    cout << "Node Value: " << root->getData();
    if(root->getLeft()){
      cout << " | left child: " << root->getLeft()->getData();
    }
    if(root->getRight()){
      cout << " | right child: " << root->getRight()->getData();
    }
    cout << endl;
    inOrderPrint(root->getRight());
  }
}
