
#include "msp.h"
#include <student/memory.h>

/**************************************************
 * Make sure that the MCU is running at 24MHz by
 * changing __SYSTEM_CLOCK in system_msp432p401r.c
 * to be 24000000
 *************************************************/

/**
 * main.c
 */
void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer


    memory_init();
    memory_game();

    while(1){};
}
