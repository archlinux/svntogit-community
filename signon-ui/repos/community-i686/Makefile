# Add here the language codes for the translated .po files:
LINGUAS =

I18N_DOMAIN = signon-ui

PO_FILES = $(addsuffix .po, $(LINGUAS))
MO_FILES = $(addsuffix .mo, $(LINGUAS))

DEL_FILE = rm -f
INSTALL = /usr/bin/install -c -m 644
MKDIR = mkdir -p

all: $(MO_FILES)

install: all
	for lang in $(LINGUAS); do \
		dir=$(INSTALL_ROOT)/usr/share/locale/$$lang/LC_MESSAGES; \
		$(MKDIR) $$dir; \
		$(INSTALL) $$lang.mo $$dir/$(I18N_DOMAIN).mo; \
	done

%.mo: %.po
	msgfmt -o "$@" "$<"

clean:
	-$(DEL_FILE) $(MO_FILES)

distclean: clean

check: all

