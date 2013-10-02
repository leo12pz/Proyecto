/* 
 * File:   main.cpp
 * Author: Manuel Mora
 *
 * Created on 19 de septiembre de 2013, 05:43 AM
 */
#include "NodoArista.h"

// Constructor por defecto
template<typename T>

NodoArista<T>::NodoArista()
{
    origen = NULL;
    destino=NULL;
    peso=NULL;
    next = NULL;
}

// Constructor por parámetro
template<typename T>
NodoArista<T>::NodoArista(T data_,T destino_,T peso_)
{
    origen = data_;
    destino=destino_;
    peso=peso_;
    next = NULL;
}

// Eliminar todos los Nodos
template<typename T>
void NodoArista<T>::delete_all()
{
    if (next)
        next->delete_all();
    delete this;
}

// Imprimir un Nodo
template<typename T>
void NodoArista<T>::print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout <<"Origen: " << origen <<" Destino: " << destino <<" Peso: " << peso << " -> ";
}

template<typename T>
NodoArista<T>::~NodoArista() {}

