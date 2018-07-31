#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayList.h"
#include "SLetra.h"
#include "Tool.h"

SLetra* SLetra_contruct(char letra, char nombre[])
{
    SLetra* character;

    character =(SLetra*) malloc(sizeof(SLetra));

    if(character != NULL)
    {
        character->letra = letra;

        strcpy(character->nombre, nombre);

        character->vocal = DENIED;
        character->consonante = DENIED;

        //DENIED es no depurado

    }

    return character;
}


SLetra* SLetra_Alta()
{
    SLetra* character;

    char letra, nombre[21];

    fflush(stdin);

    printf("tipee una letra:");
    letra = getchar();



    printf("ingrese un nombre:");
    cargarCaracter(21, nombre);

    character = SLetra_contruct(letra, nombre);

    return character;
}


int SLetra_Load(FILE* pFile, ArrayList* LList)
{

    int returnAux = DENIED;
    char titulo[1024], letra[5], nombre[21];
    SLetra* character;

    if(LList == NULL || pFile == NULL) return returnAux;

    fgets(titulo, 1024, pFile);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^\n]\n", letra, nombre);
        character = SLetra_contruct(letra, nombre);

        returnAux = LList->add(LList, character);
    }

    return returnAux;
}









