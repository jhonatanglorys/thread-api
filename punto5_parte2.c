#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct particion
{
    int comienzo, final;
};

void* sumarPartes(void* arg);

int numberArray[];

int main(int argc, char*argv[]){
    if(argc>1){
        FILE *myFile;
    myFile = fopen("numbers.txt", "r");

    //read file into array
    long suma = 0;
    int numero = atoi(argv[1]);
    numberArray[numero];
    printf("El número de elementos es: %d\n", numero);
    int i;

    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }

    for (i = 0; i < numero; i++){
        fscanf(myFile, "%d,", &numberArray[i]);
        //printf("Number is: %d\n\n", numberArray[i]);
        //suma+=numberArray[i];
    }
    int* retorno_uno, retorno_dos;
    pthread_t hilo_uno, hilo_dos;
    struct particion parte_uno, parte_dos;
    parte_uno.comienzo=0;
    parte_uno.final=(numero/2);
    parte_dos.comienzo=parte_uno.final;
    parte_dos.final=numero;
    printf("Los limites son %d, %d, %d, %d\n", parte_uno.comienzo, parte_uno.final, parte_dos.comienzo, parte_dos.final);
    pthread_create(&hilo_uno,NULL,&sumarPartes,&parte_uno);
    pthread_create(&hilo_dos,NULL,&sumarPartes,&parte_dos);
    fclose(myFile);
    pthread_join(hilo_uno,(void *)&retorno_uno);
    pthread_join(hilo_dos,(void *)&retorno_dos);
    int total=retorno_uno + retorno_dos;
    printf("La suma de todos los elementos es%d \n", total);
    return 0;
    }
    else {
        printf("Ingrese el número de valores en el vector\n");
        return 0;
    }
}

void* sumarPartes(void* parametros){
    struct particion* params = (struct particion*) parametros;
    long suma=0;
    int inicio =params->comienzo;
    int final=params->final;
    int j;
    for(j=inicio;j<final;j++){
        suma+=numberArray[j];
    }
    printf("La suma parcial de los elementos es %ld\n", suma);
    long* p_c = malloc(sizeof(long));
    *p_c = suma;
    return p_c;
}