#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <omp.h>

int soma = 0;
int respond = 0;
int request = 0;

void Client(int id);
void Server(int id);
void SecaoCritica(int id);

int main(){
    #pragma omp parallel num_threads(4)//cria duas threads
    {
        int id = omp_get_thread_num();//pega o id da thread
        if(id == 0){//se for a thread 0, ela é o servidor
            Server(id);//chama a função do servidor
        }else{
            Client(id);//se não, é um cliente
        }
    }

    return 0;
}

void Client(int id){//função do cliente
    while(true){//loop infinito
        while(respond != id){//enquanto o respond for diferente do id do cliente
            request = id;
        }
        //printf("Thread %d: %d\n", id, soma);
        SecaoCritica(id);//chama a seção crítica
        respond = 0;
    }
}

void Server(int id){//função do servidor
    while(true){
        while(request == 0);//enquanto o request for 0
        respond = request;
        while(respond != 0);//enquanto o respond for diferente de 0
        request = 0;
    }
}

void SecaoCritica(int id){//função da seção crítica
    int local = soma;
    sleep(rand()%2);//dorme por um tempo aleatório
    soma = local + 1;
    printf("Thread %d: %d\n", id, soma);
}