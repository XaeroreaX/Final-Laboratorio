#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "SLetra.h"
#define DENIED -1
#define OK 0
#define OKP 1



SLetra* SLetra_Constructor(char letra, char nombre[21])
{

    SLetra* lepra;

    lepra = (SLetra*) malloc(sizeof(SLetra));



    if(nombre != NULL && lepra != NULL)
    {

        lepra->letra = letra;
        strcpy(lepra->nombre , nombre);
        lepra->vocal = DENIED;
        lepra->consonante = DENIED;
    }

    return lepra;
}


SLetra* SLetra_GetLetraArgument()
{
    SLetra* cliente;

    char nombre[21];
    char letra;
    printf("ingrese el nombre de la letra:");
    cargarCaracter(21, nombre);

    printf("tipee el caracter");
    letra = getchar();

    cliente = SLetra_Constructor(letra, nombre);

    return cliente;
}





void SLetra_showListar(ArrayList* LList, void (*funcion)(SLetra*))
{
    int i;

    SLetra* structi;



    for(i = 0; i < LList->len(LList); i++)
    {

        structi =(SLetra*) LList->get(LList, i);

        funcion(structi);

        printf("\n");

    }

}


void SLetra_show(SLetra* caracter)
{
    if(caracter != NULL && isVocal(caracter->letra) != DENIED)
        printf("Letra:%c     nombre:%s", caracter->letra, caracter->nombre);
}











int SLetra_fileToListText(char path[], ArrayList* LList)
{
    FILE* pFile;

    int returnAux = DENIED;
    char letra[2], nombre[21], Titulo[50];
    SLetra* caracter;

    pFile = fopen(path, "r");

    if(LList == NULL || pFile == NULL) return returnAux;

    fgets(Titulo, 50, pFile);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^\n]\n",letra, nombre);
        caracter = SLetra_Constructor(letra[0], nombre);

        returnAux = LList->add(LList, caracter);
    }

    fclose(pFile);

    return returnAux;
}


int SLetra_CompareLetra(void* caracterA, void* caracterB)
{
    if(isVocal(((SLetra*)caracterA)->letra) != DENIED && isVocal(((SLetra*)caracterA)->letra) == DENIED )
    {
        return -1;
    }


    if(((SLetra*)caracterA)->letra > ((SLetra*)caracterB)->letra)
    {
        return 1;
    }
    else
    {

        return -1;
    }

    return 0;

}


/*
int Song_listToFileText(char path[], ArrayList* playList)
{
    FILE* pFIle;
    int i, returnAux = DENIED;
    SSong* music;

    pFIle = fopen(path, "w+");

    if(playList == NULL || pFIle == NULL) return returnAux;

    fprintf(pFIle, "id,nombre,albun,artista,visitas,durationSeg\n");

    for(i = 0; i < playList->len(playList); i++)
    {
        music = (SSong*) playList->get(playList, i);
        if(music != NULL)
        {
            fprintf(pFIle, "%d,%s,%s,%s,%d,%d\n", music->id, music->name, music->Albun, music->Artist, music->visit,music->durationSeg);
            returnAux = OK;
        }
    }

    fclose(pFIle);

    return returnAux;
}


*/
