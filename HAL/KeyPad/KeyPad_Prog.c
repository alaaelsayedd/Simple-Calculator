/*
 * KeyPad_Prog.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: zas
 */
#include "Keypad_Interface.h"
u8 KPD_u8GetPressedKey(void)
{
    u8 Local_u8KeyPressed=KPD_NOPRESSEDkEY,Local_u8ColIndex,Local_u8RowIndex,Local_u8PinValue;
     static u8 Local_u8ColArr[KPD_COL_NUM]={KPD_COL_PIN0,KPD_COL_PIN1,KPD_COL_PIN2,KPD_COL_PIN3};
     static u8 Local_u8RowArr[KPD_ROW_NUM]={KPD_ROW_PIN0,KPD_ROW_PIN1,KPD_ROW_PIN2,KPD_ROW_PIN3};
     static u8 Local_u8ARR[KPD_ROW_NUM][KPD_COL_NUM]=KPD_ARR;
      for (Local_u8ColIndex=0;Local_u8ColIndex < KPD_COL_NUM;Local_u8ColIndex++)
      {
    	  DIO_vSetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColIndex],LOW);
    	  for (Local_u8RowIndex=0;Local_u8RowIndex < KPD_COL_NUM;Local_u8RowIndex++)
    	   {
    		  Local_u8PinValue=DIO_u8ReadPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIndex]);
    		   if(LOW==Local_u8PinValue)
    		    {
    			   Local_u8KeyPressed=Local_u8ARR[Local_u8RowIndex][Local_u8ColIndex];

    		   while(LOW==Local_u8PinValue)
    		   {
    			   Local_u8PinValue=DIO_u8ReadPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIndex]);

    		   }
    		   return Local_u8KeyPressed;

    	   }
    	   }
    	  DIO_vSetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColIndex],HIGH);
      }

return Local_u8KeyPressed;
}

