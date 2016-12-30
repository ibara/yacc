/*
 * This file is was written by Brian Callahan <bcallah@devio.us>
 * and released into the Public Domain.
 */

#ifdef NEED_REALLOCARRAY
void   *reallocarray(void *, size_t, size_t);
#endif

#ifdef NEED_STRLCPY
size_t	strlcpy(char *, const char *, size_t);
#endif

#ifdef NEED_ASPRINTF
int	asprintf(char **, const char *, ...);
#endif

#ifdef NEED_PROGNAME
char *__progname;
#endif

#ifndef _PATH_TMP
#define _PATH_TMP "/tmp/"
#endif
