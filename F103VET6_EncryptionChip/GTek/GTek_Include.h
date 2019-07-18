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
* @ ����: GTek_Include.h
* @ ����: SummerFalls
* @ ����: 2019-5-21
* @ �汾: V1.0
* @ ����: ȫ��ͨ��ͷ�ļ����ã���Բ�ͬ .c Դ�ļ�������Ҫ
*         ���ù�ͬ��ͷ�ļ����������ֱ�����ñ�ͷ�ļ����ɡ�
*/

#ifndef __GTEK_INCLUDE_H
#define __GTEK_INCLUDE_H

/* ------- ��׼��ͷ�ļ����� ------- */
#include <stdint.h> /* �������� */

#include <stdio.h>  /* ������� */
#include <stdlib.h> /* ����ʵ�ú��� */
#include <stddef.h> /* ���ö��� */
#include <stdbool.h>/* �������Ͷ��� */
#include <string.h> /* �ַ������� */
#include <stdarg.h> /* �������� */
#include <ctype.h>  /* �ַ����� */

#include <locale.h> /* ���ػ� */
#include <time.h>   /* ���ں�ʱ�� */

#include <limits.h> /* �������� */
#include <float.h>  /* ���������� */
#include <math.h>   /* ��ѧ���� */

#include <assert.h> /* ��� */
#include <errno.h>  /* ������ */

#include <setjmp.h> /* �Ǳ�����ת */
#include <signal.h> /* �źŴ��� */


//#include "GTek_LED.h"
//#include "GTek_UART.h"
#include "GTek_Delay.h"

#include "i2c_bitbang_stm32.h"
#include "cryptoauthlib.h"
#include "symmetric_authentication.h"
#include "configuration.h"
#include "provision_device.h"
#include "host_random.h"
#include "led_patterns.h"
#include "atca_host.h"

#include "stm32f1xx.h"

#endif /* __GTEK_INCLUDE_H */
/* -------------------------------------------- END OF FILE -------------------------------------------- */
