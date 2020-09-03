// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 03/09/2020.

#include "main.h"

int main() {
    uint8_t grid[5][3] = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 0, 0}
    };

    Game g = createGame(createMapFromArray(5, 3, grid));
    displayMap(g.map);
    deleteGame(&g);

    return EXIT_SUCCESS;
}
