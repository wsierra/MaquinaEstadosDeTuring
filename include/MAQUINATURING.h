#include <iostream>

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

#ifndef MAQUINATURING_H
#define MAQUINATURING_H

#define MAX 30

using namespace std;

class MAQUINATURING
{
    public:
        MAQUINATURING();
        void cargar_regla(string);
        bool validar_p_p(string);
        bool validar(string);
        void mostrar_matriz(void);
        void reiniciar(void);
    private:
        char reglas[MAX][MAX];
        int cantreglas;
};

MAQUINATURING :: MAQUINATURING()
{
    cantreglas=0;
}
void MAQUINATURING::reiniciar(void)
{
    cantreglas = 0;
}

void MAQUINATURING :: cargar_regla(string cadena)
{
    reglas[cantreglas][0] = cadena[2];
    reglas[cantreglas][1] = cadena[4];
    reglas[cantreglas][2] = cadena[6];
    reglas[cantreglas][3] = cadena[8];
    reglas[cantreglas][4] = cadena[10];

    cantreglas++;
}

void MAQUINATURING :: mostrar_matriz(void)
{
    int i,j;
    cout << "E.Inicial // Lectura // Escritura // Mov. // E.Final" << endl;
    for(i=0; i<cantreglas; i++)
    {
        for(j=0; j<5; j++)
            cout << reglas [i][j] << "  ";
        cout << endl;
    }
}

bool MAQUINATURING:: validar(string cadena)
{
    int k=0,j,i;
    char es='0', ei, c;
    bool aux;
    bool salir = false;
    while(!salir)
    {
        for(j=0; j<cantreglas && !aux; j++)
            if( reglas[j][0] == es )
            {
                ei=es;
                j--;
                aux=true;
            }
        aux = false;
        for(i=j; reglas[i][0] == ei && !aux; i++)
        {
            if( reglas[i][1] == cadena[k] )
            {
                cadena[k] = reglas[i][2];
                if( reglas[i][3] == '>' )
                    k++;
                if( reglas[i][3] == '<' )
                    k--;
                es = reglas[i][4];
                aux = true;
                if( es == 's' || es == 'S' )
                    salir = true;
            }
        }
        c = getch();
    }

    return salir;
}

//bool MAQUINATURING :: validar_p_p(string cadena)
//{
//    while(!salir)
//    {
//
//        for(j=0; j<cantreglas && !aux; j++)
//            if( reglas[j][0] == es )
//            {
//                ei=es;
//                j--;
//                aux=true;
//            }
//        aux = false;
//        for(i=j; reglas[i][0] == ei && !aux; i++)
//        {
//            if( reglas[i][1] == cadena[k] )
//            {
//                cadena[k] = reglas[i][2];
//                if( reglas[i][3] == '>' )
//                    k++;
//                if( reglas[i][3] == '<' )
//                    k--;
//                es = reglas[i][4];
//                aux = true;
//                if( es == 's' || es == 'S' )
//                    salir = true;
//            }
//
//        }
//}
#endif // MAQUINATURING_H
