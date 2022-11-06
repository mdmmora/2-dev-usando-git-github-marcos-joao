#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>

using namespace std;

#define MAXCHAR 1024


char linhas[100][MAXCHAR];
char grid[2];
char pos[3];
char cmd[10];


//Funções de movimento:
int Left(void){
    if(pos[2] == 'N')
    {
       pos[2] = 'W';
       return 0;
    }

    if(pos[2] == 'W')
    {
       pos[2] = 'S';
       return 0;
    }
    if(pos[2] == 'S')
    {
       pos[2] = 'E';
       return 0;
    }
    if (pos[2] == 'E')
    {
       pos[2] = 'N';
       return 0;
    }
    return 0;
}

int Right(void){
    if(pos[2] == 'N')
    {
       pos[2] = 'E';
       return 0;
    }

    if(pos[2] == 'E')
    {
       pos[2] = 'S';
       return 0;
    }
    if(pos[2] == 'S')
    {
       pos[2] = 'W';
       return 0;
    }
    if (pos[2] == 'W')
    {
       pos[2] = 'N';
       return 0;
    }
    return 0;
}

int Move(void){
   if(pos[2] == 'N') //norte
   {
       if(pos[1] == grid[1]-1)
       {
           pos[1] = '0';
           return 0;
       }
       pos[1] = pos[1]+1;
       return 0;
   }
   if(pos[2] == 'W') //oeste
   {
       if(pos[0] == '0')
       {
           pos[0] = grid[0]-1;
           return 0;
       }
       pos[0] = pos[0]-1;
       return 0;
   }
   if(pos[2] == 'S') //sul
   {
       if(pos[1] == '0')
       {
           pos[1] = grid[1]-1;
           return 0;
       }
       pos[1] = pos[1]-1;
       return 0;
   }
   if(pos[2] == 'E') //leste
   {
       if(pos[0] == grid[0]-1)
       {
           pos[0] = '0';
           return 0;
       }
       pos[0] = pos[0]+1;
       return 0;
   }
}


//Função para ler o arquivo .txt
int abre_arquivo(){

    int cont = 0;
    FILE *fp;
    char str[MAXCHAR];
    char* filename = ".\\Deslocamento.txt";

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Não foi possível abrir o arquivo: %s",filename);
        return 1;
    }
    while (fgets(linhas[cont], MAXCHAR, fp) != NULL){
        printf("%s", linhas[cont]);
        cont = cont+1;
    }
    fclose(fp);


    return 0;


}


int main() {

    abre_arquivo();
    grid[0] = linhas[0][0];
    grid[1] = linhas[0][2];

    //Primeiro robo:
    pos[0] = linhas[2][0];
    pos[1] = linhas[2][2];
    pos[2] = linhas[2][4];
    for(int i = 0;i<9;++i)
    {
        cmd[i] = linhas[4][i];
    }
    printf("\n\nPrimeiro Robo:");
    printf("\nPosicao inicial: %c,%c,%c\n", pos[0],pos[1],pos[2]);
    for(int i = 0;i<9;++i){
        if(cmd[i]=='L')
            Left();
        if(cmd[i]=='R')
            Right();
        if(cmd[i]=='M')
            Move();
    }
    printf("Posicao final: %c,%c,%c\n", pos[0],pos[1],pos[2]);

    //Segundo robo
    pos[0] = linhas[6][0];
    pos[1] = linhas[6][2];
    pos[2] = linhas[6][4];
    for(int i = 0;i<10;++i)
    {
        cmd[i] = linhas[8][i];
    }
    printf("\nSegundo Robo:");
    printf("\nPosicao inicial: %c,%c,%c\n", pos[0],pos[1],pos[2]);
    //printf("\n%s\n",cmd);
    for(int i = 0;i<10;++i){
        if(cmd[i]=='L')
            Left();
        if(cmd[i]=='R')
            Right();
        if(cmd[i]=='M')
            Move();
    }
    //pos[1]=pos[1]+1;
    printf("Posicao final: %c,%c,%c\n", pos[0],pos[1],pos[2]);
}

