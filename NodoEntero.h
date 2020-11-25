#ifndef NODOENTERO_H
#define NODOENTERO_H
using namespace std;
class NodoEntero {
public:
    NodoEntero(char dato);
    NodoEntero(const NodoEntero& orig);
    virtual ~NodoEntero();
    char getDato();
    void setDato(char dato);
    NodoEntero * getSiguiente();
    void setSiguiente(NodoEntero *siguiente);
private:
    char dato;
    NodoEntero *siguiente;
};


#endif /* NODOENTERO_H */

