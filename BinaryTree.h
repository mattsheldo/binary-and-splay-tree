#include <stdlib.h>
#include <iostream>

using namespace std;

/******************************************NODE HEADER******************************************/
class Node{

  //Each node should have
  Node* parent;//- pointer to the parent node
  Node* left;//- pointer to left child
  Node* right;//- pointer to right child
  int data;//- int for storing the key value

public:

  //constructor
  Node(int val);
  Node(int val, Node* left, Node* right, Node* parentnd);
  //getter and setter for nodes and value
  void setParent(Node* node);
  void setLeft(Node* node);
  void setRight(Node* node);
  void setData(int val);

  Node* getParent();
  Node* getLeft();
  Node* getRight();
  int getData();
};

Node::Node(int val){
  parent = NULL;
  left = NULL;
  right = NULL;
  data = val;
}

Node::Node(int val, Node* leftnd, Node* rightnd, Node* parentnd){
  parent = parentnd;
  left = leftnd;
  right = rightnd;
  data = val;
}
/********************************NODE SETTERS AND GETTERS*******************************/

void Node::setParent(Node* node){
  parent = node;
}
void Node::setLeft(Node* node){
  left = node;
}
void Node::setRight(Node* node){
  right = node;
}
void Node::setData(int val){
  data = val;
}

Node* Node::getParent(){
  return parent;
}
Node* Node::getLeft(){
  return left;
}
Node* Node::getRight(){
  return right;
}
int Node::getData(){
  return data;
}

/**********************************BINARY TREE HEADER***********************************/

class BinaryTree{

protected:
  //A tree should store only its root.
  Node* root;

public:
  //functions required
  Node* insert(int val);
  Node* search(int val);
  //- constructor
  BinaryTree();
  //- getter setter root
  void setRoot(Node* node);
  Node* getRoot();
  //- a function for printing the inorder visit of the tree
  void printTree(Node* node);
  //- a function for inserting a new value in the tree
  Node* recInsert(int val, Node* leaf);
  //- a function for searching a value in the tree.
  Node* recSearch(int val, Node* leaf);
};

/*******************************TREE SETTERS AND GETTERS********************************/

BinaryTree::BinaryTree(){
  root = NULL;
}
void BinaryTree::setRoot(Node* node){
  root = node;
}
Node* BinaryTree::getRoot(){
  return root;
}

/********************************TREE INSERT FUNCTIONS**********************************/

/*Recursively finds the correct spot for the value by comparing the desired value to the
the values of the tree and going left or right depending on the comparison.*/
Node* BinaryTree::recInsert(int val, Node* leaf){
  //Going left (insert val is smaller than val in tree)
  if(val < leaf->getData()){
    //There is a child node to the left
    if(leaf->getLeft() != NULL){
      recInsert(val, leaf->getLeft());
    }
    //There is no child to the left so we can add the new node here
    else{
      leaf->setLeft(new Node(val));
      leaf->getLeft()->setParent(leaf);
      return leaf->getLeft();
    }
  }
  //Going right (insert val is bigger than val in tree)
  else if(val > leaf->getData()){
    //If there is already a child to the right of the current node
    if(leaf->getRight() != NULL){
      recInsert(val, leaf->getRight());
    }
    //There is no child to the right so we can add the new node here
    else{
      leaf->setRight(new Node(val));
      leaf->getRight()->setParent(leaf);
      return leaf->getRight();
    }
  }
  //Value is already in the tree so we do nothing
  else{
    return leaf;
  }
}

/*This insert will deal with the case where the root has not been set yet.
If the root is already set it will call the other insert function which will
recursively go through the tree to find a place for the new val.*/
Node* BinaryTree::insert(int val){
  if(root == NULL){

    root = new Node(val);
    root->setData(val);
    return root;
  }
  else{
    return recInsert(val, root);
  }
}

/*******************************TREE SEARCH FUNCTIONS***********************************/

/*This search function is used to recursively iterate through the tree
while trying to find the value that is passed in*/
Node* BinaryTree::recSearch(int val, Node* leaf){
  /*If the leaf we are looking for exists (if we have reached not ret
  the bottom of the tree)*/
  if(leaf !=  NULL){
    //Check if we have found the node we are looking for
    if(val == leaf->getData()){
      //Here we are returning the leaf node so that this code can be used for the splay tree
      return leaf;
    }
    //We haven't found our node and we have to decide which way to look
    //The current node value is bigger than the one we are looking for so we go left
    if(val < leaf->getData()){
      if(leaf->getLeft() == NULL){
        return leaf;
      }
      return recSearch(val,leaf->getLeft());
    }
    //The current node value is smaller than the one we are looking for so we go right
    else{
      if(leaf->getRight() == NULL){
        return leaf;
      }
      return recSearch(val,leaf->getRight());
    }
  }
  //The value we are looking for is not in the tree
  else {
    return leaf;
  }
}

/*This search function is used to start the recursive search function so that
the user does not interact with the tree's root variable*/
Node* BinaryTree::search(int val){
  return recSearch(val, getRoot());
}

/***********************************PRINT INORDER***************************************/

void BinaryTree::printTree(Node* node){
  if(node == NULL){
    cout << endl;
    return;
  }

  printTree(node->getLeft());

  cout << node->getData() << " ";

  printTree(node->getRight());
}
