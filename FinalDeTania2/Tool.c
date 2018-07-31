#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayList.h"
#include "Tool.h"

char cargarCaracter(int tam, char caracteres[])
{
    char buffer[1024];

    fflush(stdin);
    gets(buffer);
    while(strlen(buffer) > tam)
    {
        printf("ingreso mal la cadena de caracteres, ingrese de nuevo");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(caracteres, buffer);

    return caracteres[tam];
}


int ShowList(ArrayList* List, void (*show)(void* element))
{
    int returnAux = DENIED;

    if(List != NULL)
    {
        returnAux = OK;
        if(List->isEmpty(List) != OKP)
        {
            int i;

            for(i = 0; i < List->len(List); i++) show(List->get(List, i));
            returnAux = OKP;
        }
    }

    return returnAux;
}


int isVocal(char character)
{
    int returnAux = DENIED;



    if((tolower(character) > 96 && tolower(character)< 123) || tolower(character) == 164)
    {
        switch(character)
        {
            case 'a':
                returnAux = OKP;
                break;
            case 'e':
                returnAux = OKP;
                break;
            case 'i':
                returnAux = OKP;
                break;
            case 'o':
                returnAux = OKP;
                break;
            case 'u':
                returnAux = OKP;
                break;
            default
                returnAux = OK;

        }
    }

    return returnAux;

}

int FileList(char path[], char open[], ArrayList* List, int (*WriteOrRead)(FILE*, ArrayList*))
{
    FILE* pFile;

    int returnAux = DENIED;


    pFile = fopen(path, open);

    returnAux = WriteOrRead(pFile, List);

    fclose(pFile);

    return returnAux;
}



