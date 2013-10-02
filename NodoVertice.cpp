/* 
 * File:   main.cpp
 * Author: Manuel Mora
 *
 * Created on 18 de septiembre de 2013, 03:44 PM
 */
#include "NodoVertice.h"
#include "ListaAristas.h"
// Constructor por defecto
template<typename T>

NodoVertice <T>::NodoVertice()
{
    codigo = NULL;
    provincia=NULL;
    canton=NULL;
    distrito = NULL;
    next = NULL;
    aristas=ListaAristas <int>();   
}

// Constructor por parámetro
template<typename T>
NodoVertice<T>::NodoVertice(T codigo_,string provincia_,string canton_,string distrito_)
{
    codigo = codigo_;
    provincia=provincia_;
    canton=canton_;
    distrito= distrito_;
    next = NULL;
    
    aristas= new ListaAristas <int>();
    
}

// Eliminar todos los Nodos
template<typename T>
void NodoVertice<T>::delete_all()
{
    if (next)
        next->delete_all();
    delete this;
}

// Imprimir un Nodo
template<typename T>
void NodoVertice<T>::print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout <<"Codigo: " << codigo <<"Provincia: " << provincia <<" Canton: " << canton <<" Distrito: " << distrito << " -> ";
}

template<typename T>
NodoVertice<T>::~NodoVertice() {}



