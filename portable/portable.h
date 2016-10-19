/*
 * This file is was written by Brian Callahan <bcallah@devio.us>
 * and released into the Public Domain.
 */

#if defined(__linux__) || defined(__CYGWIN__) || defined (_AIX) || defined(__sun) || defined(__APPLE__)
void   *reallocarray(void *, size_t, size_t);
#endif

#if defined(_AIX) || defined(__sun)
int	asprintf(char **, const char *, ...);
#endif

#if defined(__linux__) || defined(_AIX)
size_t	strlcpy(char *, const char *, size_t);
#endif

#ifndef _PATH_TMP
#define _PATH_TMP "/tmp/"
#endif

#if defined(_AIX) || defined(__sun)
char *__progname;
#endif
