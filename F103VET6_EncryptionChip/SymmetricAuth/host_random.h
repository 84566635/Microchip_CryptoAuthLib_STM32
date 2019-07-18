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
* @ ����: host_random.h
* @ ����: SummerFalls
* @ ����: 2019-5-23
* @ �汾: V1.0
* @ ����:
*/

#ifndef HOST_RANDOM_H_
#define HOST_RANDOM_H_

#include <stdint.h>

void random_seed_init(void);
void host_generate_random_number(uint8_t *rand_num);

#endif /* HOST_RANDOM_H_ */
