# include "sys.h"
# include "usart.h"
# include "delay.h"
# include "led.h"
# include "key.h"
# include "usb_lib.h"
# include "hw_config.h"
# include "usb_pwr.h" 
# include "timer.h"
	   
void usb_port_set(u8 enable)
{
	RCC->APB2ENR|=1<<2;    						//使能PORTA时钟	   	 
	if(enable)_SetCNTR(_GetCNTR()&(~(1<<1)));	//退出断电模式
	else
	{	  
		_SetCNTR(_GetCNTR()|(1<<1)); 			// 断电模式
		GPIOA->CRH&=0XFFF00FFF;
		GPIOA->CRH|=0X00033000;
		PAout(12)=0;	    		  
	}
}

int main(void)
{
	u32 key=0;
	Stm32_Clock_Init(9);			//系统时钟设置
	delay_init(72);					//延时初始化
	LED_Init();						//LED初始化
	Key_Init();						//按键初始化
	TIM3_Int_Init(1000,7199);		//10KHZ的计数频率，计数到1000为100ms
	
	delay_ms(300);
 	usb_port_set(0); 				//USB先断开
	delay_ms(300);
   	usb_port_set(1);				//USB再次连接
									
 	USB_Interrupts_Config();    	//USB配置
 	Set_USBClock();   
 	USB_Init();
	
	while(1)
	{
		u8 Buf[8]={0,0,0,0,0,0,0,0};
		u8 i=2;
		
		key=Key_Scan();				//调用按键扫描程序获得键值
		
		if(key&KX_PRES)
		{	
			L1=0;LA=1;
			LED_Shine(15);
			if(key&KZ_PRES)		//`
			{
				Buf[i]=0X35;
				LED_Shine(14);
				i++;
			}
			if(key&K1_PRES)		//1
			{
				Buf[i]=0X1E;
				LED_Shine(1);
				i++;
			}
			if(key&K2_PRES)		//2
			{
				Buf[i]=0X1F;
				LED_Shine(2);
				i++;
			}
			if(key&K3_PRES)		//3
			{
				Buf[i]=0X20;
				LED_Shine(3);
				i++;
			}
			if(key&K4_PRES)		//4
			{
				Buf[i]=0X21;
				LED_Shine(4);
				i++;
			}
			if(key&K5_PRES)		//5
			{
				Buf[i]=0X22;
				LED_Shine(13);
				i++;
			}
			if(key&KQ_PRES)		//右斜
			{
				Buf[i]=0X31;
				LED_Shine(5);
				i++;
			}
			if(key&KW_PRES)		//左斜
			{
				Buf[i]=0X38;
				LED_Shine(6);
				i++;
			}
			if(key&KE_PRES)		//-
			{
				Buf[i]=0X2D;
				LED_Shine(7);
				i++;
			}
			if(key&KR_PRES)		//=
			{
				Buf[i]=0X2E;
				LED_Shine(8);
				i++;
			}
			if(key&KA_PRES)		//'
			{
				Buf[i]=0X34;
				LED_Shine(9);
				i++;
			}
			if(key&KS_PRES)		//;
			{
				Buf[i]=0X33;
				LED_Shine(10);
				i++;
			}
			if(key&KD_PRES)		//SHIFT
			{
				Buf[0]|=0X02;
				LED_Shine(11);
			}
			if(key&KF_PRES)		//ESC
			{
				Buf[i]=0X29;
				LED_Shine(12);
				i++;
			}
			if(key&KSP_PRES)	//TAB
			{
				Buf[i]=0X2B;
				LED_Shine(16);
				i++;
			}
			if(key&KY_PRES)		//6
			{
				Buf[i]=0X23;
				i++;
			}
			if(key&KU_PRES)		//7
			{
				Buf[i]=0X24;
				i++;
			}
			if(key&KI_PRES)		//8
			{
				Buf[i]=0X25;
				i++;
			}
			if(key&KO_PRES)		//9
			{
				Buf[i]=0X26;
				i++;
			}
			if(key&KP_PRES)		//0
			{
				Buf[i]=0X27;
				i++;
			}
			if(key&KG_PRES)		//,
			{
				Buf[i]=0X36;
				i++;
			}
			if(key&KH_PRES)		//.
			{
				Buf[i]=0X37;
				i++;
			}
			if(key&KJ_PRES)		//UP
			{
				Buf[i]=0X52;
				i++;
			}
			if(key&KK_PRES)		//[
			{
				Buf[i]=0X2F;
				i++;
			}
			if(key&KL_PRES)		//]
			{
				Buf[i]=0X30;
				i++;
			}
			if(key&KB_PRES)		//LEFT
			{
				Buf[i]=0X50;
				i++;
			}
			if(key&KN_PRES)		//DOWN
			{
				Buf[i]=0X51;
				i++;
			}
			if(key&KM_PRES)		//RIGHT
			{
				Buf[i]=0X4F;
				i++;
			}
			if(key&KDO_PRES)		//CTRL
			{
				Buf[0]|=0X01;
			}
			if(key&KEN_PRES)		//ALT
			{
				Buf[0]|=0X04;
			}
			if(key&KBS_PRES)		//DEL
			{
				Buf[i]=0X4C;
				i++;
			}
		}
		else if((key&KX_PRES)==0)
		{	
			L1=1;LA=0;
			if(key&KZ_PRES)		//Z
			{
				Buf[i]=0X1D;
				LED_Shine(14);
				i++;
			}
			if(key&K1_PRES)		//Q
			{
				Buf[i]=0X14;
				LED_Shine(1);
				i++;
			}
			if(key&K2_PRES)		//W
			{
				Buf[i]=0X1A;
				LED_Shine(2);
				i++;
			}
			if(key&K3_PRES)		//E
			{
				Buf[i]=0X08;
				LED_Shine(3);
				i++;
			}
			if(key&K4_PRES)		//R
			{
				Buf[i]=0X15;
				LED_Shine(4);
				TIM3->CR1|=0x01;
				PA8=1;
				i++;
			}
			if(key&K5_PRES)		//T
			{
				Buf[i]=0X17;
				LED_Shine(13);
				i++;
			}
			if(key&KQ_PRES)		//A
			{
				Buf[i]=0X04;
				LED_Shine(5);
				i++;
			}
			if(key&KW_PRES)		//S
			{
				Buf[i]=0X16;
				LED_Shine(6);
				i++;
			}
			if(key&KE_PRES)		//D
			{
				Buf[i]=0X07;
				LED_Shine(7);
				i++;
			}
			if(key&KR_PRES)		//F
			{
				Buf[i]=0X09;
				LED_Shine(8);
				i++;
			}
			if(key&KA_PRES)		//X
			{
				Buf[i]=0X1B;
				LED_Shine(9);
				i++;
			}
			if(key&KS_PRES)		//C
			{
				Buf[i]=0X06;
				LED_Shine(10);
				i++;
			}
			if(key&KD_PRES)		//V
			{
				Buf[i]=0X19;
				LED_Shine(11);
				i++;
			}
			if(key&KF_PRES)		//CTRL
			{
				Buf[0]|=0X01;
				LED_Shine(12);
			}
			if(key&KSP_PRES)	//Spacebar
			{
				Buf[i]=0X2C;
				LED_Shine(16);
				i++;
			}
			if(key&KY_PRES)		//Y
			{
				Buf[i]=0X1C;
				i++;
			}
			if(key&KU_PRES)		//U
			{
				Buf[i]=0X18;
				i++;
			}
			if(key&KI_PRES)		//I
			{
				Buf[i]=0X0C;
				i++;
			}
			if(key&KO_PRES)		//O
			{
				Buf[i]=0X12;
				i++;
			}
			if(key&KP_PRES)		//P
			{
				Buf[i]=0X13;
				i++;
			}
			if(key&KG_PRES)		//G
			{
				Buf[i]=0X0A;
				i++;
			}
			if(key&KH_PRES)		//H
			{
				Buf[i]=0X0B;
				i++;
			}
			if(key&KJ_PRES)		//J
			{
				Buf[i]=0X0D;
				i++;
			}
			if(key&KK_PRES)		//K
			{
				Buf[i]=0X0E;
				i++;
			}
			if(key&KL_PRES)		//L
			{
				Buf[i]=0X0F;
				i++;
			}
			if(key&KB_PRES)		//B
			{
				Buf[i]=0X05;
				i++;
			}
			if(key&KN_PRES)		//N
			{
				Buf[i]=0X11;
				i++;
			}
			if(key&KM_PRES)		//M
			{
				Buf[i]=0X10;
				i++;
			}
			if(key&KDO_PRES)		//CAPSLOCK
			{
				Buf[i]=0X39;
				i++;
			}
			if(key&KEN_PRES)		//ENTER
			{
				Buf[i]=0X28;
				i++;
			}
			if(key&KBS_PRES)		//BACKSPACE
			{
				Buf[i]=0X2A;
				i++;
			}
		}
			
		Joystick_Send(Buf[0],Buf[1],Buf[2],Buf[3],Buf[4],Buf[5],Buf[6],Buf[7]);
	}
}

