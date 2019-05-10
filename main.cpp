#include "tree.h"
#include "function.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main (){
    Tree* first = new Tree;
    first->initialize();
    Tree* y = new Tree;
    char x;
    while (x != '5'){
        cout << "1.Dodaj\n2.Wyswietl\n3.Wyszukaj\n5.Wyjdz" << endl;
        cin >> x;

        switch(x){
    case '1':
        cleanScr();
        first->addElement(first);
        break;
    case '2':
        break;
    case '3':
        cleanScr();
        y = first->lookFor(first);
        cleanScr();
        if(y!=NULL){
            cout << "Znaleziony element: ";
            y->display();
            cout << endl;
        }else if(y==NULL){
            cout << "Nie ma takiego elementu" << endl;
        }
        break;
    default:
        break;}
    }
    return 0;
 }

