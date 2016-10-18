/*
 * This file is was written by Brian Callahan <bcallah@devio.us>
 * and released into the Public Domain.
 */

#if defined(__linux__) || defined(__CYGWIN__) || defined (_AIX)
void   *reallocarray(void *, size_t, size_t);
#endif

#if defined(_AIX)
int	asprintf(char **, const char *, ...);
#endif

#if defined(_AIX)
size_t	strlcpy(char *, const char *, size_t);
#endif
