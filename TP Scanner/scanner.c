/*
#include <stdio.h>: Para la entrada/salida estándar.
#include <ctype.h>: Para funciones relacionadas con caracteres (como verificar si son dígitos o letras).
#include <string.h>: Para manipulación de cadenas (como comparar cadenas).
#include <errno.h>: Para manejar errores.
#include "scanner.h" y #include "tablaDeTransiciones.h": Contienen definiciones y declaraciones específicas para el escáner y la tabla de transiciones.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "scanner.h"
#include "tablaDeTransiciones.h"
#include <errno.h>

// Define el tamaño del buffer que almacenará caracteres leídos.
#define TAMANIO_BUFFER 20

// _buffer y _pos: Usados para almacenar y rastrear la posición en el buffer.
char _buffer[TAMANIO_BUFFER+1];
int  _pos = 0;

//  Limpia el buffer inicializándolo a ceros.
void InicializarBuffer(void)
{
    memset(_buffer, 0, TAMANIO_BUFFER);
}

// Limpia el contenido del buffer y resetea la posición.
void LimpiarBuffer(void) {
    memset(_buffer, 0, _pos + 1);
    _pos = 0;
}

// Agrega un carácter al buffer y avanza la posición.
void AgregarCaracter(int caracter) {
    _buffer[_pos++] = caracter;
}

//Termina la cadena en el buffer añadiendo un carácter nulo y devuelve el contenido del buffer.
const char *Buffer(void) {
    _buffer[_pos] = '\0';
    return _buffer;
}

// Identificacion de palabras reservadas: Comprueba si el contenido del buffer es una palabra reservada, devolviendo un token específico si lo es.
TOKEN EsReservada(void) {
    for(int i=0; i < CANTIDAD_PALABRAS_RESERVADAS; i++){
        if(!strcmp(_buffer, palabras_reservadas[i])){
            return RESERVADA_TOKEN;
        }
    }
    return ID_TOKEN;
}

// Variante que retorna 1 si es una palabra reservada y 0 si no.
int EsReservadaV2(void) {
    for (int i = 0; i < CANTIDAD_PALABRAS_RESERVADAS; i++) {
        if (strcmp(_buffer, palabras_reservadas[i]) == 0) {
            return 1;  // Es Reservada
        }
    }
    return 0;  // No es Reservada
}

// Obtencion de columna: Clasifica el carácter recibido y devuelve un tipo de SIMBOLO.
SIMBOLO ObtenerColumna(int simbolo) {
    if (isalpha(simbolo)) {
        return LETRA_SIMBOLO;
    } else if (isdigit(simbolo)) {
        return DIGITO_SIMBOLO;
    } else if (simbolo == '+') {
        return SUMA_SIMBOLO;
    } else if (simbolo == '-') {
        return RESTA_SIMBOLO;
    } else if (simbolo == '(') {
        return PARENTESIS_IZQUIERDO_SIMBOLO;
    } else if (simbolo == ')') {
        return PARENTESIS_DERECHO_SIMBOLO;
    } else if (simbolo == ',') {
        return COMA_SIMBOLO;
    } else if (simbolo == ';') {
        return PUNTO_Y_COMA_SIMBOLO;
    } else if (simbolo == ':') {
        return DOS_PUNTOS_SIMBOLO;
    } else if (simbolo == '=') {
        return IGUAL_SIMBOLO;
    } else if (simbolo == -1) {
        return FIN_DE_TEXTO_SIMBOLO;
    } else if (isspace(simbolo)) {
        return ESPACIO_SIMBOLO;
    }    
    return OTRO_SIMBOLO;
}

// Transicion de estados: Usa la tabla de transiciones para determinar el siguiente estado basado en el estado actual y el símbolo.
ESTADO Transicion(ESTADO estado, int simbolo) {
    int columna = ObtenerColumna(simbolo);
    return TablaDeTransiciones[estado][columna];
}

// Funcion principal del scanner: Es la función que realiza el escaneo. Lee caracteres de la entrada estándar, actualiza el estado y el buffer, y devuelve el token correspondiente basado en el estado final.
TOKEN Scanner(void) {
    int c, pos = 0;
    ESTADO estado = 0;
    LimpiarBuffer();
    while (c=getchar()) {
        estado = Transicion(estado, c);
        switch (estado) {
            case 1:
            case 3:
                AgregarCaracter(c);
                break;
            case 2:
                ungetc(c, stdin);
                return EsReservada(); /* ID o RESERVADA*/
            case 4:
                ungetc(c, stdin);
                return CONSTANTE_TOKEN; /* CONSTANTE */
            case 5:
                AgregarCaracter(c);
                return SUMA_TOKEN; /* SUMA */
            case 6:
                AgregarCaracter(c);
                return RESTA_TOKEN; /* RESTA */
            case 7:
                AgregarCaracter(c);
                return PARENTESIS_IZQUIERDO_TOKEN;  /* PARENIZQUIERDO */
            case 8:
                AgregarCaracter(c);
                return PARENTESIS_DERECHO_TOKEN;  /* PARENDERECHO */
            case 9:
                AgregarCaracter(c);
                return COMA_TOKEN;  /* COMA */
            case 10:
                AgregarCaracter(c);
                return PUNTO_Y_COMA_TOKEN;  /* PUNTOYCOMA */
            case 11:
                AgregarCaracter(c);
                break;
            case 12:
                AgregarCaracter(c);
                return ASIGNACION_TOKEN; /* ASIGNACION */
            case 13:
                return FIN_DE_TEXTO_TOKEN; /* FDT */
            case -1:
                errno = EINVAL; // EPERM operacion no permitida
                perror("Error lexico"); /* ERROR */

        }
    }
}
