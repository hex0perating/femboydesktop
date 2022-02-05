# femenu - dynamic menu
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c femenu.c stest.c util.c
OBJ = $(SRC:.c=.o)

all: options femenu stest

options:
	@echo femenu build options:
	@echo "CFLAGS   = $(CFLAGS)"
	@echo "LDFLAGS  = $(LDFLAGS)"
	@echo "CC       = $(CC)"

.c.o:
	$(CC) -c $(CFLAGS) $<

config.h:
	cp config.def.h $@

$(OBJ): arg.h config.h config.mk drw.h

femenu: femenu.o drw.o util.o
	$(CC) -o $@ femenu.o drw.o util.o $(LDFLAGS)

stest: stest.o
	$(CC) -o $@ stest.o $(LDFLAGS)

clean:
	rm -f femenu stest $(OBJ) femenu-$(VERSION).tar.gz

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f femenu femenu_path femenu_run stest $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/femenu
	chmod 755 $(DESTDIR)$(PREFIX)/bin/femenu_path
	chmod 755 $(DESTDIR)$(PREFIX)/bin/femenu_run
	chmod 755 $(DESTDIR)$(PREFIX)/bin/stest
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	sed "s/VERSION/$(VERSION)/g" < femenu.1 > $(DESTDIR)$(MANPREFIX)/man1/femenu.1
	sed "s/VERSION/$(VERSION)/g" < stest.1 > $(DESTDIR)$(MANPREFIX)/man1/stest.1
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/femenu.1
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/stest.1

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/femenu\
		$(DESTDIR)$(PREFIX)/bin/femenu_path\
		$(DESTDIR)$(PREFIX)/bin/femenu_run\
		$(DESTDIR)$(PREFIX)/bin/stest\
		$(DESTDIR)$(MANPREFIX)/man1/femenu.1\
		$(DESTDIR)$(MANPREFIX)/man1/stest.1

.PHONY: all options clean dist install uninstall