// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 03/09/2020.

#include "map.h"

Map createMap(size_t rows, size_t cols) {
    return (Map) {
        .rows = rows,
        .cols = cols,
        .array = calloc(rows * cols, sizeof(uint8_t))
    };
}

Map createMapFromArray(size_t rows, size_t cols, uint8_t array[rows][cols]) {
    Map m = createMap(rows, cols);

    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            setMapValue(m, row, col, array[row][col]);
        }
    }

    return m;
}

void deleteMap(Map* map) {
    free(map->array);
}

void setMapValue(Map map, size_t row, size_t col, uint8_t value) {
    map.array[col + row*map.cols] = value;
}

uint8_t getMapValue(Map map, size_t row, size_t col) {
    return map.array[col + row*map.cols];
}

void displayMap(Map map) {
    for (size_t row = 0; row < map.rows; row++) {
        for (size_t col = 0; col < map.cols; col++) {
            if (isActive(map, row, col)) {
                printf("@ ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

bool isActive(Map map, size_t row, size_t col) {
    return getMapValue(map, row, col) & MASK_NEIGHBORS;
}
