.syntax unified 
.cpu cortex-m4
.fpu softvfp 
.thumb 

// Global variables
.global vtable 
.global default_interrupt_handler 

// The vector table.
.type vtable, %object 
.section .vector_table,"a",%progbits 
vtable: 
.word _estack                 
.word reset_handler
.word NMI_handler
.word hard_fault_handler
.word 0 //MemManage
.word 0 //BusFault
.word 0 //Reserved
.word 0 
.word 0
.word 0
.word 0
.word 0 //SVCall
.word 0 //Debut Monitor
.word 0 //Reserved
.word 0 //PendSV
.word SysTick_handler
.word 0 //WWDG
.word 0 //PVD
.word 0 //TAMP_STAMP
.word 0 //RTC_WKUP
.word 0 //FLASH
.word 0 //RCC
.word 0 //EXTI0
.word 0 //EXTI1
.word 0 //EXTI2
.word button2_handler //EXTI3
.word 0 //EXTI4
.word 0 //DMA1_Stream0
.word 0 //DMA1_Stream1
.word 0 //DMA1_Stream2
.word 0 //DMA1_Stream3
.word 0 //DMA1_Stream4
.word 0 //DMA1_Stream5
.word 0 //DMA1_Stream6
.word 0 //ADC
.word 0 //CAN1_TX
.word 0 //CAN1_RX0
.word 0 //CAN1_Rx1
.word 0 //CAN1_SCE
.word button1_handler //EXTI9_5
.word 0 //TIM1_BRK_TIM9
.word 0 //TIM1_UP_TIM10
.word 0 //TIM1_TG_COM_TIM11
.word 0 //TIM1_CC
.word 0 //TIM2
.word 0 //TIM3
.word 0 //TIM4
.word 0 //I2C1_EV
.word 0 //I2C1_ER
.word 0 //I2C2_EV
.word 0 //I2C2_ER
.word 0 //SPI1
.word 0 //SPI2
.word 0 //USART1
.word 0 //USART2
.word 0 //USART3
.word button0_handler //EXTI15_10


// Location to Boot from RAM startup
#define boot_ram_base 0xF108F85F //does this need to change
.word boot_ram_base

// Set up weak aliases for each exception handler
.weak NMI_handler
.thumb_set NMI_handler,default_interrupt_handler

.weak hard_fault_handler
.thumb_set hard_fault_handler,default_interrupt_handler

.weak SysTick_handler
.thumb_set SysTick_handler,default_interrupt_handler

.size vtable, .-vtable

// Default interrupt handler, for interrupts not defined
.section .text.default_interrupt_handler,"ax",%progbits

default_interrupt_handler:
   default_interrupt_loop:
      B default_interrupt_loop

.size default_interrupt_handler, .-default_interrupt_handler
