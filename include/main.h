// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 03/09/2020.

#ifndef GAMEOFLIFE_MAIN_H
#define GAMEOFLIFE_MAIN_H

#include <stdint.h> // uint8_t
#include <stdio.h> // printf, size_t

#include "queue.h"
#include "map.h"
#include "game.h"

/**
 * Pattern pour afficher un nombre binaire
 */
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"

/**
 * Fonction pour afficher un nombre binaire.
 * Usage: printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(byte));
 */
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

#endif //GAMEOFLIFE_MAIN_H
