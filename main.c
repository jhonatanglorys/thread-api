#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

struct num_fact
{
  int num;
};

long* factorial (void* arg);

int main(int argc, char*argv[]){
     srand(time(0)); 
    if(argc>1){
        int *fact;
        fact= malloc(argc*sizeof(int));
        pthread_t threads_id[argc];
        int i;
        struct num_fact *parametros;
        parametros = malloc(argc*sizeof(struct num_fact));
         for(i=1; i<argc;i++){
            parametros[i].num=atoi(argv[i]);
            //printf("%d\n", parametros[i].num);
            pthread_create(&threads_id[i], NULL, &factorial, &parametros[i].num);
            pthread_join(threads_id[i],(void *)fact[i]);
            //printf ("El factorial de %d es %d\n", parametros[i].num, *(fact+i));
            free(*(fact+i));
        }
    }
    
    return 0;
}


long* factorial(void* parameters){
    struct num_fact* fact = (struct num_fact*) parameters;
    long resultado= 1;
    int num;
    for (num= 2; num<=fact->num; num++) {
        resultado= resultado*num;
        printf ("Factorial de %d, resultado parcial %ld\n", fact->num, resultado);
        sleep (random()%3);
    }
    return resultado;
}