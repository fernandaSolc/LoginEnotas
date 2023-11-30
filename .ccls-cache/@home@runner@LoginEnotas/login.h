#ifndef LOGIN_H
#define LOGIN_H

typedef struct {
    char login[50];
    char senha[50];
} Usuario;

extern Usuario usuarios[50];
extern int numUsuarios;

int encontrarUsuario(char* login);
void cadastrarUsuario(char* login, char* senha);
int verificarSenha(int index, char* senha);

#endif
