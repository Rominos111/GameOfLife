// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 03/09/2020.

#ifndef GAMEOFLIFE_QUEUE_H
#define GAMEOFLIFE_QUEUE_H

#include <stdint.h> // uint8_t, uint32_t
#include <stdbool.h> // bool
#include <stdlib.h> // malloc, free, NULL, size_t
#include <stdio.h> // fprintf, stderr
#include <signal.h> // raise, SIGILL

typedef uint8_t* QueueValue;

/**
 * Élément d'une Queue
 */
struct QueueElem {
    /**
     * Valeur de l'élément
     */
    QueueValue value;

    /**
     * Élément suivant
     */
    struct QueueElem* next;
};

/**
 * Queue, aka file
 */
typedef struct {
    /**
     * Premier élément ajouté, premier à sortir
     */
    struct QueueElem* first;

    /**
     * Dernier élément ajouté
     */
    struct QueueElem* last;

    /**
     * Taille de la file
     */
    uint32_t size;
} Queue;

/**
 * Crée une Queue
 *
 * @return Queue
 */
Queue createQueue();

/**
 * Supprime une Queue
 *
 * @param queue Queue
 */
void deleteQueue(Queue* queue);

/**
 * Ajoute un élément à la Queue
 *
 * @param item Item à ajouter
 * @param queue Queue, sera modifiée
 *
 * @return Queue modifiée
 */
Queue* enqueue(QueueValue item, Queue* queue);

/**
 * Retire un élément
 *
 * @param queue Queue où retirer un élément
 *
 * @throws SIGILL Si la Queue est vide
 *
 * @return Élément retiré
 */
QueueValue dequeue(Queue* queue);

/**
 * Teste si une Queue est vide ou non
 *
 * @param queue Queue
 *
 * @return Queue vide ou non
 */
bool isEmpty(Queue queue);

/**
 * Retourne la taille d'une Queue
 *
 * @param queue Queue
 *
 * @return Taille
 */
size_t getSize(Queue queue);

#endif //GAMEOFLIFE_QUEUE_H
