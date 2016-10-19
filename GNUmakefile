# This GNUmakefile written by Brian Callahan <bcallah@devio.us>
# and released into the Public Domain.

CC?=	cc
CFLAGS?=-O2 -pipe -Wall

UNAME_S:= $(shell uname -s)

PREFIX=	/usr/local
BINDIR=	${PREFIX}/bin
MANDIR=	${PREFIX}/man/man1

PROG=	yacc
OBJS=	closure.o error.o lalr.o lr0.o main.o mkpar.o output.o reader.o \
	skeleton.o symtab.o verbose.o warshall.o

ifeq ($(UNAME_S),FreeBSD)
CFLAGS+=-D__dead="__dead2"
OBJS+=	portable/reallocarray.o
else ifeq ($(UNAME_S),NetBSD)
OBJS+=	portable/reallocarray.o
else ifeq ($(UNAME_S),DragonFly)
CFLAGS+=-D__dead="__dead2"
else ifeq ($(UNAME_S),Darwin)
CFLAGS+=-D__dead="__attribute__((__noreturn__))"
OBJS+=	portable/reallocarray.o
else ifeq ($(UNAME_S),Linux)
CFLAGS+=-D_GNU_SOURCE -D__dead="__attribute__((__noreturn__))"
OBJS+=	portable/reallocarray.o portable/strlcpy.o
else ifeq ($(UNAME_S),SunOS)
CFLAGS=	-xO2 -D__dead=""
OBJS+=	portable/asprintf.o portable/reallocarray.o
else ifeq ($(UNAME_S),AIX)
CC=	xlc
CFLAGS=	-O3 -qstrict -qro -qroconst -D__dead=""
OBJS+=	portable/asprintf.o portable/reallocarray.o portable/strlcpy.o
else ifeq ($(findstring CYGWIN,$(UNAME_S)),CYGWIN)
CFLAGS+=-D_GNU_SOURCE -D__dead="__attribute__((__noreturn__))"
OBJS+=	portable/reallocarray.o
endif

all: ${OBJS}
	${CC} ${LDFLAGS} -o ${PROG} ${OBJS}

install: all
	install -d ${DESTDIR}${BINDIR}
	install -d ${DESTDIR}${MANDIR}
	install -m 555 yyfix.sh ${DESTDIR}${BINDIR}/yyfix
	install -m 555 ${PROG} ${DESTDIR}${BINDIR}
	install -m 444 ${PROG}.1 ${DESTDIR}${MANDIR}
	install -m 444 yyfix.1 ${DESTDIR}${MANDIR}

clean:
	rm -f ${PROG} yacc oyacc ${OBJS}
