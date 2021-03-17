#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct Foo
{
    int         v;
    struct list link;
};

int main(void)
{
    struct list list;
    list_init(&list);

    struct Foo* a0 = malloc(sizeof(struct Foo));
    struct Foo* a1 = malloc(sizeof(struct Foo));
    struct Foo* a2 = malloc(sizeof(struct Foo));
    struct Foo* a3 = malloc(sizeof(struct Foo));
    struct Foo* a4 = malloc(sizeof(struct Foo));

    a0->v = 0;
    a1->v = 1;
    a2->v = 2;
    a3->v = 3;
    a4->v = 4;

    printf("%p\n", (void*)list_head(&list));
    printf("%p\n", (void*)list_tail(&list));
    printf("\n");

    list_add(&list, &a0->link);
    printf("%p\n", (void*)list_head(&list));
    printf("%p\n", (void*)list_tail(&list));
    printf("%d\n", CONTAINER_OF(list_head(&list), struct Foo, link)->v);
    printf("%d\n", CONTAINER_OF(list_tail(&list), struct Foo, link)->v);
    printf("\n");

    list_add(&list, &a1->link);
    printf("%p\n", (void*)list_head(&list));
    printf("%p\n", (void*)list_tail(&list));
    printf("%d\n", CONTAINER_OF(list_head(&list), struct Foo, link)->v);
    printf("%d\n", CONTAINER_OF(list_tail(&list), struct Foo, link)->v);
    printf("\n");

    list_add(&list, &a2->link);
    printf("%p\n", (void*)list_head(&list));
    printf("%p\n", (void*)list_tail(&list));
    printf("%d\n", CONTAINER_OF(list_head(&list), struct Foo, link)->v);
    printf("%d\n", CONTAINER_OF(list_tail(&list), struct Foo, link)->v);
    printf("\n");

    list_add(&list, &a3->link);
    printf("%p\n", (void*)list_head(&list));
    printf("%p\n", (void*)list_tail(&list));
    printf("%d\n", CONTAINER_OF(list_head(&list), struct Foo, link)->v);
    printf("%d\n", CONTAINER_OF(list_tail(&list), struct Foo, link)->v);
    printf("\n");

    for (struct list* i = list_head(&list); i; i = list_next(&list, i)) {
        printf("%d\n", CONTAINER_OF(i, struct Foo, link)->v);
    }
    printf("\n");

    list_ins(&a1->link, &a4->link);
    for (struct list* i = list_head(&list); i; i = list_next(&list, i)) {
        printf("%d\n", CONTAINER_OF(i, struct Foo, link)->v);
    }
    printf("\n");

    list_del(list_head(&list));
    for (struct list* i = list_head(&list); i; i = list_next(&list, i)) {
        printf("%d\n", CONTAINER_OF(i, struct Foo, link)->v);
    }
    printf("\n");

    list_del(list_tail(&list));
    for (struct list* i = list_head(&list); i; i = list_next(&list, i)) {
        printf("%d\n", CONTAINER_OF(i, struct Foo, link)->v);
    }
    printf("\n");

    struct list* i = list_head(&list);
    while (i) {
        struct list tmp = *i;
        list_del(i);
        i = list_next(&list, &tmp);
    }

    for (struct list* i = list_head(&list); i; i = list_next(&list, i)) {
        printf("%d\n", CONTAINER_OF(i, struct Foo, link)->v);
    }
    printf("\n");

    return 0;
}
