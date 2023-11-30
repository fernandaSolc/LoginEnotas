#ifndef NOTAS_H
#define NOTAS_H

#include "login.h"

typedef struct {
    Usuario usuario;
    float notas[10];
    int numNotas;
} Notas;

extern Notas notas[50];

void adicionarNota(char* login, float nota);
float calcularMedia(char* login);

#endif
