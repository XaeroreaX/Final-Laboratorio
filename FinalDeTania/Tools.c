#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define DENIED -1
#define OK 0
#define OKP 1





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
