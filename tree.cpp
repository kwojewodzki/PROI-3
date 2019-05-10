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

Tree* Tree::lookFor(Tree* first){
    Tree* help = first;
    int x;
    cout << "Podaj szukana wartosc: ";
    cin >> x;
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

void Tree::delElement(Tree* first){
    first=first->lookFor(first);
    Tree* help = first->prev;
    if(first->left != NULL){

    }
    }
