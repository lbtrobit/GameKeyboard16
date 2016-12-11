# include "key.h"
# include "delay.h"

void Key_Init(void)						//������ʼ��
{
	RCC->APB2ENR|=1<<2;       	        //ʹ��PORTAʱ��
	RCC->APB2ENR|=1<<3;				    //ʹ��PORTBʱ��
	GPIOA->CRL&=0X00000000;  
	GPIOA->CRL|=0X88883333;     	    //PA3~PA0�������1��PA7~4��������
	GPIOA->ODR&=0XFF00;
	GPIOA->ODR|=0X00FF;
	GPIOB->CRH&=0X00000000;
	GPIOB->CRH|=0X88883333;			   //PB8~PB11�������1��PB12~15��������
	GPIOB->ODR&=0X00FF;				
	GPIOB->ODR|=0XFF00;
}

u32 Key_Scan(void)						//����ɨ�跨
{	
	u32 key=0;							//���巵�ر���
	
	GPIOA->ODR&=0XFFF0;					//PA3~PA0���0000
	GPIOA->ODR|=0X0000;
	GPIOB->ODR&=0XF0FF;					//PB8~PB11���0000
	GPIOB->ODR|=0X0000;
	delay_us(1);						//����Ӧʱ��
	if(((GPIOA->IDR & 0X00F0)!=0X00F0)||((GPIOB->IDR & 0XF000)!=0XF000))
	{
		delay_ms(5);					//ȥ���� 
		
		GPIOA->ODR&=0XFFF0;				//PA3~PA0���1110
		GPIOA->ODR|=0X000E;
		GPIOB->ODR&=0XF0FF;				//PB11~PB8���1110
		GPIOB->ODR|=0X0E00;
		delay_us(1);					//����Ӧʱ��	
		if(h1==0)
		{	key|=0X00000001;	}	//1	
		if(h2==0)
		{	key|=0X00000010;	}	//Q
		if(h3==0)
		{	key|=0X00000100;	}	//A
		if(h4==0)
		{	key|=0X00001000;	}	//5
		if(h5==0)
		{	key|=0X00010000;	}	//P	
		if(h6==0)
		{	key|=0X00100000;	}	//L
		if(h7==0)
		{	key|=0X01000000;	}	//M
		if(h8==0)
		{	key|=0X10000000;	}	//Y
			
		GPIOA->ODR&=0XFFF0;				//PA3~PA0���1101
		GPIOA->ODR|=0X000D;
		GPIOB->ODR&=0XF0FF;				//PB11~PB8���1101
		GPIOB->ODR|=0X0D00;
		delay_us(1);					//����Ӧʱ��
		if(h1==0)
		{	key|=0X00000002;	}	//2	
		if(h2==0)
		{	key|=0X00000020;	}	//W
		if(h3==0)
		{	key|=0X00000200;	}	//S
		if(h4==0)
		{	key|=0X00002000;	}	//Z
		if(h5==0)
		{	key|=0X00020000;	}	//O	
		if(h6==0)
		{	key|=0X00200000;	}	//K
		if(h7==0)
		{	key|=0X02000000;	}	//N
		if(h8==0)
		{	key|=0X20000000;	}	//,
		
		GPIOA->ODR&=0XFFF0;				//PA3~PA0���1011
		GPIOA->ODR|=0X000B;
		GPIOB->ODR&=0XF0FF;				//PB11~PB8���1011
		GPIOB->ODR|=0X0B00;
		delay_us(1);					//����Ӧʱ��
		if(h1==0)
		{	key|=0X00000004;	}	//3	
		if(h2==0)
		{	key|=0X00000040;	}	//E
		if(h3==0)
		{	key|=0X00000400;	}	//D
		if(h4==0)
		{	key|=0X00004000;	}	//X
		if(h5==0)
		{	key|=0X00040000;	}	//I	
		if(h6==0)
		{	key|=0X00400000;	}	//J
		if(h7==0)
		{	key|=0X04000000;	}	//B
		if(h8==0)
		{	key|=0X40000000;	}	//BS
		
		GPIOA->ODR&=0XFFF0;				//PA3~PA0���0111
		GPIOA->ODR|=0X0007;
		GPIOB->ODR&=0XF0FF;				//PB11~PB8���0111
		GPIOB->ODR|=0X0700;
		delay_us(1);					//����Ӧʱ��
		if(h1==0)
		{	key|=0X00000008;	}	//4	
		if(h2==0)
		{	key|=0X00000080;	}	//R
		if(h3==0)
		{	key|=0X00000800;	}	//F
		if(h4==0)
		{	key|=0X00008000;	}	//SP
		if(h5==0)
		{	key|=0X00080000;	}	//U
		if(h6==0)
		{	key|=0X00800000;	}	//H
		if(h7==0)
		{	key|=0X08000000;	}	//G
		if(h8==0)
		{	key|=0X80000000;	}	//EN
	}	
	return key;							//���ؼ�ֵ
}


