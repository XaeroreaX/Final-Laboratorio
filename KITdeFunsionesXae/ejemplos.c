

/**------------------------------------------show---------------------------------------------*/

void C_showCliente(void* StructIt){printf("%s %s", ((sClient*)StructIt)->nombre, ((sClient*)StructIt)->apellido);}

void C_showClienteData(void* StructIt)
{
    printf("----------------------------------------------------------------------\n\n");
    printf("cliente: %s %s\n\n", ((sClient*)StructIt)->apellido, ((sClient*)StructIt)->nombre);
    printf("DNI:%d\n\n", ((sClient*)StructIt)->documento);

}

void C_showClienteId(void* StructIt)
{
    printf("%d)%s %s", ((sClient*)StructIt)->idCliente, ((sClient*)StructIt)->nombre, ((sClient*)StructIt)->apellido);
}


/**----------------------------------------------------------------------------------------------*/




int C_getIndex(ArrayList* clienteList)///ejemplo de Tools_getIndex
{
    int i = DENIED, id;
    sCliente* StructIt;

    if(clientetList == NULL) return i;

    Tools_showList(clientetList, C_showClienteId);

    printf("ingrese el id:");
    scanf("%d", &id);


    for(i = 0; i < clientetList->len(clientetList);i++)
    {
        StructIt = (sCliente*) clientetList->get(clientetList, i);

        if(StructIt->idCliente = id) break;

    }

    return i;
}

int C_getId(void* StructIt){return ((sClient*)StructIt)->idCliente;} ///ejemplo de Tools_NexIdUnrepeatable



/**----------------------------------------------------ARCHIVOS-------------------------------------------------------------------------*/


////////////////////////////////////////////////////////////////////////////////////BINARIOS

int SUser_SaveBinari(FILE* pFile, ArrayList* userList)
{

    int returnAux = DENEID, index;

    SUser* StructIt;





    if(pFile != NULL && userList != NULL)
    {
        for(index = 0; index < userList->len(userList); index++)
        {
            StructIt =(SUser*) userList->get(userList, index);

            fwrite(StructIt, sizeof(SUser), 1 ,pFile);

        }
    }




    return returnAux;
}



int EMovie_LoadBinari(FILE* pFile, ArrayList* movieList)
{

    int returnAux = DENEID, index, size;

    EMovie* movie;





    if(pFile != NULL || movieList != NULL)
    {
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

    }
/*

    len = showMovieListIndex(movieList);
        if(len == DENEID) printf("Error en la funcion showMovieList");*/

    fclose(file);
    return returnAux;
}


//////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////TEXTO
int SSong_LoadText(FILE* pFile, ArrayList* playList)
{


    int returnAux = DENIED;
    char id[101], nombre[101], albun[101], artista[101], visitas[101], duracionSeg[101];
    SSong* music;



    if(playList != NULL && pFile != NULL)
    {

        fgets(nombre, 101, pFile);

        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, albun, artista, visitas, duracionSeg);
            music = Song_contructor(atoi(id), nombre, artista,albun, atoi(duracionSeg)); ///constructor
            music->visit = visitas;

            returnAux = playList->add(playList, music);
        }

    }



    return returnAux;
}



int SSong_SaveText(FILE* pFile, ArrayList* playList)
{

    int i, returnAux = DENIED;
    SSong* music;



    if(playList == NULL || pFIle == NULL) return returnAux;
    {

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


    }



    return returnAux;
}


///////////////////////////////////////////////////////////////////////////////////////




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


