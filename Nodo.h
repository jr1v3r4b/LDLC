
#ifndef LISTASDOBLEMENLIGADAS_NODO_H
#define LISTASDOBLEMENLIGADAS_NODO_H

class Nodo {
    int dato;
    Nodo *ligaSig, *ligaAnt;
public:
    Nodo();
    Nodo(int);

    Nodo *getLigaAnt() const;
    void setLigaAnt(Nodo *ligaAnt);
    Nodo *getLigaSig() const;
    void setLigaSig(Nodo *ligaSig);
    void setDato(int dato);
    int getDato() const;

};


#endif //LISTASDOBLEMENLIGADAS_NODO_H
