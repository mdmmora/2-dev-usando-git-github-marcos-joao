#include <stdio.h>

#define MAXCHAR 1024

//Função para ler o arquivo .txt
char linhas[100][MAXCHAR];
pos[x y O]
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

int L()
{
    if(pos[3] = 'N')
    {
       pos[3] = 'W';
       return 0;
    }

    if(pos[3] = 'W')
    {
       pos[3] = 'S';
       return 0
    }
    if(pos[3] = 'S')
    {
       pos[3] = 'E';
       return 0;
    }
    if (pos[3] = 'E')
    {
       pos[3] = 'N';
       return 0
    }
}

int R()
{
    if(pos[3] = 'N')
    {
       pos[3] = 'E';
       return 0;
    }

    if(pos[3] = 'E')
    {
       pos[3] = 'S';
       return 0
    }
    if(pos[3] = 'S')
    {
       pos[3] = 'W';
       return 0;
    }
    if (pos[3] = 'W')
    {
       pos[3] = 'N';
       return 0
    }
}

int M()
{
   if(pos[3] = 'N')
   {
       pos[2] = pos[2]+1;
       return 0;
   }
   if(pos[3] = 'W')
   {
       pos[1] = pos[1]-1;
       return 0;
   }
   if(pos[3] = 'S')
   {
       pos[2] = pos[2]-1;
       return 0;
   }
   if(pos[3] = 'E')
   {
       pos[1] = pos[1]+1;
       return 0;
   }
}


int main() {

    abre_arquivo();


}
//2-dev-usando-git-github-marcos-joao\MarsRover
