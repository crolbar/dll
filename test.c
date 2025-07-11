#include "dll.h"
#include <assert.h>
#include <stdio.h>

int
main()
{
    dll(int) dll = dll_init();
    typeof(*(dll).tail)* node;

    printf("test push_after 1 =================\n");
    {
        dll_push_after(dll, dll.head, 1);
        dll_push_after(dll, dll.head, 2);
        dll_push_after(dll, dll.head->next, 3);
        dll_push_after(dll, dll.head->next->next, 4);
        dll_push_after(dll, dll.head->next->next->next, 5);
        dll_push_after(dll, dll.head->next->next->next->next, 6);

        assert(dll.tail->next == NULL);
        assert(dll.head->prev == NULL);
        assert(dll.size == 6);

        // h-> 1, 2, 3, 4, 5, 6 <-t
        assert(dll.head->val == 1);
        assert(dll.head->next->val == 2);
        assert(dll.head->next->next->val == 3);
        assert(dll.head->next->next->next->val == 4);
        assert(dll.head->next->next->next->next->val == 5);
        assert(dll.head->next->next->next->next->next->val == 6);
        assert(dll.tail->val == 6);
        assert(dll.tail->prev->val == 5);
        assert(dll.tail->prev->prev->val == 4);
        assert(dll.tail->prev->prev->prev->val == 3);
        assert(dll.tail->prev->prev->prev->prev->val == 2);
        assert(dll.tail->prev->prev->prev->prev->prev->val == 1);

        node = (dll).head;
        while (node != NULL) {
            printf("%d", node->val);
            node = node->next;
        }
        printf("\n");

        printf("\n");

        node = (dll).tail;
        while (node != NULL) {
            printf("%d", node->val);
            node = node->prev;
        }
        printf("\n");

        dll_destroy(dll);
    }
    printf("test push_after 1 passed\n");

    printf("test push_after 2 =================\n");
    {
        dll_push_after(dll, dll.tail, 80);
        dll_push_after(dll, dll.head, 20);
        dll_push_after(dll, dll.tail, 1);
        dll_push_after(dll, dll.head->next, 30);
        dll_push_after(dll, dll.head, 0);

        // -> 80
        // -> 80, 20
        assert(dll.tail->next == NULL);
        assert(dll.head->prev == NULL);

        assert(dll.size == 5);

        assert(dll.head->val == 80);
        assert(dll.head->next->val == 0);
        assert(dll.head->next->next->val == 20);
        assert(dll.head->next->next->next->val == 30);
        assert(dll.head->next->next->next->next->val == 1);

        assert(dll.tail->val == 1);
        assert(dll.tail->prev->next->val == 1);
        assert(dll.tail->prev->prev->next->val == 30);
        assert(dll.tail->prev->prev->val == 20);
        assert(dll.tail->prev->prev->prev->val == 0);
        assert(dll.tail->prev->prev->prev->prev->val == 80);

        node = (dll).head;
        while (node != NULL) {
            printf("%d, ", node->val);
            node = node->next;
        }
        printf("\n");

        printf("\n");

        node = (dll).tail;
        while (node != NULL) {
            printf("%d, ", node->val);
            node = node->prev;
        }
        printf("\n");

        dll_destroy(dll);
    }
    printf("test push_after 1 passed \n");

    printf("test push_before 1 ==========\n");
    {
        dll_push_before(dll, NULL, 0);
        dll_push_before(dll, dll.head, 1);
        dll_push_before(dll, dll.tail, 2);
        dll_push_before(dll, dll.head->next, 3);
        dll_push_before(dll, dll.tail->prev, 4);
        dll_push_before(dll, dll.head, 5);

        assert(dll.tail->next == NULL);
        assert(dll.head->prev == NULL);
        assert(dll.size == 6);

        // -> 5 1 3 4 2 0
        assert(dll.head->val == 5);
        assert(dll.head->next->val == 1);
        assert(dll.head->next->next->val == 3);
        assert(dll.head->next->next->next->val == 4);
        assert(dll.head->next->next->next->next->val == 2);
        assert(dll.head->next->next->next->next->next->val == 0);
        assert(dll.tail->val == 0);
        assert(dll.tail->prev->prev->next->val == 2);
        assert(dll.tail->prev->prev->prev->next->val == 4);
        assert(dll.tail->prev->prev->prev->prev->next->val == 3);
        assert(dll.tail->prev->prev->prev->prev->val == 1);
        assert(dll.tail->prev->prev->prev->prev->prev->val == 5);

        node = (dll).head;
        while (node != NULL) {
            printf("%d, ", node->val);
            node = node->next;
        }
        printf("\n");

        printf("\n");

        node = (dll).tail;
        while (node != NULL) {
            printf("%d, ", node->val);
            node = node->prev;
        }
        printf("\n");

        dll_destroy(dll);
    }
    printf("test push_before 1 passed \n");

    printf("test push_before push_after 1 ==========\n");
    {
        dll_push_before(dll, dll.tail, 4);
        dll_push_before(dll, dll.head, 0);
        dll_push_after(dll, dll.head, 2);
        dll_push_before(dll, dll.head->next, 1);
        dll_push_after(dll, dll.tail->prev, 3);

        assert(dll.tail->next == NULL);
        assert(dll.head->prev == NULL);
        assert(dll.size == 5);

        assert(dll.head->val == 0);
        assert(dll.head->next->val == 1);
        assert(dll.head->next->next->val == 2);
        assert(dll.tail->prev->prev->val == 2);
        assert(dll.tail->prev->val == 3);
        assert(dll.tail->val == 4);

        dll_destroy(dll);
    }
    printf("test push_before push_after 1 passed\n");

    printf("test push_before push_after 1 ==========\n");
    {
        dll_push_before(dll, dll.tail, 4);
        dll_push_before(dll, dll.head, 0);
        dll_push_after(dll, dll.head, 2);
        dll_push_before(dll, dll.head->next, 1);
        dll_push_after(dll, dll.tail->prev, 3);

        assert(dll.tail->next == NULL);
        assert(dll.head->prev == NULL);
        assert(dll.size == 5);

        assert(dll.head->val == 0);
        assert(dll.head->next->val == 1);
        assert(dll.head->next->next->val == 2);
        assert(dll.tail->prev->prev->val == 2);
        assert(dll.tail->prev->val == 3);
        assert(dll.tail->val == 4);

        dll_destroy(dll);
    }
    printf("test push_before push_after 1 passed\n");

    printf("test push head, tail 1 ==========\n");
    {
        dll_push_head(dll, 0);
        dll_push_tail(dll, 1);
        dll_push_head(dll, 2);
        dll_push_tail(dll, 4);
        dll_push_head(dll, 3);

        assert(dll.tail->next == NULL);
        assert(dll.head->prev == NULL);
        assert(dll.size == 5);

        // 3 2 0 1 4
        assert(dll.head->val == 3);
        assert(dll.head->next->val == 2);
        assert(dll.head->next->next->val == 0);
        assert(dll.tail->prev->prev->val == 0);
        assert(dll.tail->prev->val == 1);
        assert(dll.tail->val == 4);

        dll_destroy(dll);
    }
    printf("test push head, tail 1 passed\n");

    printf("test for each 1 ==========\n");
    {
        dll_push_head(dll, 0);
        dll_push_tail(dll, 1);
        dll_push_head(dll, 2);
        dll_push_tail(dll, 4);
        dll_push_head(dll, 3);

        dll_rfor_each(dll, v)
        {
            printf("%d\n", v->val);
        }

        printf("\n");

        dll_for_each(dll, v)
        {
            printf("%d\n", v->val);
        }

        dll_destroy(dll);
    }
    printf("test for each 1 passed\n");

    printf("test remove 1 ==========\n");
    {
        dll_push_tail(dll, 0);
        dll_push_tail(dll, 1);
        dll_push_tail(dll, 2);
        dll_push_tail(dll, 3);
        dll_push_tail(dll, 4);

        dll_remove(dll, dll.head);

        assert(dll.tail->next == NULL);
        assert(dll.head->prev == NULL);
        assert(dll.size == 4);

        assert(dll.head->val == 1);
        assert(dll.head->next->val == 2);
        assert(dll.head->next->next->val == 3);
        assert(dll.tail->prev->val == 3);
        assert(dll.tail->val == 4);

        dll_remove(dll, dll.tail);

        assert(dll.tail->next == NULL);
        assert(dll.head->prev == NULL);
        assert(dll.size == 3);

        assert(dll.head->val == 1);
        assert(dll.head->next->val == 2);
        assert(dll.tail->prev->val == 2);
        assert(dll.tail->val == 3);

        dll_push_tail(dll, 200);
        dll_for_each(dll, v) if (v->val == 3) dll_push_before(dll, v, 4);

        assert(dll.tail->prev->val == 3);
        assert(dll.tail->prev->prev->val == 4);
        assert(dll.tail->val == 200);

        dll_remove(dll, dll.tail->prev);
        dll_remove(dll, dll.tail->prev);

        assert(dll.tail->next == NULL);
        assert(dll.head->prev == NULL);
        assert(dll.size == 3);

        assert(dll.head->val == 1);
        assert(dll.head->next->val == 2);
        assert(dll.tail->prev->val == 2);
        assert(dll.tail->val == 200);

        dll_destroy(dll);

        assert(dll.size == 0);
        assert(dll.head == NULL);
        assert(dll.tail == NULL);
    }
    printf("test remove 1 passed\n");

    printf("\n========ALL TESTS PASSED========\n");
}
