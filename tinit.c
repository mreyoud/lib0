/* see LICENSE file for copyright and license details. */
#include "lib0.h"

void tinit(struct tree *t, tcmpfn cmp) {
	t->root = NULL;
	t->fn = cmp;
}

