/*
 * This file written by Brian Callahan <bcallah@devio.us>
 * and released into the Public Domain.
 */

/* Minimal asprintf routine, for those that need it. */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int
asprintf(char **ret, const char *format, ...)
{
	int retval;
	va_list argl;

	va_start(argl, format);

	if ((retval = vsprintf(NULL, format, argl)) < 0) {
		retval = -1;
		goto out;
	}

	if ((*ret = malloc(retval + 1)) == NULL) {
		retval = -1;
		goto out;
	}

	if ((retval = vsprintf(*ret, format, argl)) < 0)
		retval = -1;

out:
	va_end(argl);

	return retval;
}
