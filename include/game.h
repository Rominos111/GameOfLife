// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 03/09/2020.

#ifndef GAMEOFLIFE_GAME_H
#define GAMEOFLIFE_GAME_H

#include <stdint.h> // uint8_t
#include <stdio.h> // printf, size_t
#include <stdlib.h> // malloc, free

#include "map.h"
#include "queue.h"

/**
 * Jeu
 */
typedef struct {
    /**
     * Map
     */
    Map map;

    /**
     * Cellules actives
     */
    Queue active;

    /**
     * Cellules à probablement activer
     */
    Queue toActivate;

    /**
     * Compteur de frames, pour savoir si les cellules ont été updates ou non
     */
    uint8_t frameCount;
} Game;

/**
 * Crée un jeu
 *
 * @param map Map
 *
 * @return Jeu
 */
void createGame(Game** game, Map map);

/**
 * Met à jour le jeu
 *
 * @param game Jeu
 */
void update(Game* game);

/**
 * Supprime un jeu
 *
 * @param game Jeu
 */
void deleteGame(Game* game);

#endif //GAMEOFLIFE_GAME_H
