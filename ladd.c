/* see LICENSE file for copyright and license details. */
#include "lib0.h"

void ladd(struct list *lst, struct list *itm) {
	lst->n->p = itm;
	itm->n = lst->n;
	itm->p = lst;
	lst->n = itm;
}

