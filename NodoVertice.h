/* 
 * File:   NodoVertice.h
 * Author: Manuel Mora
 *
 * Created on 19 de septiembre de 2013, 03:50 PM
 */

#ifndef NODOVERTICE_H
#define	NODOVERTICE_H

#include <iostream>
#include "ListaAristas.h"

using namespace std;

template <class T>

class NodoVertice
{
    public:
        NodoVertice();
        NodoVertice(T,string,string,string);
        ~NodoVertice();

        NodoVertice *next;
        T codigo;
        string provincia;
        string canton;
        string distrito;
        ListaAristas<int> *aristas = new ListaAristas<int>();

        void delete_all();
        void print();
};



#endif	/* NODOVERTICE_H */
