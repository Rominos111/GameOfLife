// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 03/09/2020.

#include "game.h"

void createGame(Game** g, Map map) {
    *g = malloc(sizeof(Game));

    (*g)->active = createQueue();
    (*g)->toActivate = createQueue();
    (*g)->map = map;

    for (size_t row = 0; row < map.rows; row++) {
        for (size_t col = 0; col < map.cols; col++) {
            if (isActive(map, row, col)) {
                enqueue(getMapAddress(map, row, col), &((*g)->active));
            }
        }
    }
}

void update(Game* game) {
    Queue active = game->active;

    while (!isEmpty(active)) {
        uint8_t* cell = dequeue(&active);

        for (int i=-1; i<=1; i++) {
            for (int j=-1; j<=1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                uint8_t* neighbor = getNeighborAddress(game->map, cell, i, j);

                if (neighbor == NULL) {
                    continue;
                }

                // Applique le masque pour framecount
                // Ajoute 1 voisin
                // Si voisin >= 2 on ajoute aux candidats potentiels
            }
        }
    }

    // Bien penser à update cellules actives

    game->frameCount++;
}

void deleteGame(Game* game) {
    deleteMap(&(game->map));
    deleteQueue(&(game->active));
    deleteQueue(&(game->toActivate));
    free(game);
}
