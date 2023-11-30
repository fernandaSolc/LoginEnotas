#include <stdio.h>
#include <string.h>
#include "login.h"

Usuario usuarios[100];
int numUsuarios = 0;

int encontrarUsuario(char* login) {
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].login, login) == 0) {
            return i;
        }
    }
    return -1;
}

void cadastrarUsuario(char* login, char* senha) {
    strcpy(usuarios[numUsuarios].login, login);
    strcpy(usuarios[numUsuarios].senha, senha);
    numUsuarios++;
}

int verificarSenha(int index, char* senha) {
    return strcmp(usuarios[index].senha, senha) == 0;
}

void salvarDados() {
    FILE* arquivo = fopen("usuarios.txt", "w");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo usuarios.txt\n");
        return;
    }
    for (int i = 0; i < numUsuarios; i++) {
        fprintf(arquivo, "%s %s\n", usuarios[i].login, usuarios[i].senha);
    }
    fclose(arquivo);
}

void carregarDados() {
    FILE* arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo usuarios.txt\n");
        return;
    }
    while (!feof(arquivo)) {
        fscanf(arquivo, "%s %s\n", usuarios[numUsuarios].login, usuarios[numUsuarios].senha);
        numUsuarios++;
    }
    fclose(arquivo);
}