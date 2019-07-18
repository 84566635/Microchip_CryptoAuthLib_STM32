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
* @ ����: provision_device.c
* @ ����: SummerFalls
* @ ����: 2019-5-23
* @ �汾: V1.0
* @ ����:
*/

#include "configuration.h"

#ifdef IP_PROTECTION_LOAD_CONFIG
#include "main.h"
#include "GTek_Include.h"
#ifndef CRYPTOAUTH_DEVICE
#error "δѡ�����оƬ�ͺ�, ���� configuration.h ��ѡ��"
#endif

uint32_t ATCA_ProvisionCnt = 0;

#if (CRYPTOAUTH_DEVICE == DEVICE_ATSHA204A)

// ATSHA204A Configuration to store the symmetric diversified key
const uint8_t sha204_configdata[ATCA_SHA_CONFIG_SIZE] = {
    // block 0
    // Not Written: First 16 bytes are not written
    0x01, 0x23, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0xEE, 0x55, 0x00, 0x00,
    // I2C_Address, CheckMacConfig, OtpMode, SelectorMode
    0xC8, 0x00, 0xAA, 0x00,
    // SlotConfig
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x84, 0x80, 0x00, 0x00,
    // block 1
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    // Use Flags
    0xFF, 0x00, 0xFF, 0x00,
    0xFF, 0x00, 0xFF, 0x00,
    0xFF, 0x00, 0xFF, 0x00,
    // block 2
    0xFF, 0x00, 0xFF, 0x00,
    // Last Key Use
    0x7F, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    // Not Written: UserExtra, Selector, LockData, LockConfig (word offset = 5)
    0x00, 0x00, 0x55, 0x55,
};

#elif (CRYPTOAUTH_DEVICE == DEVICE_ATECC508A)
// ATECC508A Configuration to store the symmetric diversified key
const uint8_t ecc508_configdata[ATCA_ECC_CONFIG_SIZE] = {
    // block 0
    // Not Written: First 16 bytes are not written
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    // I2C_Address, Reserved17, OtpMode, ChipMode
    0xC0, 0x00, 0xAA, 0x00,
    // SlotConfig
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x84, 0x80, 0x00, 0x00,
    // block 1
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    // Counter0
    0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00,
    // Counter1
    0xFF, 0xFF, 0xFF, 0xFF,
    // block 2
    0x00, 0x00, 0x00, 0x00,
    // LastKeyUse
    0x03, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    // Not Written: UserExtra, Selector, LockData, LockConfig (word offset = 5)
    0x00, 0x00, 0x00, 0x00,
    // SlotLocked[2], Rfu90[2]
    0xFF, 0xFF, 0x00, 0x00,
    // X509Format
    0x00, 0x00, 0x00, 0x00,
    // block 3
    // KeyConfig
    0x1C, 0x00, 0x1C, 0x00,
    0x1C, 0x00, 0x1C, 0x00,
    0x1C, 0x00, 0x1C, 0x00,
    0x1C, 0x00, 0x1C, 0x00,
    0x3C, 0x00, 0x3C, 0x00,
    0x3C, 0x00, 0x3C, 0x00,
    0x3C, 0x00, 0x3C, 0x00,
    0x3C, 0x00, 0x1C, 0x00
};
#elif (CRYPTOAUTH_DEVICE == DEVICE_ATECC608A)
// ATECC608A Configuration to store the symmetric diversified key
const uint8_t ecc608_configdata[ATCA_ECC_CONFIG_SIZE] = {
    0x01,            0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,
    ECC608A_ADDRESS, 0x00, 0x00, 0x01, 0x85, 0x00, 0x82, 0x00, 0x85, 0x20, 0x85, 0x20, 0x85, 0x20, 0x8F, 0x46,
    0x8F,            0x0F, 0x9F, 0x8F, 0x0F, 0x0F, 0x8F, 0x0F, 0x0F, 0x8F, 0x0F, 0x8F, 0x0F, 0x8F, 0x0F, 0x0F,
    0x0D,            0x1F, 0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00,            0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xF7, 0x00, 0x69, 0x76, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00,            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x0E, 0x60, 0x00, 0x00, 0x00, 0x00,
    0x53,            0x00, 0x53, 0x00, 0x73, 0x00, 0x73, 0x00, 0x73, 0x00, 0x38, 0x00, 0x7C, 0x00, 0x1C, 0x00,
    0x3C,            0x00, 0x1A, 0x00, 0x1C, 0x00, 0x10, 0x00, 0x1C, 0x00, 0x30, 0x00, 0x12, 0x00, 0x30, 0x00
};
#endif

// Function to configure the device configuration zone and the symmetric diversified key in the slot
ATCA_STATUS device_provision(uint8_t slot)
{
    ATCA_STATUS status;
    uint8_t sn[ATCA_SERIAL_NUM_SIZE];    
    bool is_locked;
    uint8_t master_key[ATCA_KEY_SIZE];
#ifdef USE_ATCAH_DERIVE_KEY
    uint8_t symmetric_key[ATCA_KEY_SIZE];
    atca_temp_key_t temp_key_derive;
    struct atca_derive_key_in_out derivekey_params;
#endif

    do {
#if (CRYPTOAUTH_DEVICE == DEVICE_ATECC608A)

        if ((status = detect_crypto_device()) != ATCA_SUCCESS) {
            break;
        }

#endif

        // Check current status of configuration lock status
        if ((status = atcab_is_locked(LOCK_ZONE_CONFIG, &is_locked)) != ATCA_SUCCESS) {
            printf("--> ָ��ִ��ʧ��_0...\r\n");
            break;
        }

        // Write configuration if it is not already locked
        if (!is_locked) {

            printf("--> Config Zone δ�����ù�...\r\n");
            printf("--> ��Ҫ��д��Կ��Data Slot ID: %u\r\n", slot);
//            printf("--> ���°�ť���м���оƬ��Կ��¼...\r\n");

            // Update the led pattern with provision led pattern
            update_led_pattern(provision_pattern);

            // Wait for the button to be pressed
//            while (LL_GPIO_IsInputPinSet(KEY_S2_GPIO_Port, KEY_S2_Pin) == 1);
//            delay_ms(100);
            printf("\r\n--> ��ʼ��¼...\r\n");

            // Trigger Configuration write
#if (CRYPTOAUTH_DEVICE == DEVICE_ATSHA204A)

            if ((status = atcab_write_config_zone(sha204_configdata)) != ATCA_SUCCESS) {
                printf("--> Config Zone д��ʧ��...\r\n");
                break;
            } else {
                printf("--> Config Zone д��ɹ�...\r\n");
            }

#elif (CRYPTOAUTH_DEVICE == DEVICE_ATECC508A)

            if ((status = atcab_write_config_zone(ecc508_configdata)) != ATCA_SUCCESS) {
                printf("--> Config Zone д��ʧ��...\r\n");
                break;
            } else {
                printf("--> Config Zone д��ɹ�...\r\n");
            }

#elif (CRYPTOAUTH_DEVICE == DEVICE_ATECC608A)

            if ((status = atcab_write_config_zone(ecc608_configdata)) != ATCA_SUCCESS) {
                printf("--> Config Zone д��ʧ��...\r\n");
                break;
            } else {
                printf("--> Config Zone д��ɹ�...\r\n");
            }

            if (cfg_ateccx08a_i2c_default.atcai2c.slave_address != ecc608_configdata[16]) {
                atcab_wakeup();
                atcab_sleep();
                cfg_ateccx08a_i2c_default.atcai2c.slave_address = ecc608_configdata[16];
                atcab_init(&cfg_ateccx08a_i2c_default);
                printf("--> ATECC608A �������µ� I2C ���豸��ַ: 0x%02X\r\n", cfg_ateccx08a_i2c_default.atcai2c.slave_address);
            }

#endif


            // Lock Configuration Zone on completing configuration
            if ((status = atcab_lock_config_zone()) != ATCA_SUCCESS) {
                printf("--> Config Zone ����ʧ��...\r\n");
                break;
            } else {
                printf("--> Config Zone �����ɹ�...\r\n");
            }
        } else {
            printf("--> Config Zone �ѱ����ò�������...\r\n");
        }


        // Check current status of data zone lock status
        if ((status = atcab_is_locked(LOCK_ZONE_DATA, &is_locked)) != ATCA_SUCCESS) {
            printf("--> ָ��ִ��ʧ��_1...\r\n");
            break;
        }

        // Write shared secret if it is not already locked
        if (!is_locked) {

            // Read the serial number from the device
            if ((status = atcab_read_serial_number(sn)) != ATCA_SUCCESS) {
                printf("--> ��ȡ���к�ʧ��...\r\n");
                break;
            } else {
//                printf("--> ���к�: 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\r\n", sn[0], sn[1], sn[2], sn[3], sn[4], sn[5], sn[6], sn[7], sn[8]);
            }
            
            get_master_key(master_key);

#ifdef USE_ATCAH_DERIVE_KEY
            memset(&temp_key_derive, 0, sizeof(temp_key_derive));
            temp_key_derive.valid = 1;
            // 32 bytes TempKey ( SN[0:8] with padded 23 zeros used in symmetric key calculation)
            memcpy(temp_key_derive.value, sn, sizeof(sn));

            // Parameters used deriving the symmetric key
            derivekey_params.mode = 0;
            derivekey_params.target_key_id = slot;
            derivekey_params.parent_key = master_key;
            derivekey_params.sn = sn;
            derivekey_params.target_key = symmetric_key;
            derivekey_params.temp_key = &temp_key_derive;

            // calculate the symmetric_diversified_key
            // ͨ�� master_key ���������������SHA-256�������һ���Գ���Կ
            if ((status = atcah_derive_key(&derivekey_params)) != ATCA_SUCCESS) {
                printf("--> �Գ���Կ����ʧ��...\r\n");
                break;
            } else {
                printf("--> �Գ���Կ����ɹ�...\r\n");
            }

            // Store the symmetric diversified key in device
            // ����������ĶԳ���Կ�洢�� Data Slot ��
            if ((status = atcab_write_zone(ATCA_ZONE_DATA, slot, 0, 0, symmetric_key, ATCA_KEY_SIZE)) != ATCA_SUCCESS) {
#else
            // �� master_key ֱ�Ӵ洢�� Data Slot ��
            if ((status = atcab_write_zone(ATCA_ZONE_DATA, slot, 0, 0, master_key, ATCA_KEY_SIZE)) != ATCA_SUCCESS) {
#endif
                printf("--> Data Zone Slot[%u]: ��Կд��ʧ��...\r\n", slot);
                break;
            } else {
                printf("--> Data Zone Slot[%u]: ��Կд��ɹ�...\r\n", slot);
            }

            // Lock the data zone of the device
            if ((status = atcab_lock_data_zone()) != ATCA_SUCCESS) {
                printf("--> Data Zone ����ʧ��...\r\n");
                break;
            } else {
                printf("--> Data Zone �����ɹ�...\r\n");
            }

#if (CRYPTOAUTH_DEVICE == DEVICE_ATECC508A) || (CRYPTOAUTH_DEVICE == DEVICE_ATECC608A)

            if ((status = atcab_lock_data_slot(slot)) != ATCA_SUCCESS) {
                printf("--> Data Zone Slot[%u]: ����ʧ��...\r\n", slot);
                break;
            } else {
                printf("--> Data Zone Slot[%u]: �����ɹ�...\r\n", slot);
            }

#endif

            update_led_pattern(NULL);

//            printf("����оƬ��Կ��¼�ɹ�...\r\n");
//            printf("���°�ť�Լ���...");

            // Press the button to start proceeding
//            while (LL_GPIO_IsInputPinSet(KEY_S2_GPIO_Port, KEY_S2_Pin) == 1);
//            delay_ms(100);
//            printf("OK\r\n");
            ATCA_ProvisionCnt++;
            printf("--> �� %u Ƭ����оƬ��д�ɹ�...\r\n", ATCA_ProvisionCnt);
        } else {
            printf("--> Data Zone   �ѱ����ò�������...\r\n\r\n");
        }

    } while (0);

    return status;
}

#if (CRYPTOAUTH_DEVICE == DEVICE_ATECC608A)
ATCA_STATUS detect_crypto_device(void)
{
    ATCA_STATUS status;

    uint8_t addr_list[] = { ECC608A_DEFAULT_ADDRESS, ECC608A_ADDRESS };

    for (uint8_t addr_index = 0; addr_index < (sizeof(addr_list) / sizeof(addr_list[0])); addr_index++) {
        cfg_ateccx08a_i2c_default.atcai2c.slave_address = addr_list[addr_index];

        if ((status = atcab_init(&cfg_ateccx08a_i2c_default)) == ATCA_SUCCESS) {
            /* ECC608A with addr_list[addr_index] address is found */
            break;
        }
    }

    return status;
}
#endif

#endif
