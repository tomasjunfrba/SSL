#ifndef SCANNER_H
#define SCANNER_H

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

typedef int ESTADO;

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

const char *Buffer(void);

TOKEN EsReservada(void);

int EsReservadaV2(void);

TOKEN Scanner(void);

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
