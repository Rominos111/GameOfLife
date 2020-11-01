// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 03/09/2020.

#include "main.h"

int main() {
    uint8_t grid[5][5] = {
            {0, 0, 0, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
    };

    Game* g;
    createGame(&g, createMapFromArray(5, 5, grid));

    displayMap(g->map);
    update(g);
    displayMap(g->map);
    update(g);
    displayMap(g->map);
    update(g);
    displayMap(g->map);

    deleteGame(g);

    return EXIT_SUCCESS;
}
