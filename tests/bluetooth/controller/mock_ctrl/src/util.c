/*
 * Copyright (c) 2016 Nordic Semiconductor ASA
 * Copyright (c) 2016 Vinayak Kariappa Chettimada
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/types.h>
#include "util.h"

/**
 * @brief Population count: Count the number of bits set to 1
 * @details
 * TODO: Faster methods available at [1].
 * [1] http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetParallel
 *
 * @param octets     Data to count over
 * @param octets_len Must not be bigger than 255/8 = 31 bytes
 *
 * @return popcnt of 'octets'
 */
uint8_t util_ones_count_get(uint8_t *octets, uint8_t octets_len)
{
	uint8_t one_count = 0U;

	while (octets_len--) {
		uint8_t bite;

		bite = *octets;
		while (bite) {
			bite &= (bite - 1);
			one_count++;
		}
		octets++;
	}

	return one_count;
}

int util_rand(void *buf, size_t len)
{
	return 0xDEADBEEF;

}
