#ifndef SCANNER_H
#define SCANNER_H

// Definicion de un tipo de dato TOKEN, que consiste en un enum llamado Token_t formado por toda esa lista de elementos.
// Que una variable sea un enum, significa que contiene uno de los elementos que forma la lista de dicho enum.
typedef enum Token_t {
    RESERVADA_TOKEN,
    ID_TOKEN,
    CONSTANTE_TOKEN,
    PARENTESIS_IZQUIERDO_TOKEN,
    PARENTESIS_DERECHO_TOKEN,
    PUNTO_Y_COMA_TOKEN,
    COMA_TOKEN,
    ASIGNACION_TOKEN,
    SUMA_TOKEN,
    RESTA_TOKEN,
    FIN_DE_TEXTO_TOKEN,
} TOKEN;

// Definicion de un tipo de dato ESTADO que es un entero.
typedef int ESTADO;

// Definicion de tipo de dato SIMBOLO que consiste en un enum llamado Simbolo_t formado por toda esa lista de elementos.
typedef enum Simbolo_t {
    LETRA_SIMBOLO,
    DIGITO_SIMBOLO,
    SUMA_SIMBOLO, 
    RESTA_SIMBOLO,
    PARENTESIS_IZQUIERDO_SIMBOLO,
    PARENTESIS_DERECHO_SIMBOLO,
    COMA_SIMBOLO,
    PUNTO_Y_COMA_SIMBOLO,
    DOS_PUNTOS_SIMBOLO,
    IGUAL_SIMBOLO,
    FIN_DE_TEXTO_SIMBOLO,
    ESPACIO_SIMBOLO,
    OTRO_SIMBOLO,
} SIMBOLO;

/* Declaracion de funcion Buffer:
    Devuelve un puntero a una cadena de caracteres constante (const char *).
    No espera argumentos (void)
Cuando llamemos a Buffer, obtendremos un puntero a una cadena de caracteres que no podemos cambiar */
const char *Buffer(void);

// Declaracion/prototipo de la funcion EsReservada, que no espera ningun argumento (void) y devuelve un TOKEN.
TOKEN EsReservada(void);

// Declaracion de la funcion EsReservadaV2: no epsera ningun argumento (void) y devuelve un entero.
int EsReservadaV2(void);

// Declaracion de la funcion Scanner: no espera ningun argumento (void) y devuelve un TOKEN.
TOKEN Scanner(void);

// Declaracion de la funcion InicializarBuffer: no recibe ni devuelve ningun dato.
void InicializarBuffer(void);

// #define <identificador> <valor>
// Se le indica al compilador que cada vez que vea el identificador (CANTIDAD_PALABRAS_RESERVADAS), lo reemplace por el valor (4)
#define CANTIDAD_PALABRAS_RESERVADAS 4

/* static especificador de clase de almacenamiento. 
Tiene diferentes significados según el contexto. 
Dentro de una función, hace que la variable conserve su valor entre múltiples llamadas a funciones. 
Fuera de una función, restringe la visibilidad de la variable o función al archivo actual. */
// const indica al compilador que no permita que el programador modifique la variable.
// char* -> Puntero a un char.

/* Declaracion y definicion de un arreglo estatico de punteros a cadenas de caracteres constantes.
static: el arreglo palabras_reservadas tiene una duración de almacenamiento estática. 
Esto significa que su vida útil es toda la duración del programa, pero su alcance está limitado al archivo donde se declara (no es accesible fuera de ese archivo).
const char*: cada elemento del arreglo es un puntero a una cadena de caracteres constante, es decir, no se puede modificar el contenido de las cadenas.
palabras_reservadas[]: Se está definiendo un array, pero la cantidad de elementos se deduce automáticamente a partir de las inicializaciones.
{ "inicio", "fin", "leer", "escribir" }: Se están inicializando los elementos del array con las cadenas de caracteres correspondientes. 
Cada cadena se convierte en un puntero a const char que apunta al texto literal.*/
static const char* palabras_reservadas[] = {
    "inicio",
    "fin",
    "leer",
    "escribir"
};

// Poner un asterisco (*) a la izquierda de un puntero, hace que se recupere el valor que hay en dicho puntero (lo opuesto a &)
// Poner un ampersan (&) a la izquierda de una variable, no da la direccion de memoria de dicha variable.
static const char *tokens[] = {
    "PALABRA_RESERVADA",
    "ID",
    "CONSTANTE",
    "PARENTESIS_IZQUIERDO",
    "PARENTESIS_DERECHO",
    "PUNTO_Y_COMA",
    "COMA",
    "ASIGNACION",
    "SUMA",
    "RESTA",
    "FIN_DE_TEXTO"
};



#endif /*SCANNER_H*/
