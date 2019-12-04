/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "stm32f4xx.h"

#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;

//Task function prototypes

void vTask1_handler(void *params);
void vTask2_handler(void *params);

#ifdef USE_SEMIHOSTING
// used for semi hosting
	extern void initialise_monitor_handles();
#endif

static void prvSetupHardware(void);
static void prvSetupUart(void);

void printmsg(char *msg);
//some macros
#define TRUE 1
#define FALSE 0
#define AVAILABLE TRUE
#define NON_AVAILABLE FALSE


//Global variable sections
char usr_msg[250];
uint8_t UART_ACCESS_KEY=AVAILABLE;

int main(void)
{

#ifdef USE_SEMIHOSTING
	initialise_monitor_handles();
	printf(" This is hello world example code \r\n ");
#endif

	//1. reset RCC clock configuration
	RCC_DeInit();

	//2. update the SystemCoreClock variable
	SystemCoreClockUpdate();

	prvSetupHardware();

	sprintf(usr_msg, "This is Hello World application starting \r \n");

	printmsg(usr_msg);

	//3. let us create 2 tasks Task-1 and Task-2

	xTaskCreate(vTask1_handler,"Task-1",configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle1);
	xTaskCreate(vTask2_handler,"Task-2",configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle2);

	//4. Schdule the tasks
	vTaskStartScheduler();
	// program will never this here
	for(;;);
}

void vTask1_handler(void *params)
{
		while(1)
		{
			if(UART_ACCESS_KEY==AVAILABLE)
			{
				UART_ACCESS_KEY=NON_AVAILABLE;
				printmsg("Hello world form task-1\r\n");
				UART_ACCESS_KEY=AVAILABLE;
				taskYIELD();
			}
		}

}

void vTask2_handler(void *params)
{
	while(1)
			{
				if(UART_ACCESS_KEY==AVAILABLE)
					{
						UART_ACCESS_KEY=NON_AVAILABLE;
						printmsg("Hello world form task-2\r\n");
						UART_ACCESS_KEY=AVAILABLE;
						taskYIELD();
					}
			}
}

static void prvSetupUart(void)
{

	GPIO_InitTypeDef gpio_uart_pins;
		USART_InitTypeDef uart2_init;


		//1. Enable UART peripheral clock
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

		//PA2 UART2_TX and PA3is UART2_TX


		//2. Alaternatre fuction configuration of MCU pins to behave as UART2 TX and RS

		//zeroing all the members of the structure  gpio_uart_pins
		memset(&gpio_uart_pins,0,sizeof(gpio_uart_pins));
		gpio_uart_pins.GPIO_Pin=GPIO_Pin_2 | GPIO_Pin_3;
		gpio_uart_pins.GPIO_Mode=GPIO_Mode_AF;
		gpio_uart_pins.GPIO_PuPd=GPIO_PuPd_UP;
		GPIO_Init(GPIOA, &gpio_uart_pins);

		//3.AF mode settings for the pins

		GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2);//PA2
		GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2);//PA3

		//4.UART parameter initialisation

		//zeroing all the members of the structure uart2_init
		memset(&uart2_init,0,sizeof(uart2_init));
		uart2_init.USART_BaudRate=115200;
		uart2_init.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
		uart2_init.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
		uart2_init.USART_Parity=USART_Parity_No;
		uart2_init.USART_StopBits=USART_StopBits_1;
		uart2_init.USART_WordLength=USART_WordLength_8b;
		USART_Init(USART2,&uart2_init);


		//5. Enable the UART peripheral

		USART_Cmd(USART2,ENABLE);



}

static void prvSetupHardware(void)
{

	//set up UART
	prvSetupUart();

}

void printmsg(char *msg)
{
	for(uint32_t i=0; i < strlen(msg);i++)
	{
		while(USART_GetFlagStatus(USART2,USART_FLAG_TXE)!=SET);
		USART_SendData(USART2, msg[i]);
	}
}

