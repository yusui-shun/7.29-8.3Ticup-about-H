#include "ti_msp_dl_config.h"
#include "stdio.h"
#include "drv_oled.h"


#define DELAY (3200000)
uint32_t straight_distance=30303;

uint32_t straight_turn=2665;
uint32_t turn_distance=38788;

uint32_t circle_turn=2482;
uint32_t circle_distance=7879;


uint8_t finish_flag=0;

uint32_t left_num=0;
uint32_t right_num=0;

uint32_t buzzer_time=5000;

uint16_t i=1;
uint8_t j=0;
uint8_t buzz=0;
uint8_t task_flag=0;
uint8_t corr_flag=0;
void my_delay_ms(uint32_t ms)
{
	while(ms--)
	{
		delay_cycles(32000);
	}
}	
void key_scan(void)
{
		if(!DL_GPIO_readPins(KEY_KEY1_PORT,KEY_KEY1_PIN))//按下为低电平
		{
			my_delay_ms(10);
			if(!DL_GPIO_readPins(KEY_KEY1_PORT,KEY_KEY1_PIN))//延时之后再次检测
			{
				while(!DL_GPIO_readPins(KEY_KEY1_PORT,KEY_KEY1_PIN));//等待按键释放
				DL_GPIO_togglePins(LED_PORT,LED_LED_1_PIN);//电平翻转驱动LED
				task_flag=1;
			}
		}		
		if(!DL_GPIO_readPins(KEY_KEY2_PORT,KEY_KEY2_PIN))//按下
		{
			my_delay_ms(10);
			if(!DL_GPIO_readPins(KEY_KEY2_PORT,KEY_KEY2_PIN))//延时之后再次检测
			{
				while(!DL_GPIO_readPins(KEY_KEY2_PORT,KEY_KEY2_PIN));//等待按键释放
				DL_GPIO_togglePins(LED_PORT,LED_LED_1_PIN);//电平翻转驱动LED
				task_flag=2;
			}
		}
		if(!DL_GPIO_readPins(KEY_KEY3_PORT,KEY_KEY3_PIN))//按下
		{
			my_delay_ms(10);
			if(!DL_GPIO_readPins(KEY_KEY3_PORT,KEY_KEY3_PIN))//延时之后再次检测
			{
				while(!DL_GPIO_readPins(KEY_KEY3_PORT,KEY_KEY3_PIN));//等待按键释放
				DL_GPIO_togglePins(LED_PORT,LED_LED_1_PIN);//电平翻转驱动LED
				task_flag=3;
			}
		}
		if(!DL_GPIO_readPins(KEY_KEY4_PORT,KEY_KEY4_PIN))//按下
		{
			my_delay_ms(10);
			if(!DL_GPIO_readPins(KEY_KEY4_PORT,KEY_KEY4_PIN))//延时之后再次检测
			{
				while(!DL_GPIO_readPins(KEY_KEY4_PORT,KEY_KEY4_PIN));//等待按键释放
				DL_GPIO_togglePins(LED_PORT,LED_LED_1_PIN);//电平翻转驱动LED
				task_flag=4;
			}
		}
}
uint8_t Straight(void)
{
	if(i==1 && finish_flag==1)
	{
		left_num=straight_distance;
		right_num=straight_distance;
		finish_flag=0;
		i++;
	}
	if(i==2 && finish_flag==1)
	{
		i=1;
//		DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
//		my_delay_ms(buzzer_time);
//		DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
		buzzer_time=0;
		return 0;
	}
	display_6_8_number_f1(0,0,left_num);//显示计数器值
	display_6_8_number_f1(0,1,right_num);//显示计数器值
	return 1;
}

uint8_t Straight_right(void)
{
	if (i==1 && finish_flag==1)
	{
		if(j==1)
		{
			right_num=2665;
		}
		if(j==2)
		{
			right_num=2865;
		}
		if(j==3)
		{
			right_num=2865;
		}
		if(j==0)
		{
			right_num=2565;
		}
		finish_flag=0;
		i++;
	}
	
	if (i==2 && finish_flag==1)
	{
		if(j==1)
		{
			left_num=turn_distance;
			right_num=turn_distance;
		}
		if(j==2)
		{
			left_num=turn_distance;
			right_num=turn_distance;
		}
		if(j==0)
		{
			left_num=turn_distance+800;
			right_num=turn_distance+800;
		}
		if(j==3)
		{
			left_num=turn_distance+1200;
			right_num=turn_distance+1200;
		}
		finish_flag=0;
		i++;
	}
	
		if (i==3 && finish_flag==1)
	{
		if(j==1)
		{
			left_num=2665;
		}
		if(j==2)
		{
			left_num=2865;
		}
		if(j==3)
		{
			left_num=2865;
		}
		if(j==0)
		{
			left_num=2565;
		}
		finish_flag=0;
		i++;
	}
	
	if(i==4 && finish_flag==1) 
	{
		i=1;
//		DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
//		my_delay_ms(buzzer_time);
//		DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
		buzzer_time=0;
		return 0;
	}
	display_6_8_number_f1(0,0,left_num);//显示计数器值
	display_6_8_number_f1(0,1,right_num);//显示计数器值
	return 1;
}

uint8_t Straight_left(void)
{
	if (i==1 && finish_flag==1)
	{
		if(j==0)
		{
			left_num=straight_turn-800;
		}
		if(j==1)
		{
			left_num=straight_turn-800;
		}
		if(j==2)
		{
			left_num=straight_turn-900;
		}
		if(j==3)
		{
			left_num=straight_turn-900;
		}
		
		finish_flag=0;
		i++;
	}
	
	if (i==2 && finish_flag==1)
	{
		if(j==1)
		{
		left_num=turn_distance-2800;
		right_num=turn_distance-2800;
		}
		if(j==2)
		{
		left_num=turn_distance-3000;
		right_num=turn_distance-3000;
		}
		if(j==3)
		{
		left_num=turn_distance-2400;
		right_num=turn_distance-2400;
		}
		if(j==0)
		{
		left_num=turn_distance-2400;
		right_num=turn_distance-2400;
		}

		finish_flag=0;
		i++;
	}
	
		if (i==3 && finish_flag==1)
	{
		if(j==0)
		{
			right_num=straight_turn-800;
		}
		if(j==1)
		{
			right_num=straight_turn-800;
		}
		if(j==2)
		{
			right_num=straight_turn-900;
		}
		if(j==3)
		{
			right_num=straight_turn-900;
		}
		finish_flag=0;
		i++;
	}
	
	if(i==4 && finish_flag==1) 
	{
		i=1;
//		DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
//		my_delay_ms(buzzer_time);
//		DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
		buzzer_time=0;
		return 0;
	}
	display_6_8_number_f1(0,0,left_num);//显示计数器值
	display_6_8_number_f1(0,1,right_num);//显示计数器值
	return 1;
}

uint8_t circle_right(void)
{
	if(corr_flag==1)
	{
				if (i==1 && finish_flag==1)
		{
			right_num=2382;
			finish_flag=0;
			i++;
		}
		
		if (i==2 && finish_flag==1)
		{
			left_num=8079;
			right_num=8079;
			finish_flag=0;
			i++;
		}
			if (i==3 && finish_flag==1)
		{
			right_num=2882;
			finish_flag=0;
			i++;
		}
		
		if (i==4 && finish_flag==1)
		{
			left_num=circle_distance;
			right_num=circle_distance;
			finish_flag=0;
			i++;
		}
			if (i==5 && finish_flag==1)
		{
			right_num=2782;
			finish_flag=0;
			i++;
		}
		
		if (i==6 && finish_flag==1)
		{
			left_num=circle_distance;
			right_num=circle_distance;
			finish_flag=0;
			i++;
		}
			if (i==7 && finish_flag==1)//
		{
			right_num=3082;
			finish_flag=0;
			i++;
		}
		
			
		if (i==8 && finish_flag==1)//
		{
			left_num=8629;
			right_num=8629;
			finish_flag=0;
			i++;
		}
			if (i==9 && finish_flag==1)
		{
			right_num=1082;
			finish_flag=0;
			i++;
		}
		if(j==3)
		{
			if (i==10 && finish_flag==1)//
			{
			left_num=3000;
			right_num=3000;
			finish_flag=0;
			i++;
			}
			if(i==11 && finish_flag==1) 
			{
				i=1;
//				DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
//				my_delay_ms(buzzer_time);
//				DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
				buzzer_time=0;
				return 0;
			}
		}
		else
		{
			if(i==10 && finish_flag==1) 
			{
				i=1;
//				DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
//				my_delay_ms(buzzer_time);
//				DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
				buzzer_time=0;
				return 0;
			}
		}

	}
	
	if(corr_flag==0)
	{
		if (i==1 && finish_flag==1)
		{
			right_num=1882;
			finish_flag=0;
			i++;
		}
		
		if (i==2 && finish_flag==1)
		{
			left_num=8079;
			right_num=8079;
			finish_flag=0;
			i++;
		}
		if (i==3 && finish_flag==1)
		{
			right_num=2682;
			finish_flag=0;
			i++;
		}
		
		if (i==4 && finish_flag==1)
		{
			left_num=circle_distance;
			right_num=circle_distance;
			finish_flag=0;
			i++;
		}
		if (i==5 && finish_flag==1)
		{
			right_num=2482;
			finish_flag=0;
			i++;
		}
		
		if (i==6 && finish_flag==1)
		{
			left_num=circle_distance;
			right_num=circle_distance;
			finish_flag=0;
			i++;
		}
		if (i==7 && finish_flag==1)//
		{
			right_num=3382;
			finish_flag=0;
			i++;
		}
		
			
		if (i==8 && finish_flag==1)//
		{
			left_num=circle_distance;
			right_num=circle_distance;
			finish_flag=0;
			i++;
		}
			if (i==9 && finish_flag==1)
		{
			right_num=1532;
			finish_flag=0;
			i++;
		}
		
			if(i==10 && finish_flag==1) 
		{
			i=1;
//			DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
//			my_delay_ms(buzzer_time);
//			DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
			buzzer_time=0;
			return 0;
		}
	}

	
	display_6_8_number_f1(0,0,left_num);//显示计数器值
	display_6_8_number_f1(0,1,right_num);//显示计数器值
	return 1;
}


uint8_t circle_left(void)
{
			if (i==1 && finish_flag==1)
	{
		left_num=2382;
		finish_flag=0;
		i++;
	}
	
	if (i==2 && finish_flag==1)
	{
		left_num=8079;
		right_num=8079;
		finish_flag=0;
		i++;
	}
		if (i==3 && finish_flag==1)
	{
		left_num=2882;
		finish_flag=0;
		i++;
	}
	
	if (i==4 && finish_flag==1)
	{
		left_num=circle_distance;
		right_num=circle_distance;
		finish_flag=0;
		i++;
	}
		if (i==5 && finish_flag==1)
	{
		left_num=2782;
		finish_flag=0;
		i++;
	}
	
	if (i==6 && finish_flag==1)
	{
		left_num=circle_distance;
		right_num=circle_distance;
		finish_flag=0;
		i++;
	}
		if (i==7 && finish_flag==1)//
	{
		left_num=3082;
		finish_flag=0;
		i++;
	}
	
		
	if (i==8 && finish_flag==1)//
	{
		left_num=circle_distance-2400;
		right_num=circle_distance-2400;
		finish_flag=0;
		i++;
	}
		if (i==9 && finish_flag==1)
	{
		left_num=1082;
		finish_flag=0;
		i++;
	}
		if(i==10 && finish_flag==1) 
	{
		i=1;
//		DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
//		my_delay_ms(buzzer_time);
//		DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
		buzzer_time=0;
		return 0;
	}
	display_6_8_number_f1(0,0,left_num);//显示计数器值
	display_6_8_number_f1(0,1,right_num);//显示计数器值
	return 1;
}


int main(void)
{
	SYSCFG_DL_init();//芯片资源初始化,由SysConfig配置软件自动生成
	DL_GPIO_togglePins(GPIOA,BUZZER_buzzer_PIN);
	oled_init();
	NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);//中断使能
	DL_TimerG_startCounter(TIMER_0_INST);//开始计数
	LCD_clear_L(0,0);//清以第一行数据 
	display_6_8_number_f1(0,0,left_num);//显示计数器值
	display_6_8_number_f1(0,1,right_num);//显示计数器值
	while(1)
	{
		key_scan();
		if(task_flag==1)
		{
			while(Straight());
			task_flag=0;
		}
		if(task_flag==2)
		{
			corr_flag=0;
			while(Straight());
			while(circle_right());
			while(Straight());
			while(circle_right());
			task_flag=0;
		}
		if(task_flag==3)
		{
			corr_flag=1;
			while(Straight_right());
			while(circle_left());
			while(Straight_left());
			while(circle_right());
			corr_flag=0;
			task_flag=0;
		}
		if(task_flag==4)
		{
			corr_flag=1;
			for(j=0;j<=3;j++)
			{
				while(Straight_right());
				while(circle_left());
				while(Straight_left());
				while(circle_right());
			}
			corr_flag=0;
			task_flag=0;
		}
	}
}


void TIMER_0_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_0_INST)) {
        case DL_TIMERG_IIDX_ZERO:
				{
					if(left_num)
					{						
						DL_GPIO_togglePins(Right_Motor_PORT,Right_Motor_Driver_R_PIN);
						left_num--;
					}
					if(right_num)
					{
						DL_GPIO_togglePins(Left_Motor_PORT,Left_Motor_Dirver_L_PIN);//IO电平翻转
						right_num--;
					}
					if(!right_num && !left_num)
					{
						finish_flag=1;
					}
					if(buzzer_time==0)
					{
						DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
					}
					if(buzzer_time==4000)
					{
						DL_GPIO_togglePins(GPIOB,BUZZER_buzzer_PIN);
					}
					if(buzzer_time<5000)
					{
						buzzer_time++;
					}
				}
				break;
        default:
            break;
    }
}

