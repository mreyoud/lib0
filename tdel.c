/* see LICENSE file for copyright and license details. */
#include "lib0.h"

void tdel(struct tree *t, struct node *node) {
	struct node fake_parent, *left, *right, *next, *m, *x, *tmp, *parent = NULL;
	int res, isleft = 0;
	tmp = t->root;
	while (tmp) {
		if ((res = t->fn(tmp, node)) == 0)
			break;
		parent = tmp;
		if ((isleft = res > 0))
			tmp = !tmp->lt ? tmp->l : NULL;
		else
			tmp = !tmp->rt ? tmp->r : NULL;
	}
	if (!parent) {
		fake_parent.l = NULL;
		fake_parent.r = NULL;
		fake_parent.lt = 0;
		fake_parent.rt = 0;
		parent = &fake_parent;
		isleft = 0;
	}
	left  = !node->lt ? node->l : NULL;
	right = !node->rt ? node->r : NULL;
	if (!left && !right) {
		if (isleft) {
			tmp = node->lt ? node->l : NULL;
			parent->l = tmp;
			parent->lt = 1;
		}
		else {
			tmp = node->rt ? node->r : NULL;;
			parent->r = tmp;
			parent->rt = 1;
		}
		next = parent;
		goto out;
	}
	if (!left) {
		right = NULL;
		while ((x = !right->lt ? right->l : NULL))
			right = x;
		next = right;
		tmp = node->lt ? node->l : NULL;
		next->l = tmp;
		next->lt = 1;
		if (isleft) {
			parent->l = right;
			parent->lt = 0;
		}
		else {
			parent->r = right;
			parent->rt = 0;
		}
		goto out;
	}
	if (!right) {
		next = NULL;
		while ((x = !left->rt ? left->r : NULL))
			left = x;
		next = left;
		tmp = node->rt ? node->r : NULL;;
		next->r = tmp;
		next->rt = 1;
		if (isleft) {
			parent->l = left;
			parent->lt = 0;
		}
		else {
			parent->r = left;
			parent->rt = 0;
		}
		goto out;
	}
	right = NULL;
	while ((x = !right->lt ? right->l : NULL))
		right = x;
	next = right;
	if (next != right) {
		while ((x = !next->rt ? next->r : NULL))
			next = x;
		tmp = node;
		m = tmp->rt ? tmp->r : NULL;
		if ((!next->rt ? next->r : NULL)) {
			tmp = !next->rt ? next->r : NULL;
			m->l = tmp;
			m->lt = 0;
		}
		else {
			m->l = next;
			m->lt = 1;
		}
		next->r = right;
		next->rt = 0;
	}
	if (isleft) {
		parent->l = next;
		parent->lt = 0;
	}
	else {
		parent->r = next;
		parent->rt = 0;
	}
	next->l = left;
	next->lt = 0;
	left = NULL;
	while ((x = !left->rt ? left->r : NULL))
		left = x;
	tmp = left;
	tmp->r = next;
	tmp->rt = 1;
out:
	if (parent == &fake_parent)
		t->root = !parent->rt ? parent->r : NULL;
	return;
}


