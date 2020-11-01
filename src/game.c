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
            if (isActive(getMapValue(map, row, col))) {
                enqueue(getMapAddress(map, row, col), (*g)->active);
            }
        }
    }
}

void update(Game* game) {
    while (!isEmpty(*game->active)) {
        uint8_t* cell = dequeue(game->active);

        setActive(cell, false);
        setActivePreviously(cell, true);
        setCellParity(cell, game->frameCount);

        for (int i=-1; i<=1; i++) {
            for (int j=-1; j<=1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                uint8_t* neighbor = getNeighborAddress(game->map, cell, i, j);

                if (neighbor == NULL) {
                    continue;
                }

                uint8_t nbCell;

                if (checkCellParity(*neighbor, game->frameCount)) {
                    nbCell = getNbNeighbors(*neighbor) + 1;
                }
                else {
                    nbCell = 1;

                    setActivePreviously(neighbor, isActive(*neighbor));
                    setCellParity(neighbor, game->frameCount);
                }

                setNbNeighbors(neighbor, nbCell);

                if (nbCell == 2) {
                    enqueue(neighbor, game->toActivate);
                }

                // Applique le masque pour framecount
                // Ajoute 1 voisin
                // Si voisin >= 2 on ajoute aux candidats potentiels
            }
        }
    }

    // Bien penser à update cellules actives

    while (!isEmpty(*game->toActivate)) {
        uint8_t* candidate = dequeue(game->toActivate);
        uint8_t neighbors = getNbNeighbors(*candidate);

        /*
        const size_t pos = candidate - &(game->map.array[0]);
        const size_t row = pos / game->map.cols;
        const size_t col = pos % game->map.cols;

        printf("%d %d\n", row, col);
         */

        if (neighbors == 3 || (neighbors == 2 && wasActive(*candidate))) {
            setActive(candidate, true);
            enqueue(candidate, game->active);
        }
    }

    game->frameCount++;
}

void deleteGame(Game* game) {
    deleteQueue(game->active);
    deleteQueue(game->toActivate);
    deleteMap(&(game->map));
    free(game);
}
