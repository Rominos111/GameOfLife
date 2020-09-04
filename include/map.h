// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 03/09/2020.

#ifndef GAMEOFLIFE_MAP_H
#define GAMEOFLIFE_MAP_H

#include <stdlib.h> // malloc, free
#include <stdint.h> // uint8_t
#include <stdio.h> // printf
#include <stdbool.h> // bool

/**
 * Masque pour cellule active au tour précédent
 */
#define MASK_ACTIVE_PREVIOUSLY 0x80 // 0b10000000

/**
 * Masque pour cellule active maintenant
 */
#define MASK_ACTIVE_NOW 0x40        // 0b01000000

/**
 * Masque pour savoir à quand remonte la dernière update
 */
#define MASK_LAST_TURN 0x20         // 0b00100000

/**
 * Masque pour le nombre de voisins
 */
#define MASK_NEIGHBORS 0x0f         // 0b00001111

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
 * Récupère l'adresse d'une case d'une map
 *
 * @param map Map
 * @param row Ligne
 * @param col Colonne
 *
 * @return Adresse
 */
uint8_t* getMapAddress(Map map, size_t row, size_t col);

/**
 * Affiche une map
 *
 * @param map Map
 */
void displayMap(Map map);

/**
 * Position valide ou non
 *
 * @param map Map
 * @param row Ligne
 * @param col Colonne
 *
 * @return Valide ou non
 */
bool isValidPos(Map map, long row, long col);

/**
 * Cellule active ou non
 *
 * @param map Map
 * @param row Ligne
 * @param col Colonne
 *
 * @return Active ou non
 *
 * @see MASK_ACTIVE_NOW
 */
bool isActive(Map map, size_t row, size_t col);

/**
 * Adresse d'un voisin selon un pointeur
 *
 * @param map Map
 * @param value Pointeur
 * @param rowOffset Offset row
 * @param colOffset Offset col
 *
 * @return Pointeur du voisin si position valide, NULL sinon
 */
uint8_t* getNeighborAddress(Map map, const uint8_t* value, int8_t rowOffset, int8_t colOffset);

#endif //GAMEOFLIFE_MAP_H
