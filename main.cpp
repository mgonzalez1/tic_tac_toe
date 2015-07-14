/* 
 * File:   main.cpp
 * Author: Moises Gonzalez
 *
 * Created on 13 de julio de 2015, 04:37 PM
 */

#include<iostream>
#include<wchar.h>
#include<stdlib.h>
#include<time.h> 
#include<string>

using namespace std;

void init_matriz();
void print_matriz();
void turn_player(char player_name[255], char type);
void game();
void select_turn();

char matriz[3][3];
int hora = time(NULL);
char player1[255];
char player2[255];

int main(){
    init_matriz();
    game();
    return 0;
}

void init_matriz(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matriz[i][j] = '*';
        }
    }
}

void print_matriz(){
    cout<<"  1 2 3"<<endl;
    for(int i=0;i<3;i++){
        cout<<i+1<<" ";
        for(int j=0;j<3;j++){
            cout<<matriz[i][j]<<" ";
            if(j==2)
                cout<<endl;
        }
    }
}

void turn_player(char player_name[255], char type){
    int x,y;
    cout<<endl<<"Turno de: "<<player_name<<endl;
    print_matriz();
    cout<<endl<<"Ingrese coordenada a jugar: ";
    cin>>x;
    cin>>y;
    matriz[x-1][y-1] = type;
    print_matriz();
    cout<<"Presione ENTER para continuar...";
    getwchar();
    getwchar();
}

void game(){
    select_turn();
    turn_player(player1,'X'); 
    turn_player(player2,'O');
}

void select_turn(){
    int turn, numRand;
    char option, name[255];
    bool sw;
    
    cout<<"Como te llamas?"<<endl;
    fgets(name, sizeof(name), stdin);
    do{
        cout<<"Cara o Sello?"<<endl;
        cout<<"Escriba 'C' si es cara | 'S' si es sello"<<endl;
        cout<<"Seleccion: ";
        cin>>option;
        fflush(stdin);
        if(option == 'C' || option == 'c'){
            turn = 0;
            sw = true;
        }
        else if(option == 'S' || option == 's'){
            turn = 1;
            sw = true;
        }
        else{
            cout<<"Seleccion incorrecta..."<<endl;
            sw = false;
            getwchar();
        }
    }while(!sw);
    
    srand(hora);
    numRand = rand() % 11;
    numRand = numRand % 2;
    if( numRand == 0){
        cout<<"Salio Cara"<<endl;
        if(turn == 0){
            cout<<"Felicidades comienzas primero!"<<endl;
            strcpy(player1,name);
            strcpy(player2,"CPU");
        }
        else{
            cout<<"Comienzas segundo"<<endl;
            strcpy(player1,"CPU");
            strcpy(player2,name);
        }
    }
    else if(numRand == 1){
        cout<<"Salio Sello"<<endl;
        if(turn == 1){
            cout<<"Felicidades comienzas primero!"<<endl;
            strcpy(player1,name);
            strcpy(player2,"CPU");
        }
        else{
            cout<<"Comienzas segundo"<<endl;
            strcpy(player1,"CPU");
            strcpy(player2,name);
        }
    }
}