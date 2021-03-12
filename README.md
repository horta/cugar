# cugar library

C99 compliant.

## Functions

```c
void         list_init(struct list* list);
struct list* list_head(struct list const* list);
struct list* list_tail(struct list const* list);
struct list* list_next(struct list const* list, struct list* item);
void         list_ins(struct list* where, struct list* item);
void         list_add(struct list* list, struct list* item);
void         list_del(struct list* item);
```

## Usage

```c
#include "list.h"

struct Foo
{
    int         value;
    struct list link;
};

int main(void)
{
    struct list list;
    list_init(&list);

    struct Foo foo = {.value = 0};

    list_add(&list, &foo.link);

    return container_of(list_head(&list), struct Foo, link)->value;
}
```

## Example

```bash
cc list_example.c -Wall -pedantic -std=c99 -o ./list_example
```
