//       ____
//      /___/\_
//     _\   \/_/\__
//   __\       \/_/\
//   \   __    __ \ \        MIT License. Copyright (c) 2019 SummerFalls.
//  __\  \_\   \_\ \ \   __
// /_/\\   __   __  \ \_/_/\
// \_\/_\__\/\__\/\__\/_\_\/
//    \_\/_/\       /_\_\/
//       \_\/       \_\/
/*
* @ ����: GTek_Delay.c
* @ ����: SummerFalls
* @ ����: 2019-5-22
* @ �汾: V1.0
* @ ����:
*/

#include "GTek_Include.h"

void delay_us(uint32_t us)
{
    uint32_t dwCurCounter = 0;                              // ��ǰʱ�����ֵ
    uint32_t dwPreTickVal = SysTick->VAL;                   // ֮ǰ SYSTICK ����ֵ
    uint32_t dwCurTickVal;                                  // ��ǰ SYSTICK ����ֵ
    us = us * (SystemCoreClock / 1000000);                  // ����ʱʱ�䣬������ʱ�����
//    us = us * (HAL_RCC_GetHCLKFreq() / 1000000);          // ����ʱʱ�䣬������ʱ�����

    while (1) {
        dwCurTickVal = SysTick->VAL;

        if (dwCurTickVal < dwPreTickVal) {
            dwCurCounter = dwCurCounter + dwPreTickVal - dwCurTickVal;
        } else {
            dwCurCounter = dwCurCounter + dwPreTickVal + SysTick->LOAD - dwCurTickVal;
        }

        dwPreTickVal = dwCurTickVal;

        if (dwCurCounter >= us) {
            break;
        }
    }
}

void delay_ms(uint32_t ms)
{
#if 0

    uint32_t i;

    for (i = 0; i < ms; i++) {
        delay_us(1000);
    }

#else

    __IO uint32_t tmp = SysTick->CTRL; /* Clear the COUNTFLAG first */

    /* Add this code to indicate that local variable is not used */
    ((void)tmp);

    /* Add a period to guaranty minimum wait */
    if (ms < 0xFFFFFFFFU) {
        ms++;
    }

    while (ms) {
        if ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0U) {
            ms--;
        }
    }

#endif
}

