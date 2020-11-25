#include "Pila.h"
#include <ctype.h>
#include <iostream>
using namespace std;

Pila::Pila() {
    this->top = nullptr;
}

Pila::Pila(const Pila& orig) {
    this->top = orig.top;
}

Pila::~Pila() {
}

bool Pila::isEmpty() {
    return this->top == nullptr;
}

void Pila::push(char dato) {
    NodoEntero *nuevoNodo = new NodoEntero(dato);
    nuevoNodo->setSiguiente(this->top);
    this->top = nuevoNodo;
}

char Pila::pop() {
    if (this->isEmpty()) {
        cout << "Pila vacia" << endl;
        exit(1);
    }
    NodoEntero *aux = this->top;
    this->top = aux->getSiguiente();
    char dato = aux->getDato();
    delete(aux);
    return dato;
}

char Pila::peek(){
    if (this->isEmpty()) {
        cout << "Pila vacia" << endl;
        exit(1);
    }
    return this->top->getDato();

}

// Método complementario
void Pila::imprimir(){
    Pila aux;
    while(!this->isEmpty()){
       char dato = this->pop();
        cout<<dato<<", ";
        aux.push(dato);    
    }
    while(!aux.isEmpty()){
        this->push(aux.pop());
    }
}

int Pila::tamanio()
{
    Pila aux;
    int cont=0, alpha=0;
   char dato;
    while (!this->isEmpty())
    {
        dato = this->pop();
        aux.push(dato);
        cont++;
    }
    while (!aux.isEmpty()) {
        this->push(aux.pop());
    }
    return cont;
}

char Pila::fondo()
{
    Pila aux;
    char alpha = 0;
    char dato;
    int cont = 0;
    while (!this->isEmpty())
    {
        dato = this->pop();
        aux.push(dato);
        cont++;
    }
    alpha = dato;
    while (!aux.isEmpty()) {
        if (cont==1)
        {
            break;
        }
        this->push(aux.pop());
        cont--;
    }
    return alpha;
}

void Pila::ordenEntrada()
{
    Pila aux;
    int cont = 0, alpha = 0;
    char dato;
    while (!this->isEmpty())
    {
        dato = this->pop();
        aux.push(dato);
        cont++;
    }
    cont = 1;
    while (!aux.isEmpty()) {
        dato = aux.pop();
        cout << "se agrego en el orden: " << cont << endl;
        cout << "valor: " << dato << endl;
        cont++;
        this->push(dato);
    }
}

void Pila::agregarPorPosicion(int posicion, char dat)
{
    if (posicion > this->tamanio()) {
        cout << "La posicion aun no existe!!" << endl;
    }
    else if (posicion>1 && posicion<this->tamanio())
    {
        Pila aux;
        Pila aux2;
        int  tam;
        char dato;
        for (int i = 0; i < posicion - 1; i++)
        {
            dato = this->pop();
            aux.push(dato);
        }
        tam = this->tamanio();
        for (int i = 0; i < tam; i++)
        {
            dato = this->pop();
            aux2.push(dato);
        }
        aux.push(dat);
        while (!aux2.isEmpty()) {
            this->push(aux2.pop());
        }
        while (!aux.isEmpty()) {
            this->push(aux.pop());
        }
    }
    else if(posicion==1)
    {
        this->agregarFondo(dat);
    }
    else if(posicion<1)
    {
        cout << "La posicion es menor a 1 el elemento se agregara en la primera posicion" << endl;
        this->agregarFondo(dat);
    }
}

void Pila::agregarFondo(char num)
{
    Pila aux;
    int alpha = 0;
    char dato;
    while (!this->isEmpty())
    {
        dato = this->pop();
        aux.push(dato);
    }
    aux.push(num);
    while (!aux.isEmpty()) {
        this->push(aux.pop());
    }
}


