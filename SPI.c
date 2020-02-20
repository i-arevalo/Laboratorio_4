#include <stdint.h>
#include <xc.h>
#include <pic16f887.h>

#define _XTAL_FREQ 4000000

void spi_conf(uint8_t op){
    switch (op){
        //maestro recibe
        case 1:
            TRISCbits.TRISC5 = 0;
            SSPSTATbits.SMP = 0;
            SSPSTATbits.CKE = 0;
            SSPCONbits.SSPEN = 1;
            SSPCONbits.CKP = 0;
            
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 0;
            SSPCONbits.SSPM1 = 0;
            SSPCONbits.SSPM0 = 0;
            TRISCbits.TRISC3 = 0;
            break;
        //esclavo envia
        case 2:
            TRISCbits.TRISC5 = 0;
            SSPSTATbits.SMP = 0;
            SSPSTATbits.CKE = 0;
            SSPCONbits.SSPEN = 1;
            SSPCONbits.CKP = 0;
            
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 1;
            SSPCONbits.SSPM1 = 0;
            SSPCONbits.SSPM0 = 1;
            TRISCbits.TRISC3 = 1;
            break;
    }
}

void spi_escribir(char dato){
    SSPBUF = dato;
}

uint8_t spi_puede_leer(void){
    if (SSPSTAT & 00000001)
        return 1;
    else
        return 0;
}

char spi_leer(void){
    return (SSPBUF);
}
