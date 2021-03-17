#include "mpool.h"
#include <assert.h>
#include <stdio.h>

struct foo
{
    int               a;
    struct llist_node node;
    int               b;
    int               c;
};

int main(void)
{
    struct mpool pool;
    MPOOL_INIT(&pool, struct foo, 3, node);

    struct foo* f0 = CONTAINER_OF(mpool_alloc(&pool), struct foo, node);
    f0->a = 0;
    f0->b = 0;
    f0->c = 0;
    printf("%d %d %d\n", f0->a, f0->b, f0->c);

    struct foo* f1 = CONTAINER_OF(mpool_alloc(&pool), struct foo, node);
    f1->a = 1;
    f1->b = 1;
    f1->c = 1;
    printf("%d %d %d\n", f1->a, f1->b, f1->c);

    struct foo* f2 = CONTAINER_OF(mpool_alloc(&pool), struct foo, node);
    f2->a = 2;
    f2->b = 2;
    f2->c = 2;
    printf("%d %d %d\n", f2->a, f2->b, f2->c);

    assert(mpool_alloc(&pool) == NULL);

    mpool_free(&pool, &f1->node);

    f1 = CONTAINER_OF(mpool_alloc(&pool), struct foo, node);
    printf("%d %d %d\n", f1->a, f1->b, f1->c);

    mpool_deinit(&pool);
}
