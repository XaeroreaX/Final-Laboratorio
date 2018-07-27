#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define H 5
#include "KITdeFunsionesXae.h"

int main()
{
    int i = 0;
    SPersona persona[H];
    HarcodearSArray(persona);
    for(i = 0; i < H; i++)
    {
        MostrarS(persona[i]);
    }
    return 0;
}
