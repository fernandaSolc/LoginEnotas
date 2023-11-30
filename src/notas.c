#include "notas.h"

Notas notas[50];

void adicionarNota(char* login, float nota) {
    int index = encontrarUsuario(login);
    if (index != -1) {
        notas[index].notas[notas[index].numNotas] = nota;
        notas[index].numNotas++;
    }
}

float calcularMedia(char* login) {
    int index = encontrarUsuario(login);
    if (index != -1) {
        float soma = 0;
        for (int i = 0; i < notas[index].numNotas; i++) {
            soma += notas[index].notas[i];
        }
        return soma / notas[index].numNotas;
    }
    return 0;
}
