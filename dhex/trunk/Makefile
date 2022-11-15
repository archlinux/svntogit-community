CC ?= gcc
LDFLAGS ?= -L/usr/lib -L/usr/lib/ncurses
CPPFLAGS ?= -I/usr/include -I/usr/include/ncurses
CFLAGS ?= -O3 -Wall
LIBS ?= -lncurses
PREFIX ?= /usr
MANDIR ?= $(PREFIX)/share/man
BINDIR ?= $(PREFIX)/bin
DOCDIR ?= $(PREFIX)/share/doc

OFILES=buffers.o \
	configfile.o \
	correlation.o \
	gpl.o \
	hexcalc.o \
	input.o \
	machine_type.o \
	main.o \
	markers.o \
	menu.o \
	output.o \
	search.o \
	ui.o

all: dhex

dhex: $(OFILES)
	$(CC) $(LDFLAGS) -o $@ $(OFILES) $(LIBS)

install:all
	install -vDm755 dhex -t $(DESTDIR)$(BINDIR)
	install -vDm644 *.1 -t $(DESTDIR)$(MANDIR)/man1
	install -vDm644 *.5 -t $(DESTDIR)$(MANDIR)/man5
	install -vDm644 README.txt -t $(DESTDIR)$(DOCDIR)/dhex

.c.o:
	$(CC) $< -c -I. $(CPPFLAGS) $(CFLAGS) $(OPTIONS)

clean:
	rm -f dhex $(OFILES)

