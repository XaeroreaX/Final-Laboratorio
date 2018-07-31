#define DENIED -1
#define OK 0
#define OKP



char cargarCaracter(int tam, char caracteres[]);

int isVocal(char character);

int ShowList(ArrayList* List, void (*show)(void* element));

int FileList(char path[], char open[], ArrayList* List, int (*WriteOrRead)(FILE*, ArrayList*));
