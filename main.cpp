/* 
 * File:   main.cpp
 * Author: Moises Gonzalez
 *
 * Created on 13 de julio de 2015, 04:37 PM
 */

#include<iostream>
#include<wchar.h>

using namespace std;

void init_matriz(char matriz[3][3]);
void print_matriz(char matriz[3][3]);
char turn_player(char player_name[20], char matriz[3][3], char type);

int main(){
    char matriz[3][3];
    int x,y;
    bool sw = false;
    
    init_matriz(matriz);
       
    cout<<endl<<"Turno del player 1"<<endl;
    print_matriz(matriz);
    cout<<endl<<endl<<"Ingrese coordenada a jugar: ";
    cin>>x;
    cin>>y;
    matriz[x-1][y-1] = 'x';
    print_matriz(matriz);    
    
    return 0;
}

void init_matriz(char matriz[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matriz[i][j] = '*';
        }
    }
}

void print_matriz(char matriz[3][3]){
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
/*
char *turn_player(char player_name[20], char matriz[3][3], char type){
    int x,y;
    //char coord[2];
    
    cout<<"Turno del player: "<<player_name<<endl;
    print_matriz(matriz);
    cout<<"Ingrese coordenada a jugar: ";
    cin>>x;
    cin>>y;
    //cin>>coord;
    //x = coord[0] + "0";
    //y = coord[1] + "0";
    matriz[x][y] = type;
    return matriz;
}
*/