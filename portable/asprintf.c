/*
 * This file was written by Brian Callahan <bcallah@devio.us>
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
	retval = vsprintf(NULL, format, argl);
	if ((*ret = malloc(retval + 1)) == NULL)
		retval = -1;
	if (retval >= 0)
		retval = vsprintf(*ret, format, argl);
	else
		retval = -1;
	va_end(argl);

	return retval;
}
