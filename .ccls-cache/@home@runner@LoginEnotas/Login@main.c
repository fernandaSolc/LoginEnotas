#include <stdio.h>
#include "login.h"
#include "notas.h"

int main() {
    char login[50];
    char senha[50];

    printf("Digite seu login: ");
    scanf("%s", login);

    int index = encontrarUsuario(login);
    if (index == -1) {
        printf("Usuario nao encontrado. Deseja criar uma conta? (s/n): ");
        char opcao;
        scanf(" %c", &opcao);
        if (opcao == 's') {
            printf("Digite sua senha: ");
            scanf("%s", senha);
            cadastrarUsuario(login, senha);
        }
    } else {
        printf("Digite sua senha: ");
        scanf("%s", senha);
        if (verificarSenha(index, senha)) {
            printf("Login bem sucedido!\n");
        } else {
            printf("Senha incorreta!\n");
        }
    }

    return 0;
}
