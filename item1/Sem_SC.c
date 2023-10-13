/*
Daniel Ferreira Martins, RA: 156.369
Savio Augusto Machado Araujo, RA: 156.584
Juan Marcos Martins, RA: 156.470
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <omp.h>

int soma = 0;

int main(){
    #pragma omp parallel num_threads(4)//cria duas threads
    {
        int id = omp_get_thread_num();//pega o id da thread
        while(true){
            int local = soma;
            sleep(rand()%2);//dorme por um tempo aleatório
            soma = local + 1;
            printf("Thread %d: %d\n", id, soma);
        }
    }

    return 0;
}