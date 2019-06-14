/* see LICENSE file for copyright and license details. */
#include "lib0.h"

void ldel(struct list *itm) {
	itm->p->n = itm->n;
	itm->n->p = itm->p;
	itm->n = itm;
	itm->p = itm;
}

