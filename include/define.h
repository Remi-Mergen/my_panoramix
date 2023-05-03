/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-panoramix-remi.mergen [WSL: Ubuntu]
** File description:
** define
*/

#pragma once
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "struct.h"

// MACRO

#define P(x) write(1, x, strlen(x))


// PROTOTYPE

/*
 * @brief Core of the program
 * @param v the village
*/
int core(village_t *v);

/*
 * @brief Handle druid actions
 * @param v the village
*/
void *druid(void *v);

/*
 * @brief Handle villager actions
 * @param v the village
*/
void *villager(void *villager);

int is_nbr(char *str);

#define HELP_MESSAGE "\
USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n\
\t nb_villagers:\t indicates the number of villagers (must be >0)\n\
\t pot_size:\t indicates the maximum number that can be contained \
in the cooking pot (must be >0)\n\
\t nb_fights:\t indicates the maximum number of fights a villager \
will engage in (must be >0)\n\
\t nb_refills:\t incicates the maximum number of time the druid will \
refill the pot (must be >0)\n"

// DRUID

#define DRUID_INIT_MSG ("Druid: I'm ready... but sleepy...\n")
#define REFILL_MSG ("Druid: Ah! Yes, yes, I'm awake! Working on it! \
Beware I can only make %d more refills after this one.\n")
#define DRUID_STOP_MSG ("Druid: I'm out of viscum. I'm going back to... zZz\n")

// VILLAGER

#define VILLAGER_INIT_MSG ("Villager %d: Going into battle!\n")
#define TRIES_DRINK_MSG ("Villager %i: I need a drink... \
I see %i servings left.\n")
#define ASK_REFILL_MSG ("Villager %d: Hey Pano wake up! \
We need more potion.\n")
#define FIGHT_MSG ("Villager %d: Take that roman scum! Only %d left.\n")
#define VILLAGER_STOP_MSG ("Villager %d: I'm going to sleep now.\n")
