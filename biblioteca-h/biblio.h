#ifndef BIBLIO_H
#define BIBLIO_H

/*Estrutura Struct*/
typedef struct 
{
    int x;
    int y;
} Operador;

int soma(int x, int y){
    Operador operador1;
    operador1.x = x;
    operador1.y = y;
    return operador1.x + operador1.y;
     
}

int subtracao(int x,int y){
    Operador operador2;
    operador2.x = x;
    operador2.y = y;
    return operador2.x - operador2.y;
     
}

int multiplicacao(int x, int y){
    Operador operador3;
    operador3.x = x;
    operador3.y = y;
    return operador3.x * operador3.y;
     
}

float divisao(int x,int y){
    Operador operador4;
    operador4.x = x;
    operador4.y = y;
    return (float)operador4.x / operador4.y;
    
}


#endif /*Fim*/
