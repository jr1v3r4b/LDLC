#include <iostream>
#include "Lista.h"

using namespace std;

void Menu()
{
    cout << "\n \t Lista doblemente ligada circular \n\n";
    cout << "1. Insertar al Inicio. " << endl;
    cout << "2. Insertar al Final .  " << endl;
    cout << "3. Insertar al Ordenado. " << endl;
    cout << "4. mostrar la Lista. " << endl;
    cout << "5. Ordenar la lista " << endl;
    cout << "6. Buscar un Dato  " << endl;
    cout << "7. En esta opcion creamos otra lista y la llamaremos L2  " << endl;
    cout << "8. mostrar la otra lista " << endl;
    cout << "9. sumar listas "<< endl;
    cout << "10. Buscar y Reemplazar un dato " << endl;
    cout << "11. Eliminar un dato " << endl;
    cout << "0. Salir"<< endl;

    cout << "Ingresar Opcion: " << endl;
}

int main() {

    int opc=0, dato=0;
    //instancia

    Lista *L1 = new Lista();
    Lista *L2 = new Lista();
    Lista *L3 = new Lista();
    do
    {
        Menu();
        cin >> opc;

        switch (opc)
        {
            case 1:
                cout << "\n ingrese un nuevo dato:";
                cin >> dato;
                L1->insertarInicio(dato);
                break;

            case 2:
                cout << "\n ingresa un nuevo dato: ";
                cin >> dato;
                L1->insertarFinal(dato);
                break;

            case 3:
                L1->ordenar();
                cout << "\n ingrese un nuevo dato:";
                cin >> dato;
                L1->insertarOrdenado(dato);
                break;

            case 4:
                if (L1->Punta != nullptr)
                    L1->mostrar();
                else
                    cout << "\n Lista Vacia...";
                cin.get();
                break;

            case 5:
                L1->ordenar();
                cout << "\n Se acaba de ordenar la lista ";
                cin.get();
                break;

            case 6:
                cout << "\n ingrese el dato a buscar: ";
                cin >> dato;
                L1->buscarDato(dato);
                break;
            case 7:
                cout << "\n ingrese el dato a agregar al final en la nueva lista: ";
                cin >> dato;
                L2->insertarFinal(dato);
                break;

            case 8:
                if (L2->Punta != nullptr)
                   L2->mostrar();
                else
                cout << "\n Lista Vacia...";
                cin.get();
                break;

            case 9:
                cout << "\n Se acaba de sumar lista 1 y lista 2 ";
                L3->sumarListas(L1,L2);
                cout << "**A continuacion  ... *** \n Lista #1: " ;
                L1->mostrar();
                cout << "\n Lista #2: " ;
                L2->mostrar();
                cout << "\n Lista #3 con las sumas: " ;
                L3->mostrar();
                cin.get();
                break;
            case 10:
                cout << "\n ingrese el dato que quiere buscar para reemplazar :";
                cin >> dato;
                L1->reemplazarDato(dato);
                break;
            case 11:
                cout << "\n ingrese un dato a eliminar (elimina el nodo):";
                cin >> dato;
                L1->eliminarDato(dato);
                break;
            default:
                cout<<" \n Opcion incorrecta... ";
                cin.get();
                break;
        }

        cout << endl << endl;
        cin.get();

    }while(opc > 0);

    return 0;
}
