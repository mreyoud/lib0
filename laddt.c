/* see LICENSE file for copyright and license details. */
#include "lib0.h"

void laddt(struct list *lst, struct list *itm) {
	itm->n = lst;
	itm->p = lst->p;
	lst->p->n = itm;
	lst->p = itm;
}

