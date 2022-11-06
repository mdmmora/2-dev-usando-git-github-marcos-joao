#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>

using namespace std;

int pos[3] = {3, 3, 2}; //1=Norte; 2=Leste; 3=Sul; 4=Oeste
string cmd = "MMRMMRMRRM";
int grid[2] = {5, 5}; //tamanho do grid
int k=1;
char op;
char L = 'L';
char R = 'R';
char M = 'M';

//Funções de movimento:
int Left(void)
{
    if(pos[2] == 1)
    {
       pos[2] = 4;
       return 0;
    }

    if(pos[2] == 4)
    {
       pos[2] = 3;
       return 0;
    }
    if(pos[2] == 3)
    {
       pos[2] = 2;
       return 0;
    }
    if (pos[2] == 2)
    {
       pos[2] = 1;
       return 0;
    }
    return 0;
}

int Right(void)
{
    if(pos[2] == 1)
    {
       pos[2] = 2;
       return 0;
    }

    if(pos[2] == 2)
    {
       pos[2] = 3;
       return 0;
    }
    if(pos[2] == 3)
    {
       pos[2] = 4;
       return 0;
    }
    if (pos[2] == 4)
    {
       pos[2] = 1;
       return 0;
    }
    return 0;
}

int Move(void)
{
   if(pos[2] == 1) //norte
   {
       if(pos[1] == grid[1])
       {
           pos[1] = 0;
           return 0;
       }
       pos[1] = pos[1]+1;
       return 0;
   }
   if(pos[2] == 4) //oeste
   {
       if(pos[0] == 0)
       {
           pos[0] = grid[0];
           return 0;
       }
       pos[0] = pos[0]-1;
       return 0;
   }
   if(pos[2] == 3) //sul
   {
       if(pos[1] == 0)
       {
           pos[1] = grid[1];
           return 0;
       }
       pos[1] = pos[1]-1;
       return 0;
   }
   if(pos[2] == 2) //leste
   {
       if(pos[0] == grid[0])
       {
           pos[0] = 0;
           return 0;
       }
       pos[0] = pos[0]+1;
       return 0;
   }
}

int main()
{
   while(k)
   {
       printf("Digite 0 para sair ou 1 para continuar:\n");
       scanf("%d", &k);
       if(k==0)
       {
           return 0;
       }
       else
       {
           if(pos[2] == 1)
            printf("Posicao inicial: %d,%d,N\n", pos[0],pos[1]);
           if(pos[2] == 2)
            printf("Posicao inicial: %d,%d,E\n", pos[0],pos[1]);
           if(pos[2] == 3)
            printf("Posicao inicial: %d,%d,S\n", pos[0],pos[1]);
           if(pos[2] == 4)
            printf("Posicao inicial: %d,%d,W\n", pos[0],pos[1]);
           printf("Cmds executados: %s\n\n", cmd.c_str());
           for(int i = 0;i<=cmd.length();++i)
           {
               if(cmd[i]==L)
                Left();
               if(cmd[i]==R)
                Right();
               if(cmd[i]==M)
                Move();
           }
           if(pos[2] == 1)
            printf("Posicao final: %d,%d,N\n", pos[0],pos[1]);
           if(pos[2] == 2)
            printf("Posicao final: %d,%d,E\n", pos[0],pos[1]);
           if(pos[2] == 3)
            printf("Posicao final: %d,%d,S\n", pos[0],pos[1]);
           if(pos[2] == 4)
            printf("Posicao final: %d,%d,W\n", pos[0],pos[1]);
       }

   }
}
