#include "NodoEntero.h"
#include <iostream>
#include <ctype.h>
#include <math.h>
#ifndef PILA_H
#define PILA_H
using namespace std;

class Pila {
public:
    Pila();
    Pila(const Pila& orig);
    virtual ~Pila();
    bool isEmpty();
    void push(char dato);
    char pop();
    char peek();
    // Métodos complementarios
    void imprimir();
    int tamanio();
    char fondo();
    void ordenEntrada();
    void agregarPorPosicion(int posicion, char dat);
    void agregarFondo(char num);
    string balanceoSimbolos(string palabra, string post)
    {
        string copia;
        char aux;
        char letra;
        int cPost=0, cont=0;
        for (int i = 0; i <= palabra.size(); i++)
        {
            letra = palabra[i];
            // cout << "melda: " << post << endl;
            if (isdigit(letra))
            {
              cout << "es un digito" << endl;
              cout << letra << endl;
                post[cPost]=letra;
                cPost++;
            }
            else
            {
                if (this->importanciaExpresion(letra)==-2)
                {
                    cont++;
              
                    while (!this->isEmpty())
                    {
                        aux = this->pop();
                        cout << "aux= " << aux << endl;
                        if (this->importanciaExpresion(aux) == 5)
                        {
                            cont++;
                        
                        }
                        else
                        {
                        
                            post[cPost] = aux;
                            cPost++;
                        }
                    }
                }
                else
                {
                    if (this->isEmpty())
                    {
                      
                        post[cPost] = letra;
                        cPost++;
                    }
                    else
                    {
                        if (this->importanciaExpresion(letra) <= this->importanciaPila())
                        {
                            while (this->importanciaExpresion(letra) <= this->importanciaPila())
                            {
                                if (this->tamanio()==1)
                                {
                                   
                                    this->push(letra);
                                    aux = this->fondo();
                                    post[cPost] = aux;
                                    cPost++;
                                    break;
                                }
                                else
                                {
                                 
                                    aux = this->pop();
                                    post[cPost] = aux;
                                    cPost++;
                                 
                                }    
                            }
                            this->push(letra);
                        }
                        else if (this->importanciaExpresion(palabra[i]) > this->importanciaPila())
                        {
                            this->push(letra);
                        }
                    }
                }
            }
        }  
        copia=post.substr(0, cPost - 1);
        for (int i = 0; i <= copia.size(); i++)
        {
            aux = post[i];
            this->agregarFondo(aux);
        }
        this->fondo();
        return post;
    }
    int importanciaPila()
    {
        if (this->peek() == '^')
        {
            return 3;
        }
        else if (this->peek() == '*' || this->peek() == '/')
        {
            return 2;
        }
        else if (this->peek() == '+' || this->peek() == '-')
        {
            return 1;
        }
        else if (this->peek() == '(')
        {
            return -1;
        }
        else if (this->peek() == ')')
        {
            return -2;
        }
    }
    int importanciaExpresion(char letra)
    {
        if (letra == '^')
        {
            return 4;
        }
        else if (letra == '*' || letra == '/')
        {
            return 2;
        }
        else if (letra == '+' || letra == '-')
        {
            return 1;
        }
        else if (letra == '(')
        {
            return 5;
        }
        else if (letra == ')')
        {
            return -2;
        }
    }
    void resover() {
        Pila aux;
        char pF;
        for (int i = 0; i <= this->tamanio() ; i++)
        {
            pF = this->fondo();
            if (isdigit(pF))
            {
                aux.push(pF);
            }
            else
            {
                if (this->importanciaExpresion(pF)==4)
                {
                    
                }
            }
        }
    
    }
private:
    NodoEntero *top;

};

#endif /* PILA_H */

