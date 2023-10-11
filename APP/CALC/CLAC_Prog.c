/*
 * CLAC_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: zas
 */

#include "CLAC_Interface.h"
#include "../../HAL/KeyPad/Keypad_Interface.h"
#include "../../HAL/CLCD/CLCD_Interface.h"

u8 Opr_Sign[5]={'+','-','*','/','='};
/*
 *  /:24
 *  *:25
 *  -:26
 *  =: 27
 *  +:28
 *  ON/OFF:29
 */
u32 CALC_u8TakeNumber(u32* Number1,u8* Opr,u32 *Number2 )
{
	u8 Local_Num;
	u32 Local_ComNum=0;
	u8 i;
	u8 Flag=0;
	u32 Rreult=-1;

do{
	 Local_Num=KPD_u8GetPressedKey();
}
while( Local_Num==KPD_NOPRESSEDkEY);

while(Local_Num<24)
{
	CLCD_voidSendNumber(Local_Num);
	Local_ComNum=Local_ComNum*10+Local_Num;
	do{
		 Local_Num=KPD_u8GetPressedKey();
	}
	while( Local_Num==KPD_NOPRESSEDkEY);


}
switch(Local_Num)
	{
	case 24:
		CLCD_voidSendData('/');
		break;
	case 25:
		CLCD_voidSendData('*');
			break;
	case 26:
		CLCD_voidSendData('-');
			break;
	case 27:
	     CLCD_voidSendData('=');
	     break;
	case 28:
		   CLCD_voidSendData('+');
		   break;
	case 29:
			   CLCD_voidSendCommand(1);
			   break;
	default:
			CLCD_SendString("NO OPRATION");
	}
if(Local_Num==29)
{
	*Number1=0;
	*Number2=0;
	Local_ComNum=0;
	Rreult=-1;
	return Rreult;

}

*Number1=Local_ComNum;
*Opr=Local_Num;
if(*Opr==27)
{
CLCD_voidSendNumber(Local_ComNum);
}
else
{
	Local_ComNum=0;
	do{
		 Local_Num=KPD_u8GetPressedKey();
	}
	while( Local_Num==KPD_NOPRESSEDkEY);

	while(Local_Num<24)
	{
		CLCD_voidSendNumber(Local_Num);
		Local_ComNum=Local_ComNum*10+Local_Num;
		do{
			 Local_Num=KPD_u8GetPressedKey();
		}
		while( Local_Num==KPD_NOPRESSEDkEY);


	}
	*Number2=Local_ComNum;
}
switch(Local_Num)
	{
	case 24:
		CLCD_voidSendData('/');
		break;
	case 25:
		CLCD_voidSendData('*');
			break;
	case 26:
		CLCD_voidSendData('-');
			break;
	case 27:
	     CLCD_voidSendData('=');
	     break;
	case 28:
		   CLCD_voidSendData('+');
		   break;
	case 29:
				   CLCD_voidSendCommand(1);
				   break;
	default:
			CLCD_SendString("NO OPRATION");
	}
if(Local_Num==29)
{
	*Number1=0;
	*Number2=0;
	Local_ComNum=0;
	Rreult=-1;
	return Rreult;

}
if(Local_Num==27)
{
	switch(*Opr)
		{
		case 28:
			Rreult=*Number1+*Number2;
			break;
		case 26:
			Rreult=*Number1-*Number2;
				break;
		case 24:
			Rreult=*Number1 / *Number2;
				break;
		case 25:
			Rreult=*Number1 * *Number2;
				break;
		default:
			CLCD_SendString("NO OPRATION");

		}







}
return Rreult;

}
