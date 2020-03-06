#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (q == NULL) {
        printf("No Enough Space\n");
    } else { /* What if malloc returned NULL? */
        q->head = NULL;
        q->tail = NULL;
    }
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    q->head = NULL;
    q->tail = NULL;
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */
    /* Add */
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    /* Solve: What should you do if the q is NULL? */
    if (q == NULL) {
        printf("queue is NULL\n");
        return false;
    } else {
        newh = malloc(sizeof(list_ele_t));
        if (newh == NULL)
            return false;
        char *input;
        size_t string_size;
        string_size = strlen(s);
        input = malloc(string_size);
        if (input == NULL) {
            free(newh);
            return false;
        }
        int i;
        for (i = 0; s[i] != '\0'; i++) {
            input[i] = s[i];
        }
        input[i] = '\0';
        newh->value = input;
        newh->next = q->head;
        if (q->head == NULL && q->tail == NULL)
            q->head = q->tail = newh;
        else
            q->head = newh;
        return true;
    }
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    list_ele_t *newt;
    if (q == NULL) {
        printf("queue is NULL\n");
        return false;
    } else {
        newt = malloc(sizeof(list_ele_t));
        if (newt == NULL)
            return false;
        char *input;
        size_t string_size;
        string_size = strlen(s);
        input = malloc(string_size);
        if (input == NULL) {
            free(newt);
            return false;
        }
        int i;
        for (i = 0; s[i] != '\0'; i++) {
            input[i] = s[i];
        }
        input[i] = '\0';
        newt->value = input;
        newt->next = NULL;
        if (q->head == NULL && q->tail == NULL)
            q->head = q->tail = newt;
        else {
            q->tail->next = newt;
            q->tail = newt;
        }
        return true;
    }
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* TODO: You need to fix up this code. */
    /* TODO: Remove the above comment when you are about to implement. */
    q->head = q->head->next;
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
