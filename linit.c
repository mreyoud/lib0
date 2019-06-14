/* see LICENSE file for copyright and license details. */
#include "lib0.h"

void linit(struct list *lst) {
	lst->p = lst;
	lst->n = lst;
}

