# femboywm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c femboywm.c util.c fsUtils.c
OBJ = ${SRC:.c=.o}

all: options femboywm

options:
	@echo femboywm build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	cp config.def.h $@

femboywm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f femboywm ${OBJ} femboywm-${VERSION}.tar.gz

dist: clean
	mkdir -p femboywm-${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk\
		femboywm.1 drw.h util.h ${SRC} femboywm.png transient.c femboywm-${VERSION}
	tar -cf femboywm-${VERSION}.tar femboywm-${VERSION}
	gzip femboywm-${VERSION}.tar
	rm -rf femboywm-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f femboywm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/femboywm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < femboywm.1 > ${DESTDIR}${MANPREFIX}/man1/femboywm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/femboywm.1

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/femboywm\
		${DESTDIR}${MANPREFIX}/man1/femboywm.1

.PHONY: all options clean dist install uninstall
