# Binary and Splay Trees

This repo contains code that emulates the behaviour of binary and splay trees. There are two mains included in this repo. The first one is the actual main and the second one was used when testing the program. The Timer.cpp and Timer.h files were provided to my class at the start of the assignment and I did not write them. They are used to judge the efficiency of the program.

## Binary Tree

Binary trees are a type of tree datastructure where each node has at most 2 child nodes that are referred to as the left and right children. Binary trees are useful because they can make it easier to search through a data set. Binary trees are often sorted so that children who are lower value than the parent are inserted on the left and children who are higher value than the parent are inserted on the right. This makes searching easier because you never look through every node in the tree and you only have to compare the current node to the node you are looking for to navigate the tree. For example in the image below if we want to find the node with a value of 6 we start at 8 and since 6 < 8 we move to the left child. Since the left child is 3 and 3 < 6 we move to the right child and we find ourselves at our destination.

![image](https://user-images.githubusercontent.com/83359136/117318236-39805980-ae58-11eb-9289-a2edcdf8cf00.png)

## Splay Tree

Splay Trees are slightly different than binary trees. They contain all the same rules and properties but splay trees have an additional property. Splay trees not only change when a new node is inserted into the tree but also whenever a node is searched for. Whenever a new node is inserted or searched for the tree is shifted so that the new node becomes the root node at the top. This is done because recent data is frequently asked for again so by keeping the most recently used nodes at the top of the tree they will be found faster. 

## Try it yourself!

Use Git to clone the repository and run the program. On your machine navigate to your desired folder and run the following command.

```bash
git clone https://github.com/mattsheldo/shortest-paths.git
```

Once you have the repository cloned on your machine you can run the following commands to compile and run the code.

To Compile:
```bash
g++ main.cpp Timer.cpp
```
To Run:
```bash
./a.out
```
