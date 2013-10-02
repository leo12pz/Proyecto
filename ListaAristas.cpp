/* 
 * File:   ListaAristas.cpp
 * Author: Manuel
 * Modificador: Leo
 * 
 * Modificado on 26 de septiembre de 2013, 10:28 AM
 * Created on 19 de septiembre de 2013, 05:43 AM
 */

#include "ListaAristas.h"

using namespace std;

// Constructor por defecto
template<typename T>
ListaAristas<T>::ListaAristas()
{
    numNodos = 0;
    first = NULL;
}

// Insertar al inicio
template<typename T>
void ListaAristas<T>::add_head(T origen_,T destino_,T peso_)
{
    NodoArista<T> *newNode = new NodoArista<T> (origen_,destino_, peso_);
    NodoArista<T> *tmp = first;

    if (!first) {
        first = newNode;
    } else {
        newNode->next = first;
        first = newNode;

        while (tmp) {
            tmp = tmp->next;
        }
    }
    numNodos++;
}
template<typename T>
 NodoArista<T> ListaAristas<T>::first_node(){
    NodoArista<T> *tmp = first;
    return tmp;
}
// Insertar al final
template<typename T>
void ListaAristas<T>::add_end(T origen_,T destino_,T peso_)
{
    NodoArista<T> *newNode = new NodoArista<T> (origen_,destino_,peso_);
    NodoArista<T> *tmp = first;

    if (!first) {
        first = newNode;
    } else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    numNodos++;
}

// Insertar de manera ordenada
template<typename T>
void ListaAristas<T>::add_sort(T origen_,T destino_, T peso_)
{
    NodoArista<T> *newNode = new NodoArista<T> (origen_,destino_,peso_);
    NodoArista<T> *tmp = first;

    if (!first) {
        first = newNode;
    } else {
        if (first->origen > origen_) {
            newNode->next = first;
            first = newNode;
        } else {
            while ((tmp->next != NULL) && (tmp->next->origen < origen_)) {
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
    }
    numNodos++;
}



// Eliminar todos los nodos
template<typename T>
void ListaAristas<T>::del_all()
{
    first->delete_all();
    first = 0;
}

// Eliminar por data del nodo
template<typename T>
void ListaAristas<T>::del_by_data(T origen_)
{
    NodoArista<T> *tmp1 = first;
    NodoArista<T> *tmp2 = first->next;

    int cont = 0;

    if (first->origen == origen_) {
        first = tmp1->next;
    } else {
        while (tmp2) {
            if (tmp2->origen == origen_) {
                NodoArista<T> *aux_node = tmp2;
                tmp1->next = tmp2->next;
                delete aux_node;
                cont++;
                numNodos--;
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }

    if (cont == 0) {
        cout << "No existe el dato " << endl;
    }
}

// Eliminar por posición del nodo
template<typename T>
void ListaAristas<T>::del_by_position(int pos)
{
    NodoArista<T> *tmp1 = first;
    NodoArista<T> *tmp2 = tmp1->next;

    if (pos < 1 || pos > numNodos) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        first = tmp1->next;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                NodoArista<T> *aux_node = tmp2;
                tmp1->next = tmp2->next;
                delete aux_node;
                numNodos--;
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
}

// Llenar la Lista por teclado
template<typename T>
void ListaAristas<T>::fill_by_user(int dim)
{
    T elem;
    for (int i = 0; i < dim; i++) {
        cout << "Ingresa el elemento " << i + 1 << endl;
        cin >> elem;
        add_end(elem);
    }
}

// Llenar la Lista aleatoriamente para enteros
template<typename T>
void ListaAristas<T>::fill_random(int dim)
{
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        add_end(rand() % 100,rand() % 100,rand() % 100);
    }
}


// Cargar una lista desde un archivo
template<typename T>
void ListaAristas<T>::load_file(string file)
{
    T line;
    ifstream in;
    in.open(file.c_str());

    if (!in.is_open()) {
        cout << "No se puede abrir el archivo: " << file << endl << endl;
    } else {
        while (in >> line) {
            add_end(line);
        }
    }
    in.close();
}

// Imprimir la Lista
template<typename T>
void ListaAristas<T>::print()
{
    NodoArista<T> *temp = first;
    if (!first) {
        cout << "La Lista está vacía " << endl;
    } else {
        int i=0;
        while (temp) {
            cout<<i <<" - ";
            temp->print();
            if (!temp->next) cout << "NULL";
                temp = temp->next;
                i++;
        }
  }
  cout << endl << endl;
}

// Buscar el dato de un nodo
template<typename T>
void ListaAristas<T>::search(T origen_)
{
    NodoArista<T> *temp = first;
    int cont = 1;
    int cont2 = 0;

    while (temp) {
        if (temp->origen == origen_) {
            cout << "El dato se encuentra en la posición: " << cont << endl;
            cont2++;
        }
        temp = temp->next;
        cont++;
    }

    if (cont2 == 0) {
        cout << "No existe el dato " << endl;
    }
    cout << endl << endl;
}

// Ordenar de manera ascendente
template<typename T>
void ListaAristas<T>::sort()
{
    T temp_data;
    NodoArista<T> *aux_node = first;
    NodoArista<T> *temp = aux_node;

    while (aux_node) {
        temp = aux_node;

        while (temp->next) {
            temp = temp->next;

            if (aux_node->origen > temp->origen) {
                temp_data = aux_node->origen;
                aux_node->origen = temp->origen;
                temp->origen = temp_data;
            }
        }

        aux_node = aux_node->next;
    }
}

// Guardar una lista en un archivo
template<typename T>
void ListaAristas<T>::save_file(string file)
{
    NodoArista<T> *temp = first;
    ofstream out;
    out.open(file.c_str());

    if (!out.is_open()) {
        cout << "No se puede guardar el archivo " << endl;
    } else {
        while (temp) {
            out << temp->origen;
            out << " ";
            temp = temp->next;
        }
    }
    out.close();
}

template<typename T>
ListaAristas<T>::~ListaAristas() {}



