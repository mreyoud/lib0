/* see LICENSE file for copyright and license details. */
#ifndef LIB0_H
#define LIB0_H

#include <stddef.h>

#define	LEN(X)                (sizeof(X) / sizeof((X)[0]))
#define	USED(X)               ((void)(X))
#define ABS(X)                ((X) < 0 ? -(X) : (X))
#define MIN(A, B)             (((A) < (B)) ? (A) : (B))
#define MAX(A, B)             (((A) > (B)) ? (A) : (B))
#define CAP(X, A, B)          ((X) < (A) ? (A) : (X) > (B) ? (B) : (X))
#define BTW(X, A, B)          ((A) <= (X) && (X) <= (B))
#define CMP(X, Y)             (((Y) < (X)) - ((X) < (Y)))
#define SIZEOF(T, M)          sizeof(((T *)NULL)->M)
#define OFFSETOF(T, M)        ((size_t)&(((T *)NULL)->M))
#define CONTAINEROF(P, T, M)  ((T *)((char *)(P) - OFFSETOF(T, M)))

#if defined(__cplusplus)
extern "C" {
#endif

/* list */

struct list {
	struct list *p;
	struct list *n;
};

#define LFOR(LIST, POS, TMP) \
	for (POS = (LIST)->n, TMP = POS->n; \
		POS != (LIST); \
			POS = TMP, TMP = POS->n)

#define LFORR(LIST, POS, TMP) \
	for (POS = (LIST)->p, TMP = POS->p; \
		POS != (LIST); \
			POS = TMP, TMP = POS->p)

extern void linit(struct list *);
extern void ladd(struct list *, struct list *);
extern void laddt(struct list *, struct list *);
extern void ldel(struct list *);
extern void lfor(const struct list *, void (*)(struct list *));
extern void lforr(const struct list *, void (*)(struct list *));

/* trees */

struct node {
	struct node *l;
	struct node *r;
	unsigned int lt : 1;
	unsigned int rt : 1;
};

typedef int (*tcmpfn)(const struct node *, const struct node *);

struct tree {
	struct node *root;
	tcmpfn fn;
};

extern void tinit(struct tree *, tcmpfn);
extern struct node *tget(const struct tree *, const struct node *);
extern struct node *tadd(struct tree *, struct node *);
extern void tdel(struct tree *, struct node *);

/* utility */
extern void die(const char * const, ...);
extern void fatal(const char * const, ...);
extern void warn(const char * const, ...);

#if defined(__cplusplus)
}
#endif
#endif

