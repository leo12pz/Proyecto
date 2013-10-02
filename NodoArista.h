/* 
 * File:   main.cpp
 * Author: Manuel Mora
 *
 * Created on 19 de septiembre de 2013, 05:43 AM
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T>

class NodoArista
{
    public:
        NodoArista();
        NodoArista(T,T,T);
        ~NodoArista();

        NodoArista *next;
        T origen;
        T destino;
        T peso;
        

        void delete_all();
        void print();
};

#endif // NODE_H



