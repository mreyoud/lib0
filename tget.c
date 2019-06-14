/* see LICENSE file for copyright and license details. */
#include "lib0.h"

struct node *tget(const struct tree *tree, const struct node *key) {
	struct node *node = tree->root;
	int res, isleft = 0;
	while (node) {
		if (!(res = tree->fn(node, key)))
			return node;
		if ((isleft = res > 0))
			node = !node->lt ? node->l : NULL;
		else
			node = !node->rt ? node->r : NULL;
	}
	return NULL;
}

