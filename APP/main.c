/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: zas
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/PORT/PORT_interface.h"
#include "../MCAL/GRIO/DIO_Interface.h"
#include "../HAL/CLCD/CLCD_Interface.h"
#include "../HAL/KeyPad/Keypad_Interface.h"
#include "CALC/CLAC_Interface.h"
void main()

{    PORT_voidInit() ;
     CLCD_void_Init();
	u32 Number1,Number2,Result;
    u8 Sign;


	while(1)
	{

		Result= CALC_u8TakeNumber(&Number1,&Sign,&Number2);
    if(Result!=-1 )
    {
    	CLCD_voidSendNumber(Result);
    }

	}
}
