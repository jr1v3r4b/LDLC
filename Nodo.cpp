#include "Nodo.h"

Nodo::Nodo(int dat) {
    dato = dat;
    ligaAnt = nullptr;
    ligaSig = nullptr;
}

int Nodo::getDato() const {
    return dato;
}
void Nodo::setDato(int dato) {
    Nodo::dato = dato;
}
Nodo *Nodo::getLigaSig() const {
    return ligaSig;
}
void Nodo::setLigaSig(Nodo *ligaSig) {
    Nodo::ligaSig = ligaSig;
}

Nodo *Nodo::getLigaAnt() const {

}
void Nodo::setLigaAnt(Nodo *ligaAnt) {

    Nodo::ligaAnt = ligaAnt;
}
