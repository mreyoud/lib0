# see LICENSE file for copyright and license details.

# version
VERSION = 0.0

# paths
PREFIX = /usr/local
EXECPREFIX = ${PREFIX}
MANPREFIX = ${PREFIX}/share/man

# flags
CPPFLAGS = -DVERSION=\"${VERSION}\"
CFLAGS = -std=c89 -pedantic -Wall -Wextra -Werror -O2

# tools
CC = cc
AR = ar
RANLIB = ranlib

