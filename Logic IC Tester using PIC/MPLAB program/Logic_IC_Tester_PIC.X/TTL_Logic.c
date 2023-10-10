//Function that are required to test the IC
//Auto function test all possibility of various Logic IC

#include <pic16f877a.h>
#include"lcd.h"
#include"General.h"
#include <stdio.h>
#include<stdbool.h>
void Write_IC(void)
{
    LCD_Clear();
    LCD_Set_Cursor(1,1);
    LCD_Write_String("IC  ");
    if(n>5){LCD_Write_String("74");}
}
void Auto(void)
{   //cheking not gate
    gate_1();
    Mode_6();
    if(is_all_good(0,6))
    {
        n=0;
        Write_IC();
        LCD_Write_String(name[0]);
        print(0,6);
        gate_1();
        return;
    }
    //checking NOR-gates
    LCD_Write_Char('.');
    gate_1();
    n=1;
    Mode_4();
    if(is_all_good(1,4))
        {
            Write_IC();
            LCD_Write_String(name[1]);
            print(1,4);
            gate_1();
            return;}
    //checking other IC
    LCD_Write_Char('.');
    gate_1();
    n=2;
    Mode_4();
    for(int i=2;i<6;i++){
        if(is_all_good(i,4)){
            Write_IC();
            LCD_Write_String(name[i]);
            print(i,4);
            return ;}}
    LCD_Set_Cursor(2,1);
    LCD_Write_String("Not Dtc or Bad");
    n=0;
}
void print(unsigned int n,unsigned int no)   //no==no of gates
{
    int num=0;
    char charNum[3];
    LCD_Set_Cursor(2,1);
    j=0;
    for(i=0;i<no;i++)
    {
        if(truth[n]==gate[i])
        {
            num=i+1;
            sprintf(charNum, "%d", num);
            LCD_Write_String(charNum);
            j++;
        }
    }
    if(j>1){LCD_Write_String(" GATE GOOD");}
    if(j==0){LCD_Write_String("IC IS BAD");}
}
bool is_all_good(unsigned int n,unsigned int no)
{
    j=0;
    for(i=0;i<no;i++)
    {
        if(truth[n]==gate[i])
        {
            j++;}}
    if(j==no) return 1;
    else return 0;
}
void Mode_4(void)
{
    k=0;
    if(n==1){
    TP2=TP3=TP5=TP6=TP15=TP14=TP18=TP17=0;
    TP1=TP4=TP16=TP19=1;
    __delay_ms(20);
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            P2=P5=P15=P18=(__bit)i;
            P3=P6=P14=P17=(__bit)j;
            k=(int)P1;
            gate[0]*=10;
            gate[0]+=k;
            k=(int)P4;
            gate[1]*=10;
            gate[1]+=k;
            k=(int)P16;
            gate[2]*=10;
            gate[2]+=k;
            k=(int)P19;
            gate[3]*=10;
            gate[3]+=k;
            __delay_ms(100);
        }}
    }
    else{
    TP1=TP2=TP4=TP5=TP15=TP16=TP18=TP19=0;
    TP3=TP6=TP14=TP17=1;
    __delay_ms(20);
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            P1=P4=P15=P18=(__bit)i;
            P2=P5=P16=P19=(__bit)j;
            k=(int)P3;
            gate[0]*=10;
            gate[0]+=k;
            k=(int)P6;
            gate[1]*=10;
            gate[1]+=k;
            k=(int)P14;
            gate[2]*=10;
            gate[2]+=k;
            k=(int)P17;
            gate[3]*=10;
            gate[3]+=k;
            __delay_ms(100);
        }}}}
void Mode_6(void)
{
    k=0;
    TP1=TP3=TP5=TP15=TP17=TP19=0;
    TP2=TP4=TP6=TP14=TP18=TP16=1;
    __delay_ms(20);
    for(i=0;i<2;i++)
    {
        P1=P3=P5=P15=P17=P19=(__bit)i;
        __delay_ms(50);
        k=(int)P2;
        gate[0]*=10;
        gate[0]+=k;
        k=(int)P4;
        gate[1]*=10;
        gate[1]+=k;
        k=(int)P6;
        gate[2]*=10;
        gate[2]+=k;
        k=(int)P14;
        gate[3]*=10;
        gate[3]+=k;
        k=(int)P16;
        gate[4]*=10;
        gate[4]+=k;
        k=(int)P18;
        gate[5]*=10;
        gate[5]+=k;
        __delay_ms(100);
    }
}
void gate_1(void)
{
    for(i=0;i<6;i++)
    {
        gate[i]=1;
    }
}
void TRI_NAN(unsigned int ic_num){ //Triple NAND AND OR
    x=0;
    LCD_Set_Cursor(2,1);
    if(ic_num==4075){
        TP1=TP2=TP3=TP4=TP5=TP14=TP17=TP18=TP19=0;
        TP16=TP15=TP6=1;}
    else{
    TP1=TP2=TP3=TP4=TP5=TP15=TP16=TP17=TP19=0;
    TP6=TP14=TP18=1;}
    __delay_ms(50);
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                if(ic_num==4075){
                    P19=P1=P3=(__bit)i;
                    P18=P2=P4=(__bit)j;
                    P17=P14=P5=(__bit)k;
                    __delay_ms(10);
                    gate1[x]=P16;
                    gate2[x]=P15;
                    gate3[x]=P6;}
                else{
                P1=P3=P17=(__bit)i;
                P2=P4=P16=(__bit)j;
                P19=P5=P15=(__bit)k;
                __delay_ms(20);
                gate1[x]=P6;
                gate2[x]=P14;
                gate3[x]=P18;}
                
                x++;
                __delay_ms(10);
            }
        }
    }

    if(TRI_GOOD(ic_num)){
        LCD_Write_String("IC IS GOOD");}
    else{LCD_Write_String("IC IS BAD");}
}
bool TRI_GOOD(unsigned int ic_num){
    for(i=0;i<8;i++){
        if(ic_num==6){
            if(gate1[i]==gate2[i]==gate3[i]==AND_3[i]) return 0; //7410
        }
        else if(ic_num==7){
            if(gate1[i]!=gate2[i]!=gate3[i]!=AND_3[i]) return 0;  //7411
        }
        else if(ic_num==8){
            if(gate1[i]==gate2[i]==gate3[i]==OR_3[i]) return 0;  //7427
        }
        else if(ic_num==9){
            if(gate1[i]!=gate2[i]!=gate3[i]!=OR_3[i]) return 0;
        }
        else return 0;
    }
    return 1;
}
