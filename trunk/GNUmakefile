MAKEFLAGS := -r

VERSION = $(shell test -d .git && git describe --tags --dirty 2>/dev/null)
ifeq ($(VERSION),)
    VERSION = 31
endif

# paths
PREFIX ?= /usr/local
bindir ?= $(PREFIX)/bin
datarootdir ?= $(PREFIX)/share
mandir ?= $(datarootdir)/man

# includes and libs
PKGCONF_DEPS := freetype2 harfbuzz libopenjp2 libjpeg x11 zlib
override CPPFLAGS += -D_GNU_SOURCE -DFFP
override CFLAGS += -g -std=c99 -pedantic -Wall -Wextra -Wshadow $(shell pkg-config --cflags $(PKGCONF_DEPS))
LDLIBS := -lpthread -lmupdf -lmupdf-third -ljbig2dec $(shell pkg-config --libs $(PKGCONF_DEPS))

# ocaml
override OCAMLFLAGS += -g -w +a -safe-string

# Some source files are stored in an OS-specific directory here.
# Divert them to the main srcdir.
ifeq ($(shell uname -s),Linux)
    VPATH := wsi/x11
else
    VPATH := wsi/cocoa # Darwin
endif

# Ensure main.cmx is last in this list:
OCAML_OBJ := utils.cmx wsi.cmx confstruct.cmx parser.cmx config.cmx ffi.cmx glutils.cmx keys.cmx utf8syms.cmx listview.cmx help.cmx main.cmx
C_OBJ := cutils.o keysym2ucs.o link.o xlib.o version.o
MODULES := unix.cmxa str.cmxa lablgl.cmxa
SRCMANS = $(wildcard adoc/*.adoc)
MANS = $(SRCMANS:.adoc=.1)

OCAMLC := ocamlopt
COMPILE.ocaml = $(OCAMLC) $(OCAMLFLAGS) -c
LINK.ocaml = $(OCAMLC) $(OCAMLFLAGS)

all: llpp $(MANS)

# dependency ordering
main.cmx: private OCAMLFLAGS += -thread -I +lablGL
main.cmx: main.cmi utils.cmx config.cmx glutils.cmx listview.cmx ffi.cmx help.cmx
config.cmx: wsi.cmx confstruct.cmx parser.cmx
confstruct.cmx: wsi.cmx
parser.cmx: utils.cmx
wsi.cmx: keys.cmx utils.cmx
listview.cmx: private OCAMLFLAGS += -I +lablGL
listview.cmx: utf8syms.cmx glutils.cmx
glutils.cmx: private OCAMLFLAGS += -I +lablGL
glutils.cmx: ffi.cmx
ffi.cmx: config.cmx
help.cmx: help.cmi utils.cmx ffi.cmx config.cmx
help.cmi: config.cmx

link.o: glfont.c
version.o: private CPPFLAGS += -DLLPP_VERSION=$(VERSION)

# ordinary targets
llpp: private OCAMLFLAGS += -I +lablGL
llpp: $(OCAML_OBJ) $(C_OBJ)
	$(LINK.ocaml) $(OUTPUT_OPTION) $(C_OBJ) -ccopt '$(LDFLAGS)' -cclib '$(LDLIBS)' $(MODULES) $(OCAML_OBJ)

confstruct.ml: genconfstr.sh
	sh $< > $@

# pattern rules
%.o: %.c
	$(COMPILE.ocaml) $(OUTPUT_OPTION) -cc '$(CC)' -ccopt '$(CFLAGS) $(CPPFLAGS)' $<

%.cmx: %.ml
	$(COMPILE.ocaml) $(OUTPUT_OPTION) $<

%.cmi: %.mli
	$(COMPILE.ocaml) $(OUTPUT_OPTION) $<

%.1: %.adoc adoc/asciidoc.conf
	a2x -d manpage -f manpage --asciidoc-opts="-f adoc/asciidoc.conf --out-file=$@.xml" $<

# special targets
clean:
	$(RM) llpp confstruct.ml $(C_OBJ) $(OCAML_OBJ) $(OCAML_OBJ:.cmx=.cmi) $(OCAML_OBJ:.cmx=.o) $(MANS) $(MANS:.1=.xml)

install:
	install -Dm755 llpp "$(DESTDIR)$(bindir)"/llpp
	install -Dm644 -t "$(DESTDIR)$(mandir)"/man1 $(MANS)
	install -Dm755 misc/llppac "$(DESTDIR)$(bindir)"/llppac
	install -Dm755 misc/llpp.inotify "$(DESTDIR)$(bindir)"/llpp.inotify
	install -Dm755 misc/llpphtml "$(DESTDIR)$(bindir)"/llpphtml
	install -Dm644 misc/llpp.desktop "$(DESTDIR)$(datarootdir)"/applications/llpp.desktop

.PHONY: all clean install
