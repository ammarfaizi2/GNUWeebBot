// SPDX-License-Identifier: GPL-2.0-only
/*
 *  src/gwbot/include/gwbot/vt_hexdump.h
 *
 *  Hexdump macro for GNUWeebBot
 *
 *  Copyright (C) 2021  Ammar Faizi
 */

#ifndef GWBOT__VT_HEXDUMP_H
#define GWBOT__VT_HEXDUMP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>


#define CHDOT(C) (((32 <= (C)) && ((C) <= 126)) ? (C) : '.')
#define VT_HEXDUMP(PTR, SIZE)							\
do {										\
	size_t i, j, k = 0, l, __size = (size_t)(SIZE);				\
	uint8_t *__ptr = (uint8_t *)(PTR);					\
	printf("================== VT_HEXDUMP ==================\n");		\
	printf("File\t\t: %s:%d\n", __FILE__, __LINE__);			\
	printf("Function\t: %s()\n", __func__);					\
	printf("Address\t\t: 0x%016" PRIxPTR "\n", (uintptr_t)__ptr);		\
	printf("Dump size\t: %zu bytes\n", (__size));				\
	printf("\n");								\
	for (i = 0; i <= (__size/16); i++) {					\
		printf("0x%016" PRIxPTR "|  ", (uintptr_t)(__ptr + i * 16));	\
		l = k;								\
		for (j = 0; (j < 16) && (k < __size); j++, k++) {		\
			printf("%02x ", __ptr[k]);				\
		}								\
		while (j++ < 16)						\
			printf("   ");						\
		printf(" |");							\
		for (j = 0; (j < 16) && (l < __size); j++, l++) {		\
			printf("%c", CHDOT(__ptr[l]));				\
		}								\
		printf("|\n");							\
	}									\
	printf("================================================\n");		\
	fflush(stdout);								\
} while (0)

#include <gwbot/base.h>

#endif /* #ifndef GWBOT__VT_HEXDUMP_H */
