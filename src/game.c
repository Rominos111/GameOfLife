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
    uint8_t* value = getMapAddress(game->map, 3, 2);
    uint8_t* neighbor = getNeighborAddress(game->map, value, 0, 1);

    printf("%p\n", (void*) value);
    printf("%p\n", (void*) neighbor);

    game->frameCount++;
}

void deleteGame(Game* game) {
    deleteMap(&(game->map));
    deleteQueue(&(game->active));
    deleteQueue(&(game->toActivate));
    free(game);
}
