#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

void* factorial (void* arg);

int main (int argc, char *argv[]) {
    srand(time(0)); 
    printf("%d", argc);
  if (argc) {
      
      pthread_t threads_ids[argc];
      int i;
      int *param, *fact;
      param = malloc(argc*sizeof(int));
      fact = malloc(argc*sizeof(int));
      for(i=1; i<=argc; i++){
            param[i]=atoi(argv[i]);
      }
        for(i=1; i<argc;i++){
            pthread_create(&threads_ids[i],NULL,&factorial,&param[i]);
        }
    for(i=1;i<=argc;i++){
        pthread_join(threads_ids[i],(void *)&fact[i]);
    }
      
    for(i=1; i<argc;i++){
        printf ("El factorial de %d es %d\n", param[i], &fact[i]);
    }
    for(i=1;i<=argc;i++){
        free(fact[i]);
    }
    
  return 0;
  }
  
}


void* factorial(void* arg){
    int fact = *((int*)arg);
    long long int resultado= 1;
    int num;
    for (num= 2; num< fact; num++) {
        resultado= resultado*num;
        printf ("Factorial de %d, resultado parcial %d\n", fact, resultado);
        sleep (random()%3);
    }
    return resultado;
}