/*
 * This file written by Brian Callahan <bcallah@devio.us>
 * and released into the Public Domain.
 */

/* Minimal asprintf routine, for those that need it. */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static int
_vasprintf(char **ret, const char *format, va_list ap)
{
	size_t size;
	int retval;
	va_list argl;

	va_copy(ap, argl);
	retval = vsnprintf(NULL, 0, format, argl);
	va_end(argl);

	if (retval < 0)
		return (-1);

	size = retval + 1;

	if ((*ret = malloc(size)) == NULL)
		return (-1);

	retval = vsnprintf(*ret, size, format, ap);

	return retval;
}

int
asprintf(char **ret, const char *format, ...)
{
	int retval;
	va_list argl;

	va_start(argl, format);
	retval = _vasprintf(ret, format, argl);
	va_end(argl);

	return retval;
}
