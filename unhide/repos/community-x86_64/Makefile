PREFIX ?= /usr/local

BINS ?= unhide-linux unhide_rb unhide-tcp unhide-posix
LINUX_SRC:= $(sort $(wildcard unhide-linux*.c))

CFLAGS ?= -Wall
CFLAGS += -Wall

all: $(BINS)
unhide-linux: $(LINUX_SRC) unhide-output.c
unhide-linux: LDFLAGS += -pthread
unhide-tcp: unhide-tcp.c unhide-tcp-fast.c unhide-output.c

install:
	install -d -m 755 '$(DESTDIR)$(PREFIX)'/bin
	for bin in $(BINS); do \
	    install -m 755 $$bin '$(DESTDIR)$(PREFIX)'/bin/$$bin; \
	done
	for man in man/*.8 man/*/*.8; do \
	    lang=$${man%/*}; \
	    lang=$${lang#man}; \
	    manfile=$${man##*/}; \
	    install -d -m 755 '$(DESTDIR)$(PREFIX)'/share/man/$$lang/man8; \
	    install -m 644 $$man '$(DESTDIR)$(PREFIX)'/share/man/$$lang/man8/$$manfile; \
	done
