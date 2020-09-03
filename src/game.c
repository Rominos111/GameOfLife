// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 03/09/2020.

#include "game.h"

Game createGame(Map map) {
    return (Game) {
        .active = createQueue(),
        .toActivate = createQueue(),
        .map = map
    };
}

void deleteGame(Game* game) {
    deleteMap(&(game->map));
    deleteQueue(&(game->active));
    deleteQueue(&(game->toActivate));
}
