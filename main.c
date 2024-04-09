#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Buzzer.h"
#include "Infrared.h"
#include "LED.h"
#include "OLED.h"
#include "Serial.h"


int main(void)
{
	uint8_t i;
	Infrared_Init();
	LED_Init();
	OLED_Init();
	Serial_Init();

//	Serial_Printf("sdf");
	
//	OLED_ShowChar(1, 1, 'A');
//	OLED_ShowNum(2, 1, 12345, 5);
//	OLED_ShowSignedNum(2, 7, -66, 2);
//	OLED_ShowHexNum(3, 1, 0xAA55, 4);
//	OLED_ShowBinNum(4, 1, 0xAA55, 16);
	
	while (1)
	{
//		if (Infrared_Get() == 1)//没有复位
//		{
//			LED1_ON();
//			Serial_Printf("sdf");
//			//OLED_Clear();
//		
//		}
//		else
//		{
//			LED1_OFF();
//			OLED_ShowString(1, 3, "Ready");//复位
//		}
	
//		if (Serial_RxFlag == 1){
//			
//			for(i=0;i<(strlen(Serial_RxPacket)-1);i++){
//			Serial_ShowRxPacket[i]=Serial_RxPacket[i+1];
//			}
//			
//			if(Serial_RxPacket[0] == '1')
//				{
//				OLED_ShowString(1, 1, Serial_ShowRxPacket);	
//				Serial_RxFlag = 0;
//				}
//				if(Serial_RxPacket[0] == '2')
//				{
//				OLED_ShowString(2, 1, Serial_ShowRxPacket);	
//				Serial_RxFlag = 0;
//				}
//				if(Serial_RxPacket[0] == '3')
//				{
//				OLED_ShowString(3, 1, Serial_ShowRxPacket);	
//				Serial_RxFlag = 0;
//				}
//				if(Serial_RxPacket[0] == '4')
//				{
//				OLED_ShowString(4, 1, Serial_ShowRxPacket);	
//				Serial_RxFlag = 0;
//				}
//		}
//		if (Serial_RxFlag == 1){
//			    if(Serial_RxPacket[0] == '1')
//				{	
//				OLED_ShowString(1, 1, Serial_RxPacket);	
//				Serial_RxFlag = 0;	
//					break;
//				}
//				
//				if(Serial_RxPacket[0] == '2')
//				{	
//				OLED_ShowString(2, 1, Serial_RxPacket);	
//				Serial_RxFlag = 0;
//                break;					
//				}  
//				
//				if(Serial_RxPacket[0] == '3')
//				{	
//				OLED_ShowString(3, 1, Serial_RxPacket);	
//				Serial_RxFlag = 0;
//break;					
//				}  
//				
//				
//				if(Serial_RxPacket[0] == '4')
//				{	
//				OLED_ShowString(4, 1, Serial_RxPacket);	
//				Serial_RxFlag = 0;
//break;					
//				}  	
//								
//		}
		if (Serial_RxFlag == 1){
			char Serial_ShowRxPacket[strlen(Serial_RxPacket)-1];
			for(i=0;i<(strlen(Serial_RxPacket)-1);i++){
			Serial_ShowRxPacket[i]=Serial_RxPacket[i+1];
			}
				switch(Serial_RxPacket[0]){
				case '1':
				OLED_ShowString(1, 1, Serial_ShowRxPacket);	
				Serial_RxFlag = 0;	
				break;	
				case '2':
				OLED_ShowString(2, 1, Serial_ShowRxPacket);	
				Serial_RxFlag = 0;	
				break;
				case '3':
				OLED_ShowString(3, 1, Serial_ShowRxPacket);	
				Serial_RxFlag = 0;	
				break;
				case '4':
				OLED_ShowString(4, 1, Serial_ShowRxPacket);	
				Serial_RxFlag = 0;	
				break;
				default:
				Serial_RxFlag = 0;	
				break;
			}
	}	
 }
}