/*
 * This file written by Brian Callahan <bcallah@devio.us>
 * and released into the Public Domain.
 */

/* Minimal asprintf routine, for those that need it. */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef NEED_ASPRINTF

int
asprintf(char **ret, const char *format, ...)
{
	int retval;
	va_list ap;

	va_start(ap, format);

	if ((*ret = malloc(32)) == NULL) {
		retval = -1;
		goto out;
	}

	retval = vsnprintf(*ret, 32, format, ap);

out:
	va_end(ap);

	return retval;
}

#endif /* NEED_ASPRINTF */
