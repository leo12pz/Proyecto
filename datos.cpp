/* 
 * File:   datos.cpp
 * Author: leo
 * 
 * Created on 18 de septiembre de 2013, 09:11 PM
 */

#include "datos.h"

/*Constructor de la clase, recibe como parametro el nombre del archivo sobre
 el cual se va a trabajar*/
datos::datos(string archivo,int num){
    this->tamano=num;
    read_File(archivo);
}

/*Este metodo retorna un arreglo de string, con los diferente atributos que
 hubiesen en la linea leida*/
void datos::insert_Data(string cadena){
    int i = 0, j = 0;
    string datos[tamano];
    string tmp;
    while (i < cadena.length()) {
        if (cadena[i] != '\t' and cadena[i] != '\n') {
            tmp += cadena[i];
        }else{
            datos[j] = tmp;
            tmp = "";
            j++;
        }
        
        i++;
    }
    datos[j]= tmp;
    if(tamano == 4){
        list1.insert_end(atoi(datos[0].c_str()),datos[1],datos[2],datos[3]);
    }
    else{
        list2.add_head(atoi(datos[0].c_str()),atoi(datos[1].c_str()),atoi(datos[2].c_str()));
    }
    
}

/*Se encarga de abrir el archivo para lectura y de llamar linea por linea a la 
 funcion insert, para que cada linea leida sea parseada e insertada en un nuevo
 arregglo*/
void datos::read_File(string nombre) {
    TextFile archivo(nombre, openForRead);
    int linea;
    string cadena;

    while (!archivo.isEOF()){
        archivo.readLine(cadena);
        if (cadena != "") {
            insert_Data(cadena);
        }
    }
    cout<<"*****************************"<<endl;
    list1.print();

}