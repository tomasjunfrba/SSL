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

// Definicion de un puntero (????)
const char *Buffer(void);

// Declaracion/prototipo de la funcion EsReservada, que no recibe ningun tipo de dato (void) y devuelve un TOKEN.
TOKEN EsReservada(void);

// Declaracion de la funcion EsReservadaV2: no recibe ningun dato y devuelve un entero.
int EsReservadaV2(void);

// Declaracion de la funcion Scanner: no recibe ningun dato y devuelve un TOKEN.
TOKEN Scanner(void);

// Declaracion de la funcion InicializarBuffer: no recibe ni devuelve ningun dato.
void InicializarBuffer(void);


#define CANTIDAD_PALABRAS_RESERVADAS 4
static const char* palabras_reservadas[] = {
    "inicio",
    "fin",
    "leer",
    "escribir"
};

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
