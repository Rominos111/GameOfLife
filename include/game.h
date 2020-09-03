// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 03/09/2020.

#ifndef GAMEOFLIFE_GAME_H
#define GAMEOFLIFE_GAME_H

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
} Game;

/**
 * Crée un jeu
 *
 * @param map Map
 *
 * @return Jeu
 */
Game createGame(Map map);

/**
 * Supprime un jeu
 *
 * @param game Jeu
 */
void deleteGame(Game* game);

#endif //GAMEOFLIFE_GAME_H
