#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>

#define MAXLON 1000

void cuenta (void* arg);

int main (int argc, char *argv[]) { 
  if (argc!= 2) {
    printf ("Indica el nombre de un fichero.\n");
    exit(0);
  }
  pthread_t hilo;
  char parametros[strlen(argv[1])];
  strcpy(parametros, argv[1]);
  pthread_create(&hilo, NULL,(void *)cuenta,&parametros);
  pthread_join(hilo, NULL);
  //cuenta(argv[1]);
  return 0;
}

void cuenta (void* parametros) {
  char *nombre = parametros;
  int pos, cont= 0, leidos;
  char cadena[MAXLON];
  int fd;
  fd= open(nombre,O_RDONLY);
  while ((leidos =read(fd,cadena,MAXLON))!= 0) {
    for (pos= 0; pos< leidos; pos++) {
      if ((cadena[pos]== 'a') || (cadena[pos]== 'A')) {
        cont++;
      }
    }
  }
  printf("Fichero %s: %d caracteres 'a' o 'A' encontrados\n", nombre, cont);
  close(fd);
}