/* 
 * File:   ListaVertices.h
 * Author: Manuel Mora
 *
 * Created on 19 de septiembre de 2013, 06:17 PM
 */

#ifndef LISTAVERTICES_H
#define	LISTAVERTICES_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "NodoVertice.h"
#include "NodoVertice.cpp"

using namespace std;

template <class T>

class ListaVertices
{
    public:
        ListaVertices();
        ~ListaVertices();

        void insert_head(T,string,string,string);
        void insert_end(T,string,string,string);
        void insert_sort(T,string,string,string);
        void del_list();
        void del_by_data(T);
        void del_by_position(int);
        void fill_by_user(int);
        void fill_random(int);
        void load_file(string);
        void print();
        void save_file(string);
        void search(T);
        NodoVertice <T> first_node();
        private:
        NodoVertice<T> *first;
        int num_nodos;
};

#endif	/* LISTAVERTICES_H */


