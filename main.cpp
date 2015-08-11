
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include "include\TURING.h"

#define ESC 27

using namespace std;

///Analiza cadenas de izquierda a derecha, cadenas del tipo #xxxxx#
///Si la cadena no es aceptada por la maquina, el programa cuelga
int main()
{
    char c, menu;
    bool salir=false;
    string cadena;

    TURING machine1, machine2;
    ifstream reglas("maquinaturing.txt");
    ifstream reglas2("maquinaturing2.txt");

    do{
        system("cls");
        salir = false;
        cout << "1:Probar ejemplo 1\n"
             << "2:Probar ejemplo 2\n"
             << "ESC:Salir\n" << endl;

        switch(menu = getch()){

            case '1' :
                if(reglas.fail())
                    cerr << "No se pudo abrir el archivo de reglas maquinaTuring.txt..." << endl;
                else
                    while(!reglas.eof()){
                        getline( reglas, cadena);
                        machine1.cargar_regla(cadena);
                    }
                while(!salir){
                    system("cls");
                    cout << "Su matriz de reglas es : ";
                    machine1.mostrar_matriz();
                        cout << "Ingrese una cadena entre NUMERALES: ";
                        cin >> cadena;
                        cout << "Su cadena es: "<<cadena<<endl;
                        if( machine1.validar(cadena) )
                            cout<<"Su cadena pertenece a la maquina" << endl;
                        cout << "Desea ingresar otra cadena?(s|n)" << endl;
                        c = getch();
                        if( c == 'n' || c == 'N' )
                            salir = true;
                }

                machine1.reiniciar();
                break;
            case '2' :

                if(reglas2.fail())
                    cerr << "No se pudo abrir el archivo de reglas maquinaTuring2.txt..." << endl;
                else
                    while(!reglas2.eof()){
                        getline( reglas2, cadena);
                        machine1.cargar_regla(cadena);
                    }
                while(!salir){
                    system("cls");
                    cout << "Su matriz de reglas es : ";
                    machine1.mostrar_matriz();
                    cout << "Ingrese una cadena entre NUMERALES: ";
                    cin >> cadena;
                    cout << "Su cadena es: "<<cadena<<endl;
                        if( machine1.validar(cadena) )
                        cout<<"Su cadena pertenece a la maquina" << endl;
                    cout << "Desea ingresar otra cadena?(s|n)" << endl;
                    c = getch();

                    if(c=='n' || c=='N')
                        salir=true;
                    }
                machine1.reiniciar();
                break;
            }

    }while( menu != ESC );
}































