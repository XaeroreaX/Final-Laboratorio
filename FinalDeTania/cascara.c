#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ArrayList.h"
#include "SLetra.h"
#include "tools.h"
#include "cascara.h"
#define DENIED -1
#define OK 0
#define OKP 1



int Cascara_Alta(ArrayList* LList)
{
    int returnAux = DENIED;
    SLetra* caracter;

    if(LList != NULL)
    {
        printf("ingrese los datos de la letra\n");

        caracter = SLetra_GetLetraArgument();

        if(caracter != NULL) returnAux = OK;
    }

    return returnAux;
}



int Cascara_ConfirmarList(ArrayList* LList)
{
    int returnAux = DENIED, i;
    SLetra* caracter;

    if(LList != NULL)
    {
        returnAux = OK;

        if(LList->isEmpty() != OKP)
        {

            returnAux = OKP;
            for(i = 0; i < LList->len(LList); i++)
            {

                caracter = (SLetra*) LList->get(LList, i);

                switch(isVocal(caracter->letra))
                {
                    case DENIED:
                        caracter->consonante = DENIED;
                        caracter->vocal = DENIED;
                        break;

                    case OK:
                        caracter->consonante = OK;
                        caracter->vocal = DENIED;
                        break;

                    case OKP:
                        caracter->consonante = DENIED;
                        caracter->vocal = OK;
                        break;
                }

                LList->set(LList, i, caracter);

            }



        }

    }

    return returnAux;

}


int Cascara_Listar(ArrayList* LList)
{
    int returnAux = DENIED;


    if(LList != NULL)
    {
        ArrayList* auxList = LList->clone(LList);

        returnAux = auxList->sort(auxList, SLetra_CompareLetra,1);

        SLetra_showListar(LList, SLetra_show);
    }


    return returnAux;

}
