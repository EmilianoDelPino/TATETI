#include <iostream>
#include "rlutil.h"
#include <stdio.h>
#include <time.h>

using namespace std;
//CREADOR: Emiliano Del Pino
// Declaro una Matriz
// asi se recibe una matriz como parametro
char funcion(char tablero[3][3]);
void armo_tableroIni(char tablero [3][3]);
void print_tablero(char tablero [3][3]);
void ingreso_1(char tablero[3][3]);
void ingreso_pc (char tablero[3][3]);
int ganador (char tablero [3][3]);



int main(){
    system ("cls");
    char tablero[3][3], a, N, S;
    cout<<"BIENVENIDOS AL PEOR TUTIFRUTI DE LA HISTORIA!!"<< endl;
    cout<< "By Emi"<<endl<<endl;
    system ("pause");
    system ("cls");
    funcion(tablero); // Asi se llama una funcion y se envia la matriz
    system ("pause");
    cout<<"Quieres volver a jugar?"<<endl;
    cout<<"S/N"<<endl;
    cin>>a;
    if(a==N){
        return 0;
    }
    else{
        return main();
    }

    return 0;

}
/// JUNTO TODAS LAS FUNCIONES PARA LLEVARLO AL MAIN.
char funcion(char tablero[3][3]){
    int i=0, j=2;
    armo_tableroIni(tablero);
    print_tablero(tablero);
    cout << endl << endl;
    while (i < 9 && j==2){
        if (i%2==0){/// = 0 mi turno = 1 turno de la maquina.
            ingreso_1(tablero);
        }
        else{
            ingreso_pc(tablero);
        }
        system("cls");
        print_tablero(tablero);
        j = ganador (tablero);
        i++;

    }
    if (j==0){
        cout << "Felicitaciones!! GANADOR EL CIRCULO!!"<<endl<<endl;
    }
    if (j==1){
        cout << "Felicitaciones!! GANADOR LA CRUZ!!"<<endl<<endl;
    }
    if(i==9){
        cout << "Han empatado!! Intentalo de nuevo!!"<<endl<<endl;
    }
}
/// ASIGNO LOS VALORES DEL TABLERO DE 1 A 9 CON LA MATRIZ.
void armo_tableroIni(char tablero [3][3]){
    int i,j;
    char ini;
    ini='1';
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            tablero[i][j]= ini++;
        }
    }
}
/// INGRESO MANUAL DEL JUGADOR CON X.
void ingreso_1(char tablero[3][3]){
    char pos;
    int i, j, b=0; //utilizo b como bandera.
    while(b==0){
        do{
            cout << "Ingrese una posicion entre 1 y 9 que no este ocupada por X u O: ";
            cin>>pos;
        }while(pos < '1' || pos > '9');
        b = 1;
        switch (pos){
            case '1':{
                i=0;
                j=0;
                if (tablero[i][j] == 'X' || tablero[i][j]=='O'){
                    b=0;
                    cout << "El lugar ya esta ocupado!! Intentalo en otro!!"<<endl;
                }
                break;
            }
            case '2':{
                i=0;
                j=1;
                if (tablero[i][j] == 'X' || tablero[i][j]=='O'){
                    b=0;
                    cout << "El lugar ya esta ocupado!! Intentalo en otro!!"<<endl;
                }
                break;
            }
            case '3':{
                i=0;
                j=2;
                if (tablero[i][j] == 'X' || tablero[i][j]=='O'){
                    b=0;
                    cout << "El lugar ya esta ocupado!! Intentalo en otro!!"<<endl;
                }
                break;
            }
            case '4':{
                i=1;
                j=0;
                if (tablero[i][j] == 'X' || tablero[i][j]=='O'){
                    b=0;
                    cout << "El lugar ya esta ocupado!! Intentalo en otro!!"<<endl;
                }
                break;
            }
            case '5':{
                i=1;
                j=1;
                if (tablero[i][j] == 'X' || tablero[i][j]=='O'){
                    b=0;
                    cout << "El lugar ya esta ocupado!! Intentalo en otro!!"<<endl;
                }
                break;
            }
            case '6':{
                i=1;
                j=2;
                if (tablero[i][j] == 'X' || tablero[i][j]=='O'){
                    b=0;
                    cout << "El lugar ya esta ocupado!! Intentalo en otro!!"<<endl;
                }
                break;
            }
            case '7':{
                i=2;
                j=0;
                if (tablero[i][j] == 'X' || tablero[i][j]=='O'){
                    b=0;
                    cout << "El lugar ya esta ocupado!! Intentalo en otro!!"<<endl;
                }
                break;
            }
            case '8':{
                i=2;
                j=1;
                if (tablero[i][j] == 'X' || tablero[i][j]=='O'){
                    b=0;
                    cout << "El lugar ya esta ocupado!! Intentalo en otro!!"<<endl;
                }
                break;
            }
            case '9':{
                i=2;
                j=2;
                if (tablero[i][j] == 'X' || tablero[i][j]=='O'){
                    b=0;
                    cout << "El lugar ya esta ocupado!! Intentalo en otro!!"<<endl;
                }
                break;
            }
        }
    }
    tablero[i][j]= 'X';
}
/// MUESTRO TABLERO EN CONSOLA.
void print_tablero(char tablero [3][3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << "  " << tablero[i][j];
            cout << "  |  ";
        }
        cout << ("\n---------------------\n");
    }

}
/* CREO JUGADOR CONSOLA DE MANERA ALEATORIA UTILIZANDO EL SRAND
Y RAND QUE EXPLICO HOY KLOSTER, SI SE ENTENDIO GENTES XD*/
void ingreso_pc (char tablero[3][3]){
    int i, j, b=1;
    srand (time(NULL));
    while(b==1){
        i= rand()%3;
        j= rand()%3;
        b=0;
        if (tablero [i][j] == 'X' || tablero [i][j] == 'O' ){
            b=1;
        }
    }
    tablero [i][j]= 'O';
}
/// FUNCION GANADOR. VOY A UTILIZAR INT
int ganador (char tablero [3][3]){
    ///COMPARO TODAS LAS POSIBILIDADES DE GANAR DE LA POSICION 0,0 (1)
    if (tablero [0][0] == 'X' || tablero [0][0] == 'O'){
        if(tablero [0][0] == tablero [0][1] && tablero [0][0] == tablero [0][2]){
            if(tablero [0][0] == 'O'){
                return 0; // Gana la O.
            }
            else {
                return 1;// Gana la X.
            }
        }
        if(tablero [0][0] == tablero [1][0] && tablero [0][0] == tablero [2][0]){
            if(tablero [0][0] == 'O'){
                return 0; // Gana la O.
            }
            else {
                return 1;// Gana la X.
            }
        }

    }
    /// COMPARO TODAS LAS POSIBILIDADES DE GANAR EN LA POSICION 1,1.(5)
    if(tablero [1][1] == 'X' || tablero [1][1] =='O'){
        if(tablero [1][1] == tablero [0][0] && tablero [1][1] == tablero [2][2]){
            if(tablero [1][1] == 'O'){
                return 0; // Gana la O.
            }
            else {
                return 1;// Gana la X.
            }
        }
        if(tablero [1][1] == tablero [1][0] && tablero [1][1] == tablero [1][2]){
            if(tablero [1][1] == 'O'){
                return 0; // Gana la O.
            }
            else {
                return 1;// Gana la X.
            }
        }
        if (tablero [1][1] == tablero [2][0] && tablero [1][1] == tablero [0][2]){
            if(tablero [1][1] == 'O'){
                return 0; // Gana la O.
            }
            else {
                return 1;// Gana la X.
            }
        }
        if (tablero [1][1] == tablero [0][1] && tablero [1][1] == tablero [2][1]){
            if(tablero [1][1] == 'O'){
                return 0; // Gana la O.
            }
            else {
                return 1;// Gana la X.
            }
        }

    }
    ///COMPARO TODAS LAS POSIBILIDADES DE LA POSICION 2,2 (9)
    if(tablero [2][2] == tablero [2][1] && tablero [2][2] == tablero [2][0]){
        if(tablero [2][2] == 'O'){
            return 0; // Gana la O.
        }
        else {
            return 1;// Gana la X.
        }
    }
    if(tablero [2][2] == tablero [1][2] && tablero [2][2] == tablero [0][2]){
        if(tablero [2][2] == 'O'){
            return 0; // Gana la O.
        }
        else {
            return 1;// Gana la X.
        }
    }
    return 2;
}




