/* 
 * File:   datos.h
 * Author: leo
 *
 * Created on 18 de septiembre de 2013, 09:11 PM
 */

#ifndef DATOS_H
#define	DATOS_H
#include "TextFile.h"
#include "ListaVertices.h"
#include "ListaAristas.h"
#include "ListaAristas.cpp"
#include "ListaVertices.cpp"
#include <cstring>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class datos {
public:
    datos(string,int);
    datos(const datos& orig);
    
//    virtual ~datos();
private:
    int tamano;
    void read_File(string);
    void insert_Data(string);
    ListaVertices <int> list1;
    ListaAristas <int> list2;
};

#endif	/* DATOS_H */

