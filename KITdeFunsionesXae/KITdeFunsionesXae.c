#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "KITdeFunsionesXae.h"


/**-----------------------------------------------------------CASCARA------------------------------------------------------------------*/

int cascara()
{


    int opcion=0;



    do
    {
        Tools_showOptions();

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");



                system("pause");
                break;
            case 2:
                system("cls");


                system("pause");
                break;
            case 3:
                system("cls");


                system("pause");
                break;
            case 4:
                system("cls");



                system("pause");
               break;
            case 5:
                system("cls");

                system("pause");
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("ingreso mal la opcion, por favor ingrese de nuevo");
                system("pause");
                break;


        }while(seguir=='s');
        system("cls");

    }
    returnAux = OK;
    return returnAux;
}


/**-----------------------------------------------------HARCODEO------------------------------------------------------------------------*/

void HarcodearSArray(struct[])
{
    int i = 0;
    char nombre[][] = {"Martin", "Roberto", "Claudia", "Camila", "Jesus"};
    int edad[] = {22, 66, 15, 33, 42};

    for(i = 0; i < H; i++)
    {
        strcpy(persona[i].nombre, nombre[i]);
        strcpy(persona[i].telefono, telefono[i]);
        strcpy(persona[i].nacionalidad, nacionalidad[i]);
        persona[i].edad = edad[i];
        persona[i].dni = dni[i];
        persona[i].altura = altura[i];
        persona[i].peso = peso[i];
    }

}


/**------------------------------------------------------------------------*/

int harcodearSUser(ArrayList* userList)
{
    int i, returnAux = DENEID, id[5] = {1, 1001, 1002, 1003, 1004};
    char nickName[5][50] = {"XaeroreaX", "mr. queen", "camila","Atilio", "pucci"};
    char password[5][50] = {"master6060", "rey2501", "camila","abel6060", "Made in heaven"};
    SUser* user;



    if(user == NULL || userList == NULL) return returnAux;

    for(i = 0; i < 5; i++)
    {


        user = (SUser*) malloc(sizeof(SUser));
        user->id = id[i];

        strcpy(user->nickName, nickName[i]);
        strcpy(user->password, password[i]);

        returnAux = userList->add(userList, user);
        if(returnAux == DENEID) break;

    }

    return returnAux;
}



/**-----------------------------------------------------BURBUJEO------------------------------------------------------------------------*/

void burbujeo()
{

    for(i = 0; i < sizeC - 1; i++)
        {
            if(autosO[i].flagAlta == OK)
            {
                for(j = 0; j < sizeC; j++)
                {

                    if(autosO[j].flagAlta == OK)
                    {
                        if(strcmp(autosO[i].modelo, autosO[j].modelo) < 0)
                        {
                            aux = autosO[i];
                            autosO[i] = autosO[j];
                            autosO[j] = aux;

                        }
                    }
                }

            }
        }


}





/**---------------------------------------------------------ALTA--------------------------------------------------------------------*/


int AltaDeCliente(ArrayList* clienteList)
{
    int returnAux = DENIED, id;
    sCliente* cliente;

    if(clienteList == NULL) return returnAux;

    id = C_getId(clienteList);

    printf("ingrese los datos del cliente: \n\n");
    cliente = C_cargarCliente(id);

    returnAux = clienteList->add(clienteList, cliente);

    return returnAux;

}







sCliente* C_cargarCliente(int id)
{
    sCliente* cliente;

    char nombre[100];
    char apellido[100];
    int documento;
    printf("ingrese un nombre:");
    cargarCaracter(100, nombre);

    printf("ingrese el apellido:");
    cargarCaracter(100, apellido);

    printf("ingrese el documneto");
    scanf("%d",&documento);

    cliente = C_contructParamClientes(id,nombre, apellido, documento);

    return cliente;
}


sCliente* C_contructParamClientes(int id, char nombre[], char apellido[], int documento)
{
    sCliente* cliente;

    cliente =(sCliente*) malloc(sizeof(sCliente));

    if(cliente != NULL)
    {
        cliente->idCliente = id;

        cliente->nombre = dinamicCharacter(nombre);
        cliente->apellido = dinamicCharacter(apellido);

        cliente->documento = documento;

    }

    return cliente;
}



/**------------------------------------------------------------------------------------------------------*/



/**---------------------------------------------------------BAJA--------------------------------------------------------------------*/


int bajaDeCliente(ArrayList* clienteList)
{
    int i, returnAux = DENIED;
    sCliente* cliente;

    if(clienteList == NULL) return returnAux;

    if(clienteList->isEmpty(clienteList) != OKP)
    {
        i = Tools_getIndex(clienteList, function?);

        cliente = clienteList->pop(clienteList, i);

        if(cliente != NULL)
        {
            printf("el cliente:");
            C_showCliente(cliente);
            printf("ha sido eliminado\n");
            returnAux = OK;
        }
    }
    else
    {
        printf("isEmpty!!!\n");
        returnAux = OK;
    }

    return returnAux;
}


int C_getIndex(ArrayList* clientetList)
{
    int i = DENIED, id;
    sCliente* cliente;

    if(clientetList == NULL) return i;

    C_showAllClientes(clientetList, C_showClienteId);

    printf("ingrese el id:");
    scanf("%d", &id);


    for(i = 0; i < clientetList->len(clientetList);i++)
    {
        cliente = (sCliente*) clientetList->get(clientetList, i);

        if(cliente->idCliente = id) break;

    }

    return i;
}


/**------------------------------------------------------------------------------------------------------*/


///**-------------------------------------shows------------------------------------------------*/

void C_showAllClientes(ArrayList* clienteList, void (*funcion)(sCliente*))
{
    int i;

    sCliente* cliente;



    for(i = 0; i < clienteList->len(clienteList); i++)
    {

        cliente = clienteList->get(clienteList, i);

        funcion(cliente);

        printf("\n");

    }

}

void C_showCliente(sCliente* cliente){printf("%s %s", cliente->nombre, cliente->apellido);}

void C_showClienteData(sCliente* cliente)
{
    printf("----------------------------------------------------------------------\n\n");
    printf("cliente: %s %s\n\n", cliente->apellido, cliente->nombre);
    printf("DNI:%d\n\n", cliente->documento);

}

void C_showClienteId(sCliente* cliente)
{
    printf("%d)%s %s", cliente->idCliente, cliente->nombre, cliente->apellido);
}



///**-----------------------------------------------------------------------------------------*/


int buscarEspcioStruct(sSong canciones[], int size)
{
    int i;

    for(i = 0; i<size; i++) if(canciones[i].flagAlta == DENEID) break;

    if(i == size) i = DENEID;

    return i;

}






int numValidado(char messages[], int ground, int top)
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





int charAddDinamic(char* caracter)
{
    int len, returnAux = DENEID;
    char* aux;

    caracter = (char*) malloc(sizeof(char) * 1024);

    if(caracter == NULL) return returnAux;

    fflush(stdin);
    scanf("%1023[^\n]", caracter);

    len = strlen(caracter);

    aux = (char*) realloc(caracter, sizeof(char*)* len+1);

    if(aux != NULL)
    {
        caracter = aux;
        returnAux = OK;
    }

    return returnAux;
}



void vaciar(int size, char string[size])
{
    int i;

    for(i = 0; i < size; i++)
        string[i] = '\0';


}


char* dinamicCharacter(char character[])
{
    char* chars;
    int len;

    len = strlen(character);

    chars = (char*) malloc(sizeof(char)*(len+1));

    strcpy(chars, character);


    return chars;
}


void fgetsToChar(FILE* pFile, int size, char string[size], char To)
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

/**-------------------------------------------------baja----------------------------------------------------------------------------*/


int getIndex(sAuto autos[], int sizeA)
{
    int i, returnAux = DENEID;

    for(i = 0; i < sizeA; i++)
    {
        if(autos[i].flagAlta == OK)
        {
            printf("%d)%s\n",(i+1), autos[i].patente);
        }

    }

    printf("ingrese opcion:");
    scanf("%d", &i);
    i--;

    if(autos[i].flagAlta == OK) returnAux = i;

    return returnAux;
}


/**---------------------------------------------------------------*/

int bajaSauto(sAuto autos[], int sizeA)
{
    int i, index, returnAux = DENEID;
    printf("elija cual es el auto que va a dar de baja");

    index = getIndex(autos, sizeA);

    if(index != DENEID)
    {
        autos[index].flagAlta = DENEID;
        returnAux = OK;

        for(i = index; i < sizeA - 1; i++)
        {
            autos[i] = autos[i+1];
        }
        autos[i].flagAlta = DENEID;
    }

    return returnAux;
}


/**-------------------------------------------------CONSTRUCTOR----------------------------------------------------------------------------*/


void VaciarStruct(sSong canciones[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        canciones[i].flagAlta = DENEID;
    }


}


/**---------------------------------------------------------------*/

Struct* contructor1(char string[1024], int entero)
{
    int len;
    Struct* construir;

    construir = (Struct*) malloc(sizeof(Struct));

    if(construir == NULL) return construir;

    construir->string = (char*) malloc(sizeof(char)*(strlen(string) + 1));


    strcpy(construir->string, string);
    construir->entero = entero;

    return construir;

}

/**------------------------------------------------------micelaneos--------------------------------------------------------------*/

int indexIdsAuto(int idDuenio, sAuto autos[], int sizeA)
{
    int i;

    for(i = 0; i < sizeA; i++)
        if(idDuenio == autos[i].idDuenio) break;


    return i;
}


void showDataSAuto(sAuto autos[], int sizeA)
{
    int i;

    for(i = 0; i < sizeA; i++)
    {
        if(autos[i].flagAlta == OK)
        {


            printf("patente:%s---modelo:%s---marca:", autos[i].patente, autos[i].modelo);

/*
            switch(autos[i].marca)
            {
                case FIAT:
                    printf("fiat\n");
                    break;

                case PEUGEOT:
                    printf("peugeot\n");
                    break;
                case FORD:
                    printf("ford\n");
                    break;
                case OTROS:
                    printf("otros\n");
                    break;
*/
            }
        }
    }


}



/**----------------------------------------------------ARCHIVOS-------------------------------------------------------------------------*/


////////////////////////////////////////////////////////////////////////////////////BINARIOS

int ListToFile()
{
    FILE* file;
    int returnAux = DENEID, index;

    SUser* user;

    user = (SUser*) malloc(sizeof(SUser));

    file = fopen("dataUser.dat", "w+b");

    if(file == NULL || userList == NULL)
    {
        fclose(file);
        return returnAux;
    }


    for(index = 0; index < userList->len(userList); index++)
    {
        user =(SUser*) userList->get(userList, index);

        fwrite(user, sizeof(SUser), 1 ,file);

    }



    fclose(file);
    return returnAux;
}



int fileToList(ArrayList* movieList)
{
    FILE* file;
    int returnAux = DENEID, index, size;

    EMovie* movie;



    file = fopen("data.dat", "rb");

    if(file == NULL || movieList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    fseek(file, 0 , SEEK_END);

    size = ftell(file)/sizeof(EMovie);

    rewind(file);

    for(index = 0; index<size; index++)
    {
        movie = (EMovie*) malloc(sizeof(EMovie));

        fread(movie, sizeof(EMovie), 1,file);

        returnAux = movieList->add(movieList, movie);
        if(returnAux == DENEID) break;

    }
/*
    len = showMovieListIndex(movieList);
        if(len == DENEID) printf("Error en la funcion showMovieList");*/

    fclose(file);
    return returnAux;
}


//////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////TEXTO
int Song_fileToListText(char path[], ArrayList* playList)
{
    FILE* pFile;

    int returnAux = DENIED;
    char id[101], nombre[101], albun[101], artista[101], visitas[101], duracionSeg[101];
    SSong* music;

    pFile = fopen(path, "r");

    if(playList == NULL || pFile == NULL) return returnAux;

    fgets(nombre, 101, pFile);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, albun, artista, visitas, duracionSeg);
        music = Song_contructor(atoi(id), nombre, artista,albun, atoi(duracionSeg));
        music->visit = visitas;

        returnAux = playList->add(playList, music);
    }

    fclose(pFile);

    return returnAux;
}



int Song_listToFileText(char path[], ArrayList* playList)
{
    FILE* pFIle;
    int i, returnAux = DENIED;
    SSong* music;

    pFIle = fopen(path, "w+");

    if(playList == NULL || pFIle == NULL) return returnAux;

    fprintf(pFIle, "id,nombre,albun,artista,visitas,durationSeg\n");

    for(i = 0; i < playList->len(playList); i++)
    {
        music = (SSong*) playList->get(playList, i);
        if(music != NULL)
        {
            fprintf(pFIle, "%d,%s,%s,%s,%d,%d\n", music->id, music->name, music->Albun, music->Artist, music->visit,music->durationSeg);
            returnAux = OK;
        }
    }

    fclose(pFIle);

    return returnAux;
}


///////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////TEXTO




/**---------------------------------------------------------------------------------*/





/**---------------------------------------------------------SORT--------------------------------------------------------------------*/

int compareMovie(void* MovieA, void* MovieB)
{

    if(((EMovie*)MovieA)->puntaje < ((EMovie*)MovieB)->puntaje)
    {
        return 1;
    }


    if(((EMovie*)MovieA)->puntaje > ((EMovie*)MovieB)->puntaje)
    {
        return -1;
    }

    if(((EMovie*)MovieA)->puntaje == ((EMovie*)MovieB)->puntaje)
    {
        if(strcmp(((EMovie*)MovieA)->titulo, ((EMovie*)MovieB)->titulo) == 1)
        {
            return 1;
        }
        else
        {
            return -1;
        }

    }


    return 0;


}



int C_compareCliente(void* clienteA, void* clienteB)
{

    if(strcmp(((sCliente*)clienteA)->apellido, ((sCliente*)clienteB)->apellido ) < 0)
    {
        return -1;
    }

    if(strcmp(((sCliente*)clienteA)->apellido, ((sCliente*)clienteB)->apellido ) > 0)
    {
        return 1;
    }


    if(strcmp(((sCliente*)clienteA)->apellido, ((sCliente*)clienteB)->apellido ) == 0)
    {

        if(strcmp(((sCliente*)clienteA)->nombre, ((sCliente*)clienteB)->nombre ) < 0)
        {
            return -1;
        }

        if(strcmp(((sCliente*)clienteA)->nombre, ((sCliente*)clienteB)->nombre ) > 0)
        {
            return 1;
        }

    }
}




