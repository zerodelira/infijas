#include <iostream>
#include "NodoEntero.h"

using namespace std;

NodoEntero::NodoEntero(char dato) {
    this->dato = dato;
    this->siguiente = nullptr;//NULL 
}

NodoEntero::NodoEntero(const NodoEntero& orig) {
}

NodoEntero::~NodoEntero() {
}

char NodoEntero::getDato(){
    return dato;
}

void NodoEntero::setDato(char dato){
    this->dato = dato;
}
   
NodoEntero * NodoEntero::getSiguiente(){
    return siguiente;
}

void NodoEntero::setSiguiente(NodoEntero *siguiente){
    this->siguiente = siguiente;
}

