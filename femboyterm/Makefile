# ft - simple terminal
# See LICENSE file for copyright and license details.
.POSIX:

include config.mk

SRC = ft.c x.c
OBJ = $(SRC:.c=.o)

all: options ft

options:
	@echo ft build options:
	@echo "CFLAGS  = $(STCFLAGS)"
	@echo "LDFLAGS = $(STLDFLAGS)"
	@echo "CC      = $(CC)"

config.h:
	cp config.def.h config.h

.c.o:
	$(CC) $(STCFLAGS) -c $<

ft.o: config.h ft.h win.h
x.o: arg.h config.h ft.h win.h

$(OBJ): config.h config.mk

ft: $(OBJ)
	$(CC) -o $@ $(OBJ) $(STLDFLAGS)

clean:
	rm -f ft $(OBJ) ft-$(VERSION).tar.gz

dist: clean
	mkdir -p ft-$(VERSION)
	cp -R FAQ LEGACY TODO LICENSE Makefile README config.mk\
		config.def.h ft.info ft.1 arg.h ft.h win.h $(SRC)\
		st-$(VERSION)
	tar -cf - ft-$(VERSION) | gzip > ft-$(VERSION).tar.gz
	rm -rf ft-$(VERSION)

install: ft
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f ft $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/ft
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	sed "s/VERSION/$(VERSION)/g" < ft.1 > $(DESTDIR)$(MANPREFIX)/man1/ft.1
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/ft.1
	tic -sx ft.info
	@echo Please see the README file regarding the terminfo entry of ft.

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/st
	rm -f $(DESTDIR)$(MANPREFIX)/man1/st.1

.PHONY: all options clean dist install uninstall
