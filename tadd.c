/* see LICENSE file for copyright and license details. */
#include "lib0.h"

struct node *tadd(struct tree *t, struct node *node) {
	struct node *key, *parent = NULL;
	int res, isleft = 0;
	key = t->root;
	while (key) {
		if ((res = t->fn(key, node)) == 0)
			return key;
		parent = key;
		if ((isleft = res > 0))
			key = !key->lt ? key->l : NULL;
		else
			key = !key->rt ? key->r : NULL;
	}
	if (!parent) {
		node->l = NULL;
		node->r = NULL;
		node->lt = 0;
		node->rt = 0;
		t->root = node;
		return NULL;
	}
	if (isleft) {
		node->l = parent->lt ? parent->l : NULL;
		node->lt = 1;
		node->r = parent;
		node->rt = 1;
		parent->l = node;
		parent->lt = 0;
	} else {
		node->l = parent;
		node->lt = 1;
		node->r = parent->rt ? parent->r : NULL;
		node->rt = 1;
		parent->r = node;
		parent->rt = 0;
	}
	return NULL;
}

