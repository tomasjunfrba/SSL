#include <stdio.h>
#include "scanner.h"

int main(void) {
    TOKEN t;
    while ((t = Scanner()) != FIN_DE_TEXTO_TOKEN) {
        printf("%s -> %s\n", tokens[t], Buffer());
    }
}

/* Alternativa usando EsReservadaV2()
int main(void) {
    TOKEN t;
    puts("TOKEN\tLEXEMA\t\tRESERVADA?");
    while ((t = Scanner()) != FIN_DE_TEXTO_TOKEN) {
        printf("%d\t%s\t\t%d\n", t, Buffer(), EsReservadaV2());
    }
}
*/
