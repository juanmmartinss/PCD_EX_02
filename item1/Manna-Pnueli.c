#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int soma = 0;
int respond = 0;
int request = 0;

void Client(int id);
void Server(int id);
void SecaoCritica(int id);

int main(){


    return 0;
}

void Client(int id){
    while
}

void Server(int id){
}

void SecaoCritica(int id){
    int local = soma;
    sleep(rand()%2);
    soma = local + 1;
}