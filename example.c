#include "dll.h"
#include <stdio.h>

struct state
{
    int value;
    int* dvalue;
    char* name;
};

int
main()
{
    dll(struct state) l = dll_init();

    {
        int* d = malloc(sizeof(*d));
        *d = 3;
        struct state s = { 2, d, "item 1" };
        dll_push_tail(l, s);
    }

    {
        int* d = malloc(sizeof(*d));
        *d = 1;
        struct state s = { 0, d, "item 2" };
        dll_push_tail(l, s);
    }

    dll_for_each(l, v)
      printf("%s: v: %d, dv: %d\n", v->val.name, v->val.value, *v->val.dvalue);

    dll_for_each(l, v) free(v->val.dvalue);
    dll_destroy(l);
}
