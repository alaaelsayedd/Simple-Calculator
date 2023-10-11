/*
 * KeyPad_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: zas
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#define KPD_PORT  GROUPC
#define KPD_NOPRESSEDkEY  0xff

#define KPD_COL_PIN0    PIN_0
#define KPD_COL_PIN1    PIN_1
#define KPD_COL_PIN2    PIN_2
#define KPD_COL_PIN3    PIN_3

#define KPD_ROW_PIN0    PIN_4
#define KPD_ROW_PIN1    PIN_5
#define KPD_ROW_PIN2    PIN_6
#define KPD_ROW_PIN3    PIN_7
/*
 *  /:24
 *  *:25
 *  -:26
 *  =: 27
 *  +:28
 *  ON/OFF:29
 */
#define KPD_ARR  {{7,8,9,24},{4,5,6,25},{1,2,3,26},{29,0,27,28}}
#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
