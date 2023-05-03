/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-panoramix-remi.mergen [WSL: Ubuntu]
** File description:
** struc
*/

#pragma once

#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

typedef struct {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
} params_t;

typedef struct {
    size_t size;
    int cooking_pot;
} shared_t;

typedef struct {
    int id;
    pthread_t thread;
    int nb_fights;
    struct village_s *village;
} villager_t;

typedef struct village_s {
    params_t *params;
    shared_t *shared;
    pthread_t druid_thread;
    bool druid_alive;
    villager_t *villagers;
    pthread_mutex_t *mutex;
    sem_t empty_potion;
    sem_t fill_potion;
} village_t;
