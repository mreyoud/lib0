# see LICENSE file for copyright and license details.

include config.mk

LIB := lib0.a
HDR := lib0.h
SRC := ${wildcard *.c}
OBJ := ${SRC:.c=.o}
MAN := lib0.7
MSC := config.mk makefile LICENSE README

all: ${LIB}

.o: .c ${HDR} config.mk
	${CC} ${CFLAGS} ${CPPFLAGS} -c -o $@ $<

${LIB}: ${OBJ}
	${AR} rc $@ $?
	${RANLIB} $@

install: ${LIB}
	mkdir -p "${DESTDIR}${EXECPREFIX}/lib"
	mkdir -p "${DESTDIR}${PREFIX}/include/"
	mkdir -p "${DESTDIR}${MANPREFIX}/man7"
	cp ${LIB} "${DESTDIR}${EXECPREFIX}/lib"
	cp ${HDR} "${DESTDIR}${PREFIX}/include"
	cp ${MAN} "${DESTDIR}${MANPREFIX}/man7"

uninstall:
	cd "${DESTDIR}${EXECPREFIX}/lib" && rm ${LIB}
	cd "${DESTDIR}${PREFIX}/include" && rm ${HDR}
	cd "${DESTDIR}${MANPREFIX}/man" && rm ${MAN}

dist: clean
	mkdir -p ${LIB}-${VERSION}
	cp -R ${MSC} ${HDR} ${SRC} ${MAN} ${LIB}-${VERSION}
	tar -cf ${LIB}-${VERSION}.tar ${LIB}-${VERSION}
	zip ${LIB}-${VERSION}.tar
	rm -rf ${LIB}-${VERSION}

clean:
	rm -f ${OBJ} ${LIB} ${LIB}-${VERSION}.tar.gz

.PHONY: all clean dist install uninstall

