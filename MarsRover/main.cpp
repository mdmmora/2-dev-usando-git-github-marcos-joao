#include <stdio.h>

#define MAXCHAR 1024

//Função para ler o arquivo .txt
char linhas[100][MAXCHAR];

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

}
//2-dev-usando-git-github-marcos-joao\MarsRover
