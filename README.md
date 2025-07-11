# Typed Doubly Linked List implementation with C macros in 100 LOC

## Macros

- `dll`: generate full list type with specified value type (example: `dll(int)`)
- `dll_init`: simple initialization of the struct type (example: `dll(int) l = dll_init();`)
- `dll_push_tail`: push an item as the new tail (example: `dll_push_tail(l, 2);`)
- `dll_push_head`: push an item as the new head (example: `dll_push_head(l, 2);`)
- `dll_push_after`: push an item after the specified item (example: `dll_push_after(l, l->head, 2);`)
- `dll_push_before`: push an item after the specified item (example: `dll_push_after(l, l->head, 2);`)
- `dll_remove`: removes the specified item (example: `dll_remove(l, l.head)`)
- `dll_for_each`: iterates over the list giving you a symbol as each item (example: `dll_for_each(l, v)`)
- `dll_rfor_each`: iterates in reverse (example: `dll_rfor_each(l, v)`)
- `dll_pop`: removes the tail and returns its value
- `dll_hpop`: removes the head and returns its value
- `dll_destroy`: frees up the list

## Example

```c
dll(int) l = dll_init();

dll_push_tail(l, 4);
dll_push_head(l, 2);
dll_push_head(l, 1);
dll_push_after(l, l.tail->prev, 3);

dll_remove(l, l.tail);

dll_for_each(l, v) printf("%d\n", v->val); // 1->2->3

printf("%d\n", dll_pop(l)); // 3

dll_destroy(l);
```

# Credits
[dnkl](https://codeberg.org/dnkl/)
