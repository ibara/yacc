yacc
====
`yacc`, or `oyacc`, is a portable version of the OpenBSD Yacc program.

It is suitable for ensuring standard Yacc compliance, for older Unix machines
that do not have a free Yacc or have a very old Yacc, or for users that do not
need the bells and whistles of `byacc` or `bison`.

`yacc` requires `GNU Make` to build (except on OpenBSD). It is known to build
and run on all *BSD flavors, Linux, Mac OS X, Cygwin, AIX, and Solaris. It is
very likely to run on other Unix flavors; please let me know if you are using
this on a Unix not listed here so that I may add it to the list.

To build, run:
```
$ make
# make install
```
or
```
$ make PROG=oyacc
# make install
```
substituting `gmake` for `make` if necessary.

Use the first if you do not already have a `yacc` program on your machine, or
wish to replace your system `yacc`. Use the second if you already have a `yacc`
program on your machine and do not wish to replace it.
