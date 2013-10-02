/* 
 * File:   main.cpp
 * Author: Manuel Mora
 *
 * Created on 19 de septiembre de 2013, 05:43 AM
 */

#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "NodoArista.h"
#include "NodoArista.cpp"

using namespace std;

template <class T>

class ListaAristas
{
    public:
        ListaAristas();
        ~ListaAristas();

        void add_head(T,T,T);
        void add_end(T,T,T);
        void add_sort(T,T,T);
        void del_all();
        void del_by_data(T);
        void del_by_position(int);
        void fill_by_user(int);
        void fill_random(int);
        void load_file(string);
        void print();
        void save_file(string);
        NodoArista <T> first_node();
        void search(T);
        void sort();

        private:
        NodoArista<T> *first;
        int numNodos;
};

#endif // LIST_H



