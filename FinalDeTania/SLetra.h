


typedef struct SLetra
{
    char letra;
    char nombre[21];
    int vocal;
    int consonante;

}SLetra;




SLetra* SLetra_Constructor(char letra, char nombre[21]);



SLetra* SLetra_GetLetraArgument();


void SLetra_showListar(ArrayList* LList, void (*funcion)(SLetra*));

void SLetra_show(SLetra* caracter);

int SLetra_fileToListText(char path[], ArrayList* LList);

int SLetra_CompareLetra(void* caracterA, void* caracterB);






