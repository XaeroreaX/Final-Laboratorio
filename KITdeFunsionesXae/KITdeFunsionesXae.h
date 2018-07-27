typedef struct
{
    char nombre[20];
    char telefono[20];
    char nacionalidad[40];
    int edad, dni;
    float altura, peso;

}SPersona;
/** \brief estructura de una persona
 *
 * \param vector(20) de caracteres que representa el nombre
 * \param vector(20) de caracteres que representa el telefono
 * \param vector(40) de caracteres que representa la nacionalidad
 * \param entero que representa la edad
 * \param entero que representa el DNI
 * \param flotante que representa la altura
 * \param flotante que representa el peso
 * \struct
 *
 */




SPersona HarcodearS(char[], char[], char[], int, int, float, float);
/** \brief harcodea a una estructura de tipo SPersona con argumentos
 *
 * \param vector(20) de caracteres que representa el nombre
 * \param vector(20) de caracteres que representa el telefono
 * \param vector(40) de caracteres que representa la nacionalidad
 * \param entero que representa la edad
 * \param entero que representa el DNI
 * \param flotante que representa la altura
 * \param flotante que representa el peso
 * \return
 *
 */

 SPersona cargarPersona(int, SPersona[]);
 /** \brief una funsion que cargar una estructura de tipo persona
  *
  * \param entero que representa el tamaño
  * \param y un vector de SPersona
  * \return SPersona cargado
  *
  */


void HarcodearSArray(SPersona[]);
/** \brief harcodea un vector de tipo estructura(5 elementos)
 *
 * \param un vector de tipo SPersona
 * \return el vector SPersona ya harcodeado
 *
 */


void MostrarS(SPersona);
/** \brief muestra toda la informacion de tipo SPersona
 *
 * \param un dato de tipo SPersona
 *
 */


