#include <iostream>
#include "Lista.h"

using namespace std;

Lista::Lista(){
    Punta = nullptr;
    Fin = nullptr;
}

void Lista::insertarInicio(int dat){
    Nodo* newNode = new Nodo(dat);

    if(Punta == nullptr) {
        Punta = newNode;
        Fin = newNode;
        newNode->setLigaSig(Punta);
        newNode->setLigaAnt(Punta);
    }
    else{
        newNode->setLigaSig(Punta);
        Punta->setLigaAnt(newNode);
        Fin->setLigaSig(newNode);
        newNode->setLigaAnt(Fin);
        Punta = newNode;
    }
}

void Lista::insertarFinal(int dat) {

    Nodo* newNodo = new Nodo(dat);

    if (Punta == nullptr)
    {
        Punta = newNodo;
        Fin = newNodo;
        newNodo->setLigaSig(Punta);
        newNodo->setLigaAnt(Punta);
    }
    else
    {
        Fin->setLigaSig(newNodo);
        newNodo->setLigaSig(Punta);
        newNodo->setLigaAnt(Fin);
        Punta->setLigaAnt(newNodo);
        Fin = newNodo;
    }
}

void Lista::insertarOrdenado(int dat) {
    Nodo* newNodo = new Nodo(dat);
    Nodo* p;
    Nodo* a;

    if (Punta == nullptr)
    {
        Punta = newNodo;
        Fin = newNodo;
        newNodo->setLigaSig(Punta);
        newNodo->setLigaAnt(Punta);
    }
    else
    {
        p = Punta;
        a = Punta;
        while (a->getLigaSig() != Punta && newNodo->getDato() > p->getDato()){
            a = p;
            p = p->getLigaSig();
        }
        if (a == Punta)
        {
            p->setLigaAnt(newNodo);
            newNodo->setLigaSig(p);
            newNodo->setLigaAnt(Fin);
            Fin->setLigaSig(newNodo);
            Punta = newNodo;
        }
        else
        {
            a->setLigaSig(newNodo);
            newNodo->setLigaAnt(a);
            newNodo->setLigaSig(p);
            p->setLigaAnt(newNodo);
            Fin = newNodo;
        }
    }
}

void Lista::mostrar() {
    Nodo *p = Punta;
    do {
        cout << "|" << p->getDato() << "|->";
        p = p->getLigaSig();
    } while (p != Punta);
}

void Lista::ordenar() {

    Nodo* p = Punta;
    Nodo* q;
    int aux;

    while(p->getLigaSig() != Punta)
    {
        q =  p->getLigaSig();
        while(q != Punta)
        {
            if(p->getDato() > q->getDato())
            {
                aux = q->getDato();
                q->setDato(p->getDato());
                p->setDato(aux);
            }
            q = q->getLigaSig();
        }
        p = p->getLigaSig();
    }
}

void Lista::buscarDato(int dat) {

    Nodo* aux = nullptr;
    Nodo* p = Punta;

    do{
        if (p->getDato() == dat)
        {
            aux = p;
            cout << " el dato se encontró el la/las posicion: " << " | ";
            cout << aux;
        }
        p = p->getLigaSig();
    }while(p != Punta);

    if(aux == nullptr)
        cout << " no se encotró el dato en ninguna posición";

    cin.get();
}

void Lista::reemplazarDato(int dat) {

    Nodo* aux = nullptr;
    Nodo* p = Punta;
    bool sw = false;
    int dato2;

    do{
        if (p->getDato() == dat)
        {
            aux = p;
            cout << " el dato se encontró el la/las posicion: \n " << " | ";
            cout << aux;
            cout << " ingrese el dato que lo va a reemplazar: \n ";
            cin >> dato2;
            p->setDato(dato2);
            cout << " Dato reemplazado \n ";
            sw = true;
        }
        p = p->getLigaSig();
    }while(p != Punta);

    if(sw == false)
        cout << " no se encontró el dato en ninguna posición";

    cin.get();
}

void Lista::eliminarDato(int dat) {
    Nodo *p = Punta;
    Nodo *q = p->getLigaSig();
    Nodo *z;

    if (dat == Punta->getDato()) {
        q->setLigaAnt(Fin);
        Fin->setLigaSig(q);
        Punta = q;
        if(Punta->getLigaSig() == Punta){
            Punta = nullptr;
            cout << "la lista quedó vacía ";
        }
    } else {
        cout << Fin->getDato();
        cin.get();
        if (dat == Fin->getDato()) {
            cout << " aqui llego";
            Fin = Fin->getLigaAnt();
            Fin->setLigaSig(Punta);
            Punta->setLigaAnt(Fin);
        } else {
            do {
                q = q->getLigaSig();
                p = p->getLigaAnt();

                if (q->getDato() == dat) {
                    z = q->getLigaSig();
                    p->setLigaSig(z);
                    z->setLigaAnt(p);
                }
            } while (p != Punta);
        }
    }
}

void Lista::sumarListas(Lista* lista1, Lista*  lista2) {
    Punta = nullptr;
    Nodo* p = lista1->Punta;
    Nodo* q = lista2->Punta;
    bool sw = false;

     do{
        if (sw == false || p != lista1->Punta && q != lista2->Punta) {
            insertarFinal(p->getDato() + q->getDato());
            p = p->getLigaSig();
            q = q->getLigaSig();
            sw = true;
        }
        else {
            if (p != lista1->Punta) {
                insertarFinal(p->getDato());
                p = p->getLigaSig();
            }
            if (q != lista2->Punta) {
                insertarFinal(q->getDato());
                q = q->getLigaSig();
            }
        }
     }while (p != lista1->Punta || q != lista2->Punta);
}


void Lista::poliPuntoSumarenVector() {
    Nodo *p = Punta;
    int suma, vec[3];
    cout << " escriba 3 numeros para llenar el vector";

    for (int i = 0; i < 3; ++i) {
        cout <<"numerous... :";
        cin >> vec[i];
    }
    for (int i = 0; i < 3; ++i) {
        suma = 0;
        p = Punta;
        do {
            suma = suma + vec[i] * p->getDato();
            p=p->getLigaSig();
        } while (p != Punta);
        insertarFinal(suma);
        cout << " la Lista 2 con la suma distrutiva es : ";
        mostrar();
    }


}

void Lista::mostrarMitadLista() {
    Nodo* p = Punta;
    Nodo* q = Fin;

    while (p != q || p->getLigaSig() != q)
    {
        p = p->getLigaSig();
        q = q->getLigaAnt();
    }

    if(p = q )
    {
        cout << "la lista es impar y el dato de la mitad de la lista es: ";
        cout << p->getDato();
    }
    else
    {
        cout << "la lista es par y los datos de la mitad son: ";
        cout << p->getDato();
        cout << q->getDato();
    }
}
