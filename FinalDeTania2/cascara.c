#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "SLetra.h"
#include "ArrayList.h"
#include "Tool.h"
#include "cascara.h"




int cascara_Alta(ArrayList* LList)
{
    int returnAux = DENIED;

    if(LList != NULL)
    {


        returnAux = LList->add(LList, SLetra_Alta());
    }

    return returnAux;
}


int cascara_Completar(ArrayList* LList)
{
    int returnAux = DENIED, i;

    if(LList != NULL)
    {
        SLetra* aux;
        for(i = 0; i < LList->len(LList); i++)
        {
            aux = LList->get(LList, i);

            switch(isVocal(aux->letra))
            {
                case DENIED:
                    aux->consonante = OK;
                    aux->vocal = OK;
                    break;

                case OK:
                    aux->consonante = OKP;



            }



            returnAux = LList->set(LList, i, aux);
        }
    }

    return returnAux;
}
