#include <iostream>
#include <string>
#pragma once
using namespace std;

class Tree {
protected:
    Tree *prev;
    int val;
    Tree *left;
    Tree *right;
    Tree* findMax(Tree*);

public:
    bool operator== (Tree*);
    bool operator!= (Tree*);
    bool isEqual(Tree*, Tree*);
    ~Tree();
    void addElement(Tree*);
    void initialize();
    void display();
    Tree* lookFor(Tree*,int);
    Tree* delElement (Tree*, int);
     };


