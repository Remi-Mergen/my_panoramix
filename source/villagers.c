/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-panoramix-remi.mergen [WSL: Ubuntu]
** File description:
** villagers
*/

#include "imports.h"
#include "define.h"

static void drink(villager_t *v)
{
    printf(TRIES_DRINK_MSG, v->id, v->village->shared->cooking_pot);
    if (v->village->shared->cooking_pot <= 0) {
        printf(ASK_REFILL_MSG, v->id);
        sem_post(&v->village->empty_potion);
        sem_wait(&v->village->fill_potion);
    }
    --v->village->shared->cooking_pot;
    return;
}

void *villager(void *villager)
{
    villager_t *v = (villager_t *)villager;

    printf(VILLAGER_INIT_MSG, v->id);
    for (;v->nb_fights;) {
        pthread_mutex_lock(v->village->mutex);
        if (!v->village->druid_alive && v->village->shared->cooking_pot <= 0) {
            pthread_mutex_unlock(v->village->mutex);
            break;
        }
        drink(v);
        pthread_mutex_unlock(v->village->mutex);
        printf(FIGHT_MSG, v->id, --v->nb_fights);
    }
    printf(VILLAGER_STOP_MSG, v->id);
    int *ret = malloc(sizeof(int));
    *ret = 0;
    return ret;
}
