#ifndef LOGIN_H
#define LOGIN_H

typedef struct {
    char login[6];
    char senha[10];
} Usuario;

extern Usuario usuarios[100];
extern int numUsuarios;

int encontrarUsuario(char* login);
void cadastrarUsuario(char* login, char* senha);
int verificarSenha(int index, char* senha);
void salvarDados();
void carregarDados();

#endif
