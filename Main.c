#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


char M[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},id_1[100],id_2[100];
int tour=1,score_id_1=0,score_id_2=0;

int GameLoop(){
clrscr();
printf("Morpion Tour : %d | Score: %s : %d /!/ %s : %d \n",tour, id_1,score_id_1,id_2,score_id_2);
printf("______________\n");
printf("| %c | %c | %c |\n",M[0][0],M[0][1],M[0][2]);
printf("______________\n");
printf("| %c | %c | %c |\n",M[1][0],M[1][1],M[1][2]);
printf("______________\n");
printf("| %c | %c | %c |\n",M[2][0],M[2][1],M[2][2]);
printf("______________\n");
if(GameTest()=='X') return 1;
else {if (GameTest()=='O') return 2;
else {if (tour==9) return 3;}}
return 4;
}


void Control(){
int k=0,l=0,p=1;
if (tour%2==0) p=2;
else p=1;
do{
if(p==1) printf("Player %s : i and j: \n",id_1);
else printf("Player %s : i and j: \n",id_2);
scanf("%d%d",&k,&l);
}while(M[k][l]!=' ');

if (tour%2==0) M[k][l]='O';
else M[k][l]='X';
}

int GameTest(){
if(M[0][0]==M[1][1] && M[0][0]==M[2][2]) return M[0][0];
if(M[2][0]==M[1][1] && M[2][0]==M[0][2]) return M[2][0];

if(M[0][0]==M[0][1] && M[0][0]==M[0][2]) return M[0][0];
if(M[1][0]==M[1][1] && M[1][0]==M[1][2]) return M[1][0];
if(M[2][0]==M[2][1] && M[2][0]==M[2][2]) return M[2][0];

if(M[0][0]==M[1][0] && M[0][0]==M[2][0]) return M[0][0];
if(M[0][1]==M[1][1] && M[0][1]==M[2][1]) return M[0][1];
if(M[0][2]==M[1][2] && M[0][2]==M[2][2]) return M[0][2];
}


void main(){
int i,j,game=0,ingame=0;
do{
    printf("Welcome to Morpion by Hamza Ahmouny\n");
    printf("Entrer le nom du joueur 1:\n");scanf("%s",&id_1);
    printf("Entrer le nom du joueur 2:\n");scanf("%s",&id_2);
    score_id_1=0;score_id_2=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            M[i][j]=' ';
    }}
    do{
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            M[i][j]=' ';
    }}
    while(tour<10){
        Control();
        GameLoop();
        if(GameLoop()==1) {printf("PLAYER %s WIN !\n",id_1);score_id_1++;break;}
        if(GameLoop()==2) {printf("PLAYER %s WIN !\n",id_2);score_id_2++;break;}
        if(GameLoop()==3) {printf("GAME NULL\n");break;}
        tour++;Sleep(1);
    }
    printf("Entrer 0 pour continuer 1 pour reset le score");scanf("%d",&ingame);
    clrscr();
    }while(ingame==0);
        printf("Entrer 0 pour recommencer une partie et 1 pour quitter le jeu");scanf("%d",&game);
        clrscr();
}while(game==0);
}




