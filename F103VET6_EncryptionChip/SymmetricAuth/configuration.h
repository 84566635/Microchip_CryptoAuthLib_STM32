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
* @ ����: configuration.h
* @ ����: SummerFalls
* @ ����: 2019-5-24
* @ �汾: V1.0
* @ ����:
*/

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

// ������
// �ͺ�: ATSHA204A �� SN[0:8] 0x01 0x23 0x77 0xEE 0x79 0x3F 0xA1 0xE0 0xEE
// �ͺ�: ATSHA204A �� SN[0:8] 0x01 0x23 0x48 0xD2 0x64 0x40 0xC1 0x04 0xEE
// �ͺ�: ATECC508A �� SN[0:8] 0x01 0x23 0x0C 0x97 0x4A 0x3E 0x60 0xF8 0xEE

/*
NOTE 1: ������֤ʱ�Ƿ�ʹ�� DERIVE_KEY�����ʹ�ã�
        ����� atcah_derive_key() ����ͨ�� master_key ���������������SHA-256�������һ���Գ���Կ��

NOTE 2: �����֤ʱҪʹ�� DERIVE_KEY����Ҫ���ڼ���оƬ��һ������ʱҲ���� DERIVE_KEY ��ʹ�ã�
        ������ atcah_derive_key() ����ͨ�� master_key �����Գ���Կ�������Գ���Կд�����оƬ��Data Slot�С�
        
NOTE 3: �ܸú�Ӱ����ļ�: provision_device.c    symmetric_authentication.c
*/
#define USE_ATCAH_DERIVE_KEY

#define DEVICE_ATSHA204A 0
#define DEVICE_ATECC508A 1
#define DEVICE_ATECC608A 2 // ATECC608A ��������Ϣ��ʱΪĬ�ϣ�������ʱ���øú�

// �����Ƿ���м���оƬ������д����Կ����Ϣ
#define IP_PROTECTION_LOAD_CONFIG       1

// ѡ����Ҫ��֤�ļ���оƬ
#define CRYPTOAUTH_DEVICE               DEVICE_ATSHA204A

// ����������֤�� symmetric key(�Գ���Կ) ���洢�� Data Slot����Χ: 0 ~ 15
#define CRYPTOAUTH_DEVICE_AUTH_KEY_SLOT 4

// ������֤��������С�ȴ����� (��λ: ms)
#define AUTHENTICATION_MIN_MSEC         1500

// ������֤���������ȴ����� (��λ: ms) ���� AUTHENTICATION_MIN_MSEC �� AUTHENTICATION_MIN_MSEC + AUTHENTICATION_RANGE_MSEC ֮��
#define AUTHENTICATION_RANGE_MSEC       3000

#endif /* CONFIGURATION_H_ */
