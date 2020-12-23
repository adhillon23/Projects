#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"
#include "inc/hw_gpio.h"
#include "driverlib/rom.h"

#define PWM_FREQUENCY 55
uint32_t one_second;
volatile uint32_t blinky_timer;

//***************************************************************************************************************

//                Highway                   Side Road        Side Road Pedestrian         Highway Pedestrian
//Red             Pin A2                     Pin A5                Pin B0                       Pin B2
//Yellow          Pin A3                     Pin A6
//Green           Pin A4                     Pin A7                Pin B1                       Pin B3
//
void onButton0(void) {
    if (GPIOIntStatus(GPIO_PORTF_BASE, false) & GPIO_PIN_0)
    {

                SysCtlDelay(one_second * 20);
                //Delay for 20 seconds after a button pressed the button

                GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4,GPIO_PIN_0|GPIO_PIN_2);
                //SIDe road pedestrian green and highway pedestrian red light on

                GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_3|GPIO_PIN_5);
                //Highway Yellow and SIDE road Red are on

                SysCtlDelay(one_second * 5);
                //Delay for 5 seconds

                GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_2|GPIO_PIN_7);
                //Highway Red and Side Road Green are on
                GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4,GPIO_PIN_1|GPIO_PIN_2);
                //SIDe road pedestrian green and highway pedestrian red light on

                SysCtlDelay(one_second * 10);
                //Delay for 10 seconds

                blinky_timer = one_second;
                      for(blinky_timer = one_second ; blinky_timer <= (one_second * 5); blinky_timer+= one_second){
                          //Loop SIDe road pedestrian green to blink for 10 seconds
                          GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_2|GPIO_PIN_7);
                                 //Highway Red and Side Road Green are on
                          GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1|GPIO_PIN_2, GPIO_PIN_1|GPIO_PIN_2);
                          //SIDe road pedestrian green and highway pedestrian red light on

                          SysCtlDelay(one_second/2);
                          //Delay for half second

                          GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_2|GPIO_PIN_7);
                                 //Highway Red and Side Road Green are on
                          GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_1|GPIO_PIN_2,GPIO_PIN_2);


                          SysCtlDelay(one_second/2);
                          // Delay for half second
                          }
                GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_2|GPIO_PIN_7);
                         //Highway Red and Side Road Green are on
                GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_2, GPIO_PIN_0|GPIO_PIN_2);
                        //SIDe road pedestrian red and highway pedestrian red light on
                SysCtlDelay(one_second * 10);
                 //Delay for 10 seconds

                GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_2|GPIO_PIN_6);
                 //Highway Red and Side road yellow are on
                GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4,GPIO_PIN_0|GPIO_PIN_2);
                   //SIDe road pedestrian red light on

                SysCtlDelay(one_second * 5);
                //Delay for 5 seconds

                GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_5|GPIO_PIN_2);
                 //Both Highway and Pedestrian's red on
                GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4,GPIO_PIN_0|GPIO_PIN_2);
                   //SIDe road pedestrian red light on

                SysCtlDelay(one_second * 5);
                //Delay for 5 seconds

                GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_5|GPIO_PIN_4);
                //Highway Green and SIDE ROAD RED  are on as the beginning

                GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4,GPIO_PIN_0|GPIO_PIN_2);
                   //SIDe road pedestrian red light on


                GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_0);  // Clear interrupt flag
    }

    if (GPIOIntStatus(GPIO_PORTF_BASE, false) & GPIO_PIN_4) {


            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_5|GPIO_PIN_4);
                      //Highway Green and SIDE road Red lights are on
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4,GPIO_PIN_0|GPIO_PIN_3);
                                               //SIDe road pedestrian red light and highway pedestrian green  on

             SysCtlDelay(one_second * 10);
             //Delay for 10 seconds

                  blinky_timer = one_second;
                        for(blinky_timer = one_second ; blinky_timer <= (one_second * 5); blinky_timer+= one_second){
                         //Loop for yellow light to blink for 10 seconds
                        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_5|GPIO_PIN_4);
                          //Highway green and Side Road red are on
                        GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4,GPIO_PIN_0|GPIO_PIN_3);
                         //SIDe road pedestrian red light and highway pedestrian green on
                         SysCtlDelay(one_second/2);
                           //Delay for half second
                         GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_5, GPIO_PIN_5|GPIO_PIN_4);
                          //Highway Red and Side Road Green are on
                         GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4,GPIO_PIN_0);
                          //SIDe road pedestrian red light on
                        SysCtlDelay(one_second/2);
                        // Delay for half second
                                        }

             GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_5|GPIO_PIN_4);
             //Highway Green and SIDE road Red lights are on

             GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4,GPIO_PIN_0|GPIO_PIN_2);
             //SIDe road pedestrian red light and highway pedestrian on

             GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);  // Clear interrupt flag
        }

}


int main(void)

{

//****************************************************************************************************************
SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4);
GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4);

SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);


HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;

GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_DIR_MODE_IN);
GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

one_second = SysCtlClockGet()/3;



     GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_0,GPIO_FALLING_EDGE);              // Configure PF4 for falling edge trigger
     GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4,GPIO_FALLING_EDGE);             // Configure PF4 for falling edge trigger
     GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_0);                                // Clear pending interrupts for PF0
     GPIOIntRegister(GPIO_PORTF_BASE, onButton0);                             // Register our handler function for port F
     GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4);                  // Enable interrupt for PF4


while(1)
{
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_5|GPIO_PIN_4);
    //Highway Green and SIDE road Red lights are on

    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4,GPIO_PIN_0|GPIO_PIN_2);
    //SIDe road pedestrian green and highway pedestrian red light on
}

}
