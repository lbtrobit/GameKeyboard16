# ifndef __LED_H
# define __LED_H
# include "sys.h"					//LED�˿ڶ���
# define PA8 PAout(8)				//���� �ߵ�ͨ
# define L1 PAout(13)				//L1 �͵�ͨ
# define LA PAout(14)				//LA �͵�ͨ
# define PB0 PBout(0)				//��һ 1 Q A 5 �͵�ͨ
# define PB1 PBout(1)				//�ж� 2 W S Z �͵�ͨ
# define PB2 PBout(2)				//���� 3 E D X �͵�ͨ
# define PB3 PBout(3)				//���� 4 R F SP �͵�ͨ
# define PB4 PBout(4)				//���� 5 Z X SP �ߵ�ͨ
# define PB5 PBout(5)				//���� A S D F �ߵ�ͨ
# define PB6 PBout(6)				//��� Q W E R �ߵ�ͨ
# define PB7 PBout(7)				//��һ 1 2 3 4 �ߵ�ͨ
void LED_Init(void);
void LED_Shine(u8 led);
# endif 
