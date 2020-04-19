#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

struct num_fact
{
  int num;
};


void* factorial (void* arg);

int main (int argc, char *argv[]) {
    srand(time(0)); 
    
  if (argc== 3) {
        int* fact_uno;
        int* fact_dos;
      pthread_t id_hilo_uno;
      pthread_t id_hilo_dos;  
      struct num_fact param_uno;
      struct num_fact param_dos;
      param_uno.num = atoi(argv[1]);
      param_dos.num = atoi(argv[2]);
      pthread_create(&id_hilo_uno,NULL,&factorial,&param_uno);
      pthread_create(&id_hilo_dos,NULL,&factorial,&param_dos);
      pthread_join(id_hilo_uno,(void *)&fact_uno);
      pthread_join(id_hilo_dos,(void *)&fact_dos);
    //printf ("El factorial de %d es %d\n", param_uno, *fact_uno);
    //printf ("El factorial de %d es %d\n", param_dos, *fact_dos);
    free(fact_uno);
    free(fact_dos);
  return 0;
  }
  
}


void* factorial(void* parameters){
    struct num_fact* fact = (struct num_fact*) parameters;
    long resultado= 1;
    int num;
    for (num= 2; num<=fact->num; num++) {
        resultado= resultado*num;
        printf ("Factorial de %d, resultado parcial %lld\n", fact->num, resultado);
        sleep (random()%3);
    }
    return resultado;
}