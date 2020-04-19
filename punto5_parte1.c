#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
    if(argc>1){
        FILE *myFile;
    myFile = fopen("numbers.txt", "r");

    //read file into array
    long suma = 0;
    int numero = atoi(argv[1]);
    int numberArray[numero];
    int i;

    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }

    for (i = 0; i < numero; i++){
        fscanf(myFile, "%d,", &numberArray[i] );
        printf("Number is: %d\n\n", numberArray[i]);
        suma+=numberArray[i];
    }

    printf("La suma es %ld\n", suma);
    fclose(myFile);

    return 0;
    }
    else {
        printf("Ingrese el número de valores en el vector");
        return 0;
    }
}