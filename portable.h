/*
 * This file is was written by Brian Callahan <bcallah@devio.us>
 * and released into the Public Domain.
 */

#include "config.h"

#ifndef HAVE_ASPRINTF
extern int	 asprintf(char **, const char *, ...);
#endif

#ifndef HAVE_REALLOCARRAY
extern void	*reallocarray(void *, size_t, size_t);
#endif

#ifndef HAVE_STRLCPY
extern size_t	 strlcpy(char *, const char *, size_t);
#endif

#ifndef HAVE_PROGNAME
extern char	*__progname;
#endif

#ifndef _PATH_TMP
#define _PATH_TMP "/tmp/"
#endif
