#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "SLetra.h"
#include "cascara.h"
#define DENIED -1
#define OK 0
#define OKP 1



int main()
{
    char seguir='s';
    int opcion=0, returnAux = DENIED;

    ArrayList* LLetra = al_newArrayList();

    if(SLetra_fileToListText("MOCK_DATA.csv", LLetra) == DENIED)
        printf("WARNING\n\n");

    while(seguir=='s')
        {
            printf("1- Agregar Letra\n");
            printf("2- Borrar Letra\n");
            printf("3- Modificar Letra\n");
            printf("4- comfirmar vocal/consonate");
            printf("5- Listar letra\n");
            printf("6- Salir\n");
            printf("ingrese opcion");

            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    system("cls");

                    if(Cascara_Alta(LLetra) == DENIED)
                        printf("WARNING\n\n");

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

                    switch(Cascara_ConfirmarList(LLetra))
                    {
                        case DENIED:
                            printf("WARNING\n\n");
                            break;
                        case OK:
                            printf("Lista Vacia");
                            break;
                        case OKP:
                            printf("Letras confirmadas");
                    }

                    system("pause");
                   break;
                case 5:
                    system("cls");

                    Cascara_Listar(LLetra);

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


            }
            system("cls");

        }
    return 0;
}
