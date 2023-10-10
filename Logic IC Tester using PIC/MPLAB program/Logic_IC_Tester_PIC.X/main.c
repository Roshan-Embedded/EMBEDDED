//Programmer : ROSHAN NT
//AIM : To test all possible input and output for every single gate in the Logic IC
//Program is written in the basic of testing 16 pin IC's in future
#include <xc.h>
#include "config.h"
#include "lcd.h"    
#include "General.h" 
#include <pic16f877a.h>
void main(void){
  TRISA0=1;
  TRISA1=1;
  TRISA2=1;
  TRISA3=1;
  TRISA4=1;
  ADCON0=0X00;
  ADCON1=0X06;
  LCD_Init(); // Initialize LCD module with I2C address = 0x4E
  LCD_Clear();
  LCD_Set_Cursor(1, 1);
  LCD_Write_String("IC TESTER");
  while(1)
  {
      if(RA4==1)
      {
          n = (n + 1) % 10;
          Write_IC();
          LCD_Write_String(name[n]);
          __delay_ms(300);
      }
      if(RA3==1)
      {
          n = (n -1+10) % 10;
          Write_IC();
          LCD_Write_String(name[n]);
          __delay_ms(300);
      }
      if(RA1==1)
      {
          Write_IC();
          LCD_Write_String(name[n]);
          Test(n);
          __delay_ms(300);
      }
      if(RA0==1)
      {
          LCD_Clear();
          LCD_Set_Cursor(1, 1);
          LCD_Write_String("IC Auto...");
          Auto();
          __delay_ms(300);
      }
      if(RA2==1)
      {
      }
  }
  return;
}
void Test(unsigned int n)
{
    if(n==0){
        Mode_6();
        print(0,6);
        gate_1();}
    else if(n>0&&n<6){
        Mode_4();
        print(n,4);
        gate_1();}
    else if(n>5){
        TRI_NAN(n);
    }
            
}
//sprintf(charNum, "%d",gate[1]);
//LCD_Write_String(charNum);
