#include <iostream>
#include <string>


using namespace std;

class Tree {
protected:
    Tree *prev;
    int val;
    Tree *left;
    Tree *right;
public:
    void addElement(Tree*);
    void initialize();
    void display();
    Tree* lookFor(Tree*);
    void delElement (Tree*);
     };


