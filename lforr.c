/* see LICENSE file for copyright and license details. */
#include "lib0.h"

void lforr(const struct list *lst, void (*fn)(struct list *)) {
	struct list *p, *t;
	LFORR(lst, p, t)
		fn(p);
}

