#ifndef DEFS_H
#define DEFS_H

typedef unsigned long long U64;

#define NAME "Chess engine 1.0"
#define BRD_SQ_NUM 120
//Should be enough to store all the half moves of a game

#define MAXGAMEMOVES 2048

enum {VACIO, wP,wN,wB,wQ,wK,wR,bP,bN,bB,bQ,bK,bR};
enum {FILA_A,FILA_B,FILA_C,FILA_D,FILA_E,FILA_F,FILA_G,FILA_NONE};
enum {COLUMNA_1,COLUMNA_2,COLUMNA_3,COLUMNA_4,COLUMNA_5,COLUMNA_6,COLUMNA_7,COLUMNA_8,COLUMNA_NONE};

enum{BLANCAS,NEGRAS,AMBAS};

enum {
A1= 21,B1,C1,D1,E1,F1,G1,H1,
A2= 31,B2,C2,D2,E2,F2,G2,H2,
A3= 41,B3,C3,D3,E3,F3,G3,H3,
A4= 51,B4,C4,D4,E4,F4,G4,H4,
A5= 61,B5,C5,D5,E5,F5,G5,H5,
A6= 71,B6,C6,D6,E6,F6,G6,H6,
A7= 81,B7,C7,D7,E7,F7,G7,H7,
A8= 91,B8,C8,D8,E8,F8,G8,H8,NO_SQ
};

enum {FALSE,TRUE};
//To check if we can castle (1 0 0 1 implies that white can only castle king side and black can only castle queen side )
enum {WKCA = 1, WQCA = 2 , BKCA = 4 , BQCA = 8};

typedef struct 
{
    int move;
    int castlePerm;
    int enPas;
    int fiftyMove;
    U64 posKey;
} S_UNDO;

typedef struct {

    int piezas[BRD_SQ_NUM];
    U64 pawns[3]; // Set to 1 when there is a pawn
//Square where the king is position for both colors
    int kingSq[2];
//To keep track of the side, en-passant square active and fifty move rule
    int side;
    int enPas;
    int fiftyMove;
//To keep track of the move number
    int ply;
    int hisPly;

    int castlePerm;
//Position KEY
    U64 posKey;
//Nº of pieces by type both colors and empty squares
    int pceNum[13];
//Nº of pieces by total diff between big, major and minor for both colors and total
    int bigPce[3];
    int majPce[3];
    int minPce[3];
//Store the move that is going to be made
    S_UNDO history[MAXGAMEMOVES];

} S_TABLERO;

//GLOBALS

extern int Sq120ToSq64[BRD_SQ_NUM];
extern int Sq64ToSq120[64];
//MACROS
#define FR2SQ(f,r) ((21+(f))+((r)* 10))
//FUNCIONS
extern void AllInit();
#endif