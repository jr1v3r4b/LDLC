#ifndef LISTASDOBLEMENLIGADAS_LISTA_H
#define LISTASDOBLEMENLIGADAS_LISTA_H
#include "Nodo.h"

class Lista {

public:
    Nodo *Punta, *Fin;
    Lista();

    void insertarInicio(int);
    void insertarFinal(int);
    void insertarOrdenado(int);
    void mostrar();
    void ordenar();
    void buscarDato(int);
    void sumarListas(Lista* , Lista* );
    void poliPuntoSumarenVector();
    void mostrarMitadLista();
    void reemplazarDato(int dat);

    void eliminarDato(int dat);
};


#endif //LISTASDOBLEMENLIGADAS_LISTA_H
