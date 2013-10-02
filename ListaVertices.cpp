/* 
 * File:   main.cpp
 * Author: Manuel Mora
 *
 * Created on 19 de septiembre de 2013, 05:43 AM
 */

#include "ListaVertices.h"

using namespace std;

// Constructor por defecto
template<typename T>
ListaVertices<T>::ListaVertices()
{
    num_nodos = 0;
    first = NULL;
    
}

// Insertar al inicio
template<typename T>
void ListaVertices<T>::insert_head(T codigo_, string provincia_,string canton_,string distrito_)
{
    NodoVertice<T> *new_node = new NodoVertice<T> (codigo_ ,provincia_, canton_, distrito_);
    NodoVertice<T> *temp = first;

    if (!first) {
        first = new_node;
    } else {
        new_node->next = first;
        first = new_node;

        while (temp) {
            temp = temp->next;
        }
    }
    num_nodos++;
}

// Insertar al final
template<typename T>
void ListaVertices<T>::insert_end(T codigo_, string provincia_,string canton_,string distrito_)
{
    NodoVertice<T> *new_node = new NodoVertice<T> (codigo_,provincia_, canton_,distrito_);
    NodoVertice<T> *temp = first;

    if (!first) {
        first = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    num_nodos++;
}

// Insertar de manera ordenada
template<typename T>
void ListaVertices<T>::insert_sort(T codigo_, string provincia_,string canton_,string distrito_)
{
    NodoVertice<T> *new_node = new NodoVertice<T> (codigo_,provincia_, canton_,distrito_);
    NodoVertice<T> *temp = first;

    if (!first) {
        first = new_node;
    } else {
        if (first->codigo > codigo_) {
            new_node->next = first;
            first = new_node;
        } else {
            while ((temp->next != NULL) && (temp->next->codigo < codigo_)) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    num_nodos++;
}


// Eliminar todos los nodos
template<typename T>
void ListaVertices<T>::del_list()
{
    first->delete_all();
    first = 0;
}

// Eliminar por data del nodo
template<typename T>
 NodoVertice<T> ListaVertices<T>::first_node(){
    NodoVertice<T> *temp = first;
    return *temp;
}
template<typename T>
void ListaVertices<T>::del_by_data(T codigo_)
{
    NodoVertice<T> *temp = first;
    NodoVertice<T> *temp1 = first->next;

    int cont = 0;

    if (first->codigo == codigo_) {
        first = temp->next;
    } else {
        while (temp1) {
            if (temp1->codigo == codigo_) {
                NodoVertice<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                cont++;
                num_nodos--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }

    if (cont == 0) {
        cout << "No existe el dato " << endl;
    }
}

// Eliminar por posición del nodo
template<typename T>
void ListaVertices<T>::del_by_position(int pos)
{
    NodoVertice<T> *temp = first;
    NodoVertice<T> *temp1 = temp->next;

    if (pos < 1 || pos > num_nodos) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        first = temp->next;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                NodoVertice<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                num_nodos--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}

// Llenar la Lista por teclado
template<typename T>
void ListaVertices<T>::fill_by_user(int dim)
{
    T ele;
    for (int i = 0; i < dim; i++) {
        cout << "Ingresa el elemento " << i + 1 << endl;
        cin >> ele;
        insert_end(ele);
    }
}

// Llenar la Lista aleatoriamente para enteros
template<typename T>
void ListaVertices<T>::fill_random(int dim)
{
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        insert_end(rand() % 100,"San Jose","Perez Zeledon","San Isidro");
    }
}


// Cargar una lista desde un archivo
template<typename T>
void ListaVertices <T>::load_file(string file)
{
    T line;
    ifstream in;
    in.open(file.c_str());

    if (!in.is_open()) {
        cout << "No se puede abrir el archivo: " << file << endl << endl;
    } else {
        while (in >> line) {
            insert_end(line);
        }
    }
    in.close();
}

// Imprimir la Lista
template<typename T>
void ListaVertices<T>::print()
{
    NodoVertice<T> *temp = first;
    if (!first) {
        cout << "La Lista esta vacia " << endl;
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
void ListaVertices<T>::search(T codigo_)
{
    NodoVertice<T> *temp = first;
    int cont = 1;
    int cont2 = 0;

    while (temp) {
        if (temp->codigo == codigo_) {
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



// Guardar una lista en un archivo
template<typename T>
void ListaVertices<T>::save_file(string file)
{
    NodoVertice <T> *temp = first;
    ofstream out;
    out.open(file.c_str());

    if (!out.is_open()) {
        cout << "No se puede guardar el archivo " << endl;
    } else {
        while (temp) {
            out << temp->codigo;
            out << " ";
            temp = temp->next;
        }
    }
    out.close();
}
//    public void DijkstraConColaPrioridad(int inicial) {
//        ResetVisitado();  //Inicializa todos los nodos como no visitados
//        int distancia[] = new int[100000];
//        int inicio = 0;
//        NodoVertice1 nodoInicial = buscarVertice(inicial);
//        nodoInicial.distancia = 0;
//        colaPrioridad.aCola(nodoInicial.dato);
//        NodoArista aristax = nodoInicial.arista.primero;
//        while (colaPrioridad.size > 0) {
//            colaPrioridad.eliminaMenor((colaPrioridad.menor()));
//            if (nodoInicial.visitado == true && colaPrioridad.size > 0) {
//                if (colaPrioridad.menor() == null) {
//                    nodoInicial = primero;
//                }
//                if (colaPrioridad.menor() != null) {
//                    nodoInicial = buscarVertice(colaPrioridad.menor().dato);
//                    colaPrioridad.eliminaMenor((colaPrioridad.menor()));
//                }
//
//            }
//
//            aristax = nodoInicial.arista.primero;
//
//            while (aristax != null) {
//
//                int w = aristax.peso;
//                if (buscarVertice(aristax.vertice) != null && buscarVertice(aristax.vertice).visitado != true) {
//                    relajacion(nodoInicial, buscarVertice(aristax.vertice), w);
//
//                }
//                aristax = aristax.next;
//
//
//            }
//
//            buscarVertice(nodoInicial.dato).visitado = true;
//            nodoInicial.visitado = true;
//            if (colaPrioridad.menor() == null) {
//                nodoInicial = primero;
//            } else {
//                nodoInicial = buscarVertice(colaPrioridad.menor().dato);
//            }
//
//
//        }
//
//    }
//    
//    //this methoc checks if the new distance is smaller than the actual
//    public void relajacion(NodoVertice1 actual2, NodoVertice1 adyacente, int peso) {
//        if (actual2.distancia + peso < adyacente.distancia) {
//            adyacente.distancia = actual2.distancia + peso;
//            System.out.println("La distancia del nodo adyacente " + adyacente.dato + " es : " + adyacente.distancia);
//            colaPrioridad.aCola(adyacente.dato);
//
//            camino[indiceCamino] = actual2.dato;
//            adyacente.caminoCorto[0] = actual2.dato;
//            buscarVertice(adyacente.dato).caminoCorto[0] = actual2.dato;
//            indiceCamino += 1;
//
//            colaPrioridad.Ultimo.distancia = actual2.distancia + peso;;
//            buscarVertice(adyacente.dato).distancia = actual2.distancia + peso;
//
//        }
//
//
//    }
template<typename T>
ListaVertices <T>::~ListaVertices() {}
