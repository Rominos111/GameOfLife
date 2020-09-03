// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 03/09/2020.

#ifndef GAMEOFLIFE_MAP_H
#define GAMEOFLIFE_MAP_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * Masque pour le nombre de voisins
 */
#define MASK_NEIGHBORS 0xf // 0b00001111

/**
 * Map
 */
typedef struct {
    /**
     * Nombre de lignes
     */
    size_t rows;

    /**
     * Nombre de colonnes
     */
    size_t cols;

    /**
     * Liste de cellules
     */
    uint8_t* array;
} Map;

/**
 * Crée une map
 *
 * @param rows Nombre de lignes
 * @param cols Nombre de colonnes
 *
 * @return Map créée
 */
Map createMap(size_t rows, size_t cols);

/**
 * Crée une map depuis un tableau
 *
 * @param rows Nombre de lignes
 * @param cols Nombre de colonnes
 * @param array Tableau d'origine
 *
 * @return Map créée
 */
Map createMapFromArray(size_t rows, size_t cols, uint8_t array[rows][cols]);

/**
 * Supprime une map
 *
 * @param map Map
 */
void deleteMap(Map* map);

/**
 * Set la valeur d'une case d'une map
 *
 * @param map Map
 * @param row Ligne
 * @param col Colonne
 * @param value Valeur à set
 */
void setMapValue(Map map, size_t row, size_t col, uint8_t value);

/**
 * Récupère la valeur d'une case d'une map
 *
 * @param map Map
 * @param row Ligne
 * @param col Colonne
 *
 * @return Valeur
 */
uint8_t getMapValue(Map map, size_t row, size_t col);

/**
 * Affiche une map
 *
 * @param map Map
 */
void displayMap(Map map);

/**
 * Cellule active ou non
 *
 * @param map Map
 * @param row Ligne
 * @param col Colonne
 *
 * @return Active ou non
 *
 * @see MASK_NEIGHBORS
 */
bool isActive(Map map, size_t row, size_t col);

#endif //GAMEOFLIFE_MAP_H
