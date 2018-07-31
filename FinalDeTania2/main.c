#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayList.h"
#include "SLetra.h"
#include "Tool.h"
#include "cascara.h"
int main()
{
    int opcion = 0;

    ArrayList* LList = al_newArrayList();

    if(FileList("MOCK_DATA.csv", "r", LList, SLetra_Load) == DENIED)
        printf("Warning");
    do
    {
        printf("1- ALTA \n");
        printf("2- COMPLETAR \n");
        printf("3- Modificar \n");
        printf("5- mostrar\n");
        printf("6- Salir\n");
        printf("ingrese opcion");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");

                if(cascara_Alta(LList) == DENIED)
                    printf("WARNING");

                system("pause");
                break;
            case 2:
                system("cls");

                if(cascara_Completar(LList)!= DENIED) printf("WARNING");
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

                break;
            default:
                system("cls");
                printf("ingreso mal la opcion, por favor ingrese de nuevo");
                system("pause");
                break;


        }
        system("cls");

    }while(opcion != 6);
    return 0;
}
