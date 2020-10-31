// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 03/09/2020.

#include "queue.h"

Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->size = 0;
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}

void deleteQueue(Queue* queue) {
    while (!isEmpty(*queue)) {
        dequeue(queue);
    }
    free(queue);
}

Queue* enqueue(QueueValue item, Queue* queue) {
    struct QueueElem* node = malloc(sizeof(struct QueueElem));

    node->value = item;
    node->next = NULL;

    if (isEmpty(*queue)) {
        queue->first = node;
    }
    else {
        queue->last->next = node;
    }

    queue->last = node;
    queue->size++;

    return queue;
}

QueueValue dequeue(Queue* queue) {
    QueueValue elem = 0;

    if (isEmpty(*queue)) {
        fprintf(stderr, "Dequeue on empty queue.");
        raise(SIGILL);
    }
    else {
        struct QueueElem* node = queue->first;

        elem = node->value;

        queue->first = node->next;

        if (queue->first == NULL) {
            queue->last = NULL;
        }

        if (node != NULL) {
            free(node);
        }
    }

    queue->size --;

    return elem;
}

bool isEmpty(Queue queue) {
    return queue.size == 0;
}

size_t getSize(Queue queue) {
    return queue.size;
}
