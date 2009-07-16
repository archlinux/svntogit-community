# Customize to fit your system

# paths
PREFIX      = /opt/plan9
MANPREFIX   = ${PREFIX}/man

# flags
VERSION     = 1
CFLAGS      = -c -I. -DPREFIX="\"${PREFIX}\"" %CFLAGS%
LDFLAGS     = -static %LDFLAGS%

# compiler
AR          = ar rc
CC          = cc
YACC        = ../yacc/9yacc
