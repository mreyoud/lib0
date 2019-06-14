/* see LICENSE file for copyright and license details. */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void fatal(const char * const fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	if (fmt[0] && fmt[strlen(fmt) - 1] == ':') {
		fputc(' ', stderr);
		perror(NULL);
	}
	abort();
}

