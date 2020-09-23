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
            if (array[row][col]) {
                setMapValue(m, row, col, MASK_ACTIVE_NOW);
            }
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

uint8_t* getMapAddress(Map map, size_t row, size_t col) {
    return &(map.array[col + row*map.cols]);
}

void displayMap(Map map) {
    for (size_t row = 0; row < map.rows; row++) {
        for (size_t col = 0; col < map.cols; col++) {
            if (isActive(getMapValue(map, row, col))) {
                printf("@ ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool isValidPos(Map map, long row, long col) {
    return row >= 0 && row < (long) map.rows && col >= 0 && col < (long) map.cols;
}

bool isActive(uint8_t cell) {
    return cell & (uint8_t) MASK_ACTIVE_NOW;
}

uint8_t* getNeighborAddress(Map map, const uint8_t* value, int8_t rowOffset, int8_t colOffset) {
    const size_t pos = value - &(map.array[0]);
    const size_t row = pos / map.cols;
    const size_t col = pos % map.cols;

    if (isValidPos(map, (long) row + rowOffset, (long) col + colOffset)) {
        return getMapAddress(map, row + rowOffset, col + colOffset);
    }
    else {
        return NULL;
    }
}

uint8_t getNbNeighbors(uint8_t cell) {
    return cell & (uint8_t) MASK_NEIGHBORS;
}

void setNbNeighbors(uint8_t* cell, uint8_t nb) {
    *cell = (*cell) & (uint8_t) (~ (uint8_t) MASK_NEIGHBORS);
    *cell = (*cell) | (uint8_t) ((uint8_t) MASK_NEIGHBORS & nb);
}

void setCellParity(uint8_t* cell, uint8_t parity) {
    if (parity == 0) {
        *cell = *cell & (uint8_t) (~ (uint8_t) MASK_PARITY);
    }
    else {
        *cell = *cell | (uint8_t) MASK_PARITY;
    }
}
