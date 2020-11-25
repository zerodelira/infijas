#include <iostream>
#include<cstdlib>
#include<stdio.h>
#include<string.h>

#include "Pila.h"
using namespace std;
int main()
{
    Pila pila;
    string palabra, post;
    Pila beta;

   // cout << encabezado();
    cout << "ingrese una expresion" << endl;
    cin >> palabra;
    post = palabra;
    post=pila.balanceoSimbolos(palabra, post);
    cout << palabra << endl;
    cout << post << endl;
    pila.imprimir();
   
}
