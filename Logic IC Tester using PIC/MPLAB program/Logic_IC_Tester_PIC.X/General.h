#include"lcd.h"
#include<stdbool.h>
unsigned int gate[6]={1,1,1,1,1,1};
const unsigned int truth[6]={110,11000,11110,10001,10111,10110};
const char name[11][5]={"7404","7402","7400","7408","7432","7486","10","11","27","4075"};
unsigned int i,j,k,n=9,l,x;  //n=current IC pointer  i,j,k,x is for general operation
bool x1,x2,x3;
bool gate1[8]={0,0,0,0,0,0,0,0};
bool gate2[8]={0,0,0,0,0,0,0,0};
bool gate3[8]={0,0,0,0,0,0,0,0};
bool AND_3[8]={0,0,0,0,0,0,0,1};
bool OR_3[8]={0,1,1,1,1,1,1,1};
//-------------------------------Global variable----------------------------
#define TP1 TRISB0
#define TP2 TRISD7
#define TP3 TRISD6
#define TP4 TRISD5
#define TP5 TRISD4
#define TP6 TRISD3
#define TP7 TRISD2
#define TP13 TRISB7
#define TP14 TRISB6
#define TP15 TRISB5
#define TP16 TRISB4
#define TP17 TRISB3
#define TP18 TRISB2
#define TP19 TRISB1

#define P1 RB0
#define P2 RD7
#define P3 RD6
#define P4 RD5
#define P5 RD4
#define P6 RD3
#define P7 RD2
#define P13 RB7
#define P14 RB6
#define P15 RB5
#define P16 RB4
#define P17 RB3
#define P18 RB2
#define P19 RB1
//----------------------------TTL_Logic-------------------------------------------
void Mode_4(void);
void Write_IC(void);
void Test(unsigned int);
void print(unsigned int n,unsigned int no);
void LCD_Write_Integer(int);
void Mode_6(void);
void Mode_3(void);
void Auto(void);
void gate_1(void);
bool is_all_good(unsigned int n,unsigned int no);
//extern const char name[10][5];
//extern unsigned int n;
void TRI_NAN(unsigned int ic_num); //Triple NAND AND OR
bool TRI_GOOD(unsigned int ic_num);
//-------------------------------