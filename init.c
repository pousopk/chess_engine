#include "defs.h"
#include "stdio.h"
int Sq120toSq64[BRD_SQ_NUM];
int Sq64toSq120[64];

void InitSq120to64 (){
    int index = 0;
    int fila = FILA_A;
    int columna = COLUMNA_1;
    int sq = A1;
    int sq64 = 0;
    //Init imposible values in the 120 to 64 array to fail-check/debug
    for (index = 0; index < BRD_SQ_NUM;++index ){
        Sq120ToSq64[index] = 65;
    }
    //Init imposible values in the 64 to 120 array to fail-check/debug
    for (index = 0; index < 64;++index ){
        Sq64ToSq120[index] = 120;
    }

    for(columna=COLUMNA_1; columna <=COLUMNA_8;++columna){
        for(fila = FILA_A; fila <= FILA_G;++fila){
            sq = FR2SQ(fila,columna);
            Sq64ToSq120[sq64] = sq;
            Sq120ToSq64[sq]= sq64;
            sq64++;
        }
    }
}

void AllInit(){
    InitSq120to64();
}