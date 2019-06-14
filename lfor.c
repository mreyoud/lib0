/* see LICENSE file for copyright and license details. */
#include "lib0.h"

void lfor(const struct list *lst, void (*fn)(struct list *)) {
	struct list *p, *t;
	LFOR(lst, p, t)
		fn(p);
}

