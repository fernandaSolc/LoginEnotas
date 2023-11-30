#include <stdio.h>
#include "login.h"
#include "notas.h"

main() {
    char login[6],
    senha[10];

    carregarDados();

    printf("Digite seu login: ");
    scanf("%s", login);

    int index = encontrarUsuario(login);
    if (index == -1) 
      {
        printf("Digite sua senha: ");
        scanf("%s", senha);
        if (verificarSenha(index, senha)) 
        {
            printf("Login bem sucedido!\n");
      }
    
     else {
      printf("Usuario nao encontrado. Deseja criar uma conta? (s/n): ");
      char opcao;
      scanf(" %c", &opcao);
      
       if (opcao == 's') {
           int userExists;
           do {
               printf("Digite seu novo login: ");
               scanf("%s", login);
             
               userExists = encontrarUsuario(login);
             
               if (userExists != -1) {
                   printf("Login ja existente. Por favor, escolha outro login.\n");
               }
           } while (userExists != -1);
           printf("Digite sua senha: ");
           scanf("%s", senha);
           cadastrarUsuario(login, senha);
           
    } 
      else 
      {
        printf("Digite sua senha: ");
        scanf("%s", senha);
        cadastrarUsuario(login, senha);
        printf("\n\nConta criada com sucesso!");
    }
      }
  }}