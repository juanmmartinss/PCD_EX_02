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