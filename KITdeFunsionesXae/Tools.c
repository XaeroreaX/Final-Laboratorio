#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayList.h"
#include "Tools.h"




int Tools_NexIdUnrepeatable(ArrayList* List, int (*getId)(void*))
{
    int flagEncontrado = DENIED,i, j,id = 1;



    void* Struct1, *Struct2;

    if(List == NULL) return DENIED;



    if(List->isEmpty(List) == OK)
    {


        for(i = 0; i < List->len(List); i++)
        {
            Struct1 = List->get(List, i);

            if(getId(Struct1) == id)
            {
                id = getId(Struct1) +1;
            }
            else
            {

                for(j = i + 1; j < List->len(List); j++)
                {
                    Struct2 = List->get(List, j);

                    if(id == getId(Struct2)) break;

                }


                if(j < List->len(List)) flagEncontrado = OK;

            }

            if(flagEncontrado == DENIED)
            {
                id = getId(Struct1) + 1;
            }
            else
            {
                break;
            }
        }

    }

    return id;
}



int Tools_getIndex(ArrayList* List, int (*Selector)(ArrayList*))
{
    int index = DENIED;


    if(List != NULL)
    {
        index = Selector(List);
    }

    return i;
}




/**------------------------------------------------------SHOW-----------------------------------------------------------------------------*/


void Tools_showList(ArrayList* List, void (*show)(void*))
{
    int i, returnAux = DENIED;

    void* StructIt;

    if(List != NULL && show != NULL)
    {

        returnAux = OK;

        if(list->isEmpty(List) != OKP)
        {


            for(i = 0; i < List->len(List); i++)
            {

                funcion(List->get(List, i));

                printf("\n");

            }

        }
    }

    return returnAux;
}


void Tools_showOptions()
{
            printf("1- Agregar \n");
            printf("2- Borrar \n");
            printf("3- Modificar \n");
            printf("4- mostrar\n");
            printf("5- Salir\n");
            printf("ingrese opcion")
}

void Tools_showHour(int durationSeg)
{
    printf("%d:%d:%d", (durationSeg/3600), ((durationSeg%60)/60), ((durationSeg%60)%60));

}
/**-----------------------------------------------------------------------------------------------------------------------------------------*/




int Tools_numValidado(char messages[], int ground, int top)
{
    int numero;
    fflush(stdin);

    printf("%s:",messages);
    scanf("%d", &numero);

    while(numero < ground || numero > top)
    {
        printf("el numero ingresado no es valido, por favor ingrese de nuevo");
        fflush(stdin);
        scanf("%d", &numero);
    }

    return numero;
}



/**----------------------------------------cadena de caracteres---------------------------------------------------*/

char ToolS_Gets(int size, char String[])
{
    char buffer[1024];

    fflush(stdin);
    gets(buffer);
    while(strlen(buffer) > size)
    {
        printf("ingreso mal la cadena de caracteres, ingrese de nuevo");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(String, buffer);

    return String[size];
}





int Tools_GetsDynamic(char* String)
{
    int length, returnAux = DENEID;
    char* aux;

    String = (char*) malloc(sizeof(char) * 1024);

    if(String == NULL) return returnAux;

    fflush(stdin);
    scanf("%1023[^\n]", String);

    length = strlen(String);

    aux = (char*) realloc(String, sizeof(char*)* length+1);

    if(aux != NULL)
    {
        String = aux;
        returnAux = OK;
    }

    return returnAux;
}



void Tools_FreeString(int size, char String[size])
{
    int i;

    for(i = 0; i < size; i++)
        string[i] = '\0';


}


char* Tools_ConvertArrayToDynamic(char character[])
{
    char* chars;
    int len;

    len = strlen(character);

    chars = (char*) malloc(sizeof(char)*(len+1));

    strcpy(chars, character);


    return chars;
}


void Tools_fgetsToChar(FILE* pFile, int size, char string[size], char To)
{
    int i;

    char auxChar;


    for(i = 0; auxChar != To && i < size; i++)
    {
        auxChar = fgetc(pFile);
        if(auxChar != To)
            string[i] = auxChar;

    }



}



///**----------------------------------------------------------------------------------------------------------*/



/**----------------------------------------------------ARCHIVOS-------------------------------------------------------------------------*/



int Tools_FileList(char path[], char open[], ArrayList* List, int (*WriteOrRead)(FILE*, ArrayList*)) ///usar con sabiduria
{

    int returnAux = DENIED;

    FILE* pFile = fopen(path, open);

    if(pFile != NULL && List != NULL)
    {
        returnAux = WriteOrRead(pFile, List);
    }

    fclose(pFile);

    return returnAux;

}

int Tools_FileArray(char path[], char open[], void* Array[], int size, int (*WriteOrRead)(FILE*, void*[], int))
{
    int returnAux = DENIED;

    FILE* pFile = fopen(path, open);

    if(pFile != NULL)
    {

        returnAux = WriteOrRead(pFile, Array, size);


    }

    fclose(pFile);

    return returnAux;
}


/**------------------------------------------------------------------------------------------------------------------------------*/






