#include "ArrayList.h"

typedef struct
{
    char letra;
    char nombre[21];
    int vocal;
    int consonante;
}SLetra;


SLetra* SLetra_contruct(char letra, char nombre[]);

SLetra* SLetra_Alta();


int SLetra_Load(FILE* pFile, ArrayList* LList);
