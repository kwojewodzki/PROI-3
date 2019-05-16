#include "tree.h"
#include "merge.h"
#include "function.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main (){
    Tree* first = new Tree;
    Tree* scn = new Tree;
    Merge* newMerge = new Merge;
    int j;
    newMerge->initialize();
    cout << "Podaj pierwsza wartosc do drzewa"<<endl;
    first->initialize();
    cout << "Podaj pierwsza wartosc dla drugiego drzewa " << endl;
    scn->initialize();
    int i;
    Tree* y;
    char x;
    while (x != '7'){
        cout << "1.Dodaj(1)\n2.Usun(1)\n3.Wyszukaj(1)\n4.Dodaj(2)\n5.Usun(2)\n6.Wyszukaj(2)\n7.wyjdz" << endl;
        cin >> x;

        switch(x){
    case '1':
        cleanScr();
        first->addElement(first);
        break;
    case '2':
        cout << "Podaj wartosc ktora chcesz usunac:" << endl;
        cin >> i;
        first->delElement(first, i);
        cleanScr();
        break;
    case '3':
        cleanScr();
        cout << "Podaj szukana wartosc:\n";
        cin >> j;
        y = first->lookFor(first,j);
        cleanScr();
        if(y!=NULL){
            cout << "Znaleziony element: ";
            y->display();
            cout << endl;
        }else if(y==NULL){
            cout << "Nie ma takiego elementu" << endl;
        }
        break;
    case '4':
        cleanScr();
        scn->addElement(scn);
        break;
    case '5':
        cout << "Podaj wartosc ktora chcesz usunac:" << endl;
        cin >> i;
        scn->delElement(scn, i);
        cleanScr();
        break;
    case '6':
        cleanScr();
        cout << "Podaj szukana wartosc:\n";
        cin >> j;
        y = scn->lookFor(scn,j);
        cleanScr();
        if(y!=NULL){
            cout << "Znaleziony element: ";
            y->display();
            cout << endl;
        }else if(y==NULL){
            cout << "Nie ma takiego elementu" << endl;
        }
        break;
    case '8':
        if(first->isEqual(first, scn)){
            cout << "Drzewa sa rowne" << endl;
        }else{
        cout << "Drzewa sie roznia"<<endl;
        }
        break;
    default:
        break;}
    }
    delete first;
    delete scn;
    delete newMerge;
    return 0;
 }

