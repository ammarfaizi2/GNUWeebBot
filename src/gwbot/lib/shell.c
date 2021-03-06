// SPDX-License-Identifier: GPL-2.0-only
/*
 *  src/gwbot/lib/shell.c
 *
 *  Function to spawn shell for TeaVPN2
 *
 *  Copyright (C) 2021  Ammar Faizi
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gwbot/print.h>
#include <gwbot/lib/shell.h>
#include <gwbot/lib/string.h>


char *shell_exec(const char *cmd, char *buf, size_t buflen, size_t *outlen)
{
	int err;
	FILE *handle;
	bool use_malloc;
	size_t read_len;

	use_malloc = (buf == NULL);

	if (unlikely(use_malloc)) {
		buf = malloc(buflen);
		if (unlikely(buf == NULL)) {
			err = errno;
			pr_err("malloc(): " PRERF, PREAR(err));
			goto out_err;
		}
	}

	handle = popen(cmd, "r");
	if (unlikely(handle == NULL)) {
		err = errno;
		pr_err("popen(\"%s\", \"r\"): " PRERF, cmd, PREAR(err));
		goto out_err;
	}

	memset(buf, 0, buflen);
	read_len = fread(buf, sizeof(char), buflen, handle);
	pclose(handle);

	if (likely(outlen))
		*outlen = read_len;

	return buf;
out_err:
	if (unlikely(use_malloc))
		free(buf);
	return NULL;
}
