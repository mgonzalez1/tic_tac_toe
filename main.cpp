/* 
 * File:   main.cpp
 * Author: Moises Gonzalez
 *
 * Created on 13 de julio de 2015, 04:37 PM
 */

#include<iostream>
#include<wchar.h>

using namespace std;

void init_matriz();
void print_matriz();
void turn_player(char player_name[20], char type);
void game();

char matriz[3][3];
char player1[255] = "Player1";
char player2[255] = "Player2";

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

void turn_player(char player_name[255],char type){
    int x,y;
    cout<<endl<<"Turno de: "<<player_name<<endl;
    print_matriz();
    cout<<endl<<endl<<"Ingrese coordenada a jugar: ";
    cin>>x;
    cin>>y;
    matriz[x-1][y-1] = type;
    print_matriz();
    cout<<"Presione ENTER para continuar...";
    getwchar();
    getwchar();
}

void game(){
    turn_player(player1,'X'); 
    turn_player(player2,'O');
}