# include "timer.h"
# include "led.h"
//��ʱ��3�жϷ������
void TIM3_IRQHandler(void)
{
	if(TIM3->SR&0X0001) PA8=!PA8;	//����ж�
	TIM3->SR&=~(1<<0);				//����жϱ�־λ
	TIM3->CR1&= ~(0x01);			//��ֹ��ʱ��3
}
//ͨ�ö�ʱ��3�жϳ�ʼ��
//ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr:�Զ���װֵ
//psc:ʱ��Ԥ��Ƶ��
void TIM3_Int_Init (u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<1;				//TIM3ʱ��ʹ��
	TIM3->ARR=arr;					//�趨�������Զ���װֵ
	TIM3->PSC=psc;					//Ԥ��Ƶ��7200���õ�10KHZ�ļ���ʱ��
	TIM3->DIER|=1<<0;				//��������ж�
	MY_NVIC_Init(1,3,TIM3_IRQn,2);	//��ռ1�������ȼ�3����2
}
