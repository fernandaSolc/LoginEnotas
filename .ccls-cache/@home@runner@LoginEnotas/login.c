#include <string.h>
#include "login.h"

Usuario usuarios[50];
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
