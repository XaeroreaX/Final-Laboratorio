#define DENIED -1
#define OK 0
#define OKP 1


void Tools_showOptions();


int Tools_NexIdUnrepeatable(ArrayList* List, int (*getId)(void*));

int Tools_getIndex(ArrayList* List, int (*Selector)(ArrayList*));


void Tools_showList(ArrayList* List, void (*show)(void*));

void Tools_showHour(int durationSeg);


int Tools_numValidado(char messages[], int ground, int top);


char ToolS_Gets(int size, char String[]);


int Tools_GetsDynamic(char* String);


void Tools_FreeString(int size, char String[size]);

void Tools_fgetsToChar(FILE* pFile, int size, char string[size], char To);


int Tools_FileList(char path[], char open[], ArrayList* List, int (*WriteOrRead)(FILE*, ArrayList*));




int Tools_FileArray(char path[], char open[], void* Array[], int size, int (*WriteOrRead)(FILE*, void*[], int));
