#include <stdio.h>
#include "login.h"
#include "notas.h"

char login[6],
senha[10];
char opcao;
int userExists;

main() {


    carregarDados();

    printf("Digite seu login: ");
    scanf("%s", login);

     int index = encontrarUsuario(login);
  
        printf("Digite sua senha: ");
        scanf("%s", senha);
        if (verificarSenha(index, senha)) 
        {
            printf("Login bem sucedido!\n");
        }
    
     else {
      printf("Usuario nao encontrado. Deseja criar uma conta? (s/n): ");
      scanf(" %c", &opcao);
     
    }
}         

void salvarUsuario() {
if (opcao == 's') {
    printf("Digite seu novo login: ");
    scanf("%s", login);
    int userExists = encontrarUsuario(login);
    if (userExists != -1) {
        printf("Login ja existente. Por favor, escolha outro login.\n\n");
    } else {
        printf("Digite sua senha: ");
        scanf("%s", senha);
        cadastrarUsuario(login, senha);
        salvarUsuario();
        printf("\n\nConta criada com sucesso!"); }
}}