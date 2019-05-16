#include "tree.h"
void Tree::initialize(){  //Ustawienie pierwszego elementu drzewa
    prev=NULL;
    left=NULL;
    right=NULL;
    int x;
    cin >> x;
    val=x;
}


void Tree::display(){
        cout << val << endl;
}
Tree* Tree::findMax(Tree* first){
    while(first->right!=NULL){
        first=first->right;
    }
    return first;
}
void Tree::addElement(Tree* first){
    int x;
    Tree* help = first;
    cout << "Value:" << endl;
    cin >> x;
        while(help){
        if(x == help->val){                         //Sprawdzenie czy element który chcemy dodac, ju¿ jest w drzewie
            cout << "Podany element juz istnieje\n";
            return;
        }else if(x > help->val){
            help = help->right;
        }else if(x < help->val){
            help = help->left;
        }
    }
    help = first;
    Tree* newElement = new Tree;        //Dodawanie nowego elementu,ustawienie elemntu na odpowiednim miejscu w drzewie ,ustawienie wskaŸników prev, right, left
    newElement->val = x;
    while(help->right || help->left){
        if(x > help->val){
            if(help->right == NULL){
                break;
            }
        help=help->right;
    }else if(x<help->val){
            if(help->left == NULL){
                break;
            }
        help=help->left;
        }
    }
    if(help->val < x ){
        help->right = newElement;
    }else if(help->val > x){
        help->left = newElement;
        }
    newElement->right = NULL;
    newElement->left = NULL;
    newElement->prev = help;
}

Tree* Tree::lookFor(Tree* first, int x){
    Tree* help = first;
    while(help){
        if(x == help->val){                 //Wyszukiwanie  elementu w drzewie
            return help;

        }else if(x > help->val){
            help = help->right;
        }else if(x < help->val){
            help = help->left;
        }
    }
    cout << "Nie ma takiego elemntu" << endl;
    return NULL;
}

Tree* Tree::delElement(Tree* first, int val){
     if(first==NULL) return first;
    else if(val<first->val)
        first->left = delElement(first->left, val);
    else if (val> first->val)
        first->right = delElement(first->right, val);
    else
    {
        //No child
        if(first->right == NULL && first->left == NULL)
        {
            delete first;
            first = NULL;
        }
        //One child
        else if(first->right == NULL)
        {
            Tree* temp = first;
            first= first->left;
            delete temp;
        }
        else if(first->left == NULL)
        {
            Tree* temp = first;
            first= first->right;
            delete temp;
        }
        //two child
        else
        {
            Tree* temp = findMax(first->left);
            first->val = first->val;
            first->left = delElement(first->left, temp->val);
        }
    }
    return first;
}

 Tree::~Tree(){
    delete left;
    delete right;
}
bool Tree::operator== (Tree* root){
        if(root ==NULL && this==NULL){
            return true;
        }else return false;
}

bool Tree::isEqual (Tree* root1, Tree* root2){
    if(root1==root2)
    { return true;}
    if(  (root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL) ){
        return false;
    }
    if(  (root1->val)  !=  (root2->val)   ){
        return false;
    }
     return ( isEqual(root1->left,root2->left) &&
      isEqual(root1->right,root2->right));
}


