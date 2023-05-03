/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-panoramix-remi.mergen [WSL: Ubuntu]
** File description:
** druid
*/

#include "imports.h"
#include "define.h"

static void refill_pot(village_t *v)
{
    v->shared->cooking_pot = v->params->pot_size;
    printf(REFILL_MSG, --v->params->nb_refills);
    return;
}

void *druid(void *v)
{
    village_t *village = (village_t *)v;
    printf(DRUID_INIT_MSG);

    while (village->params->nb_refills > 0) {
        sem_wait(&village->empty_potion);
        refill_pot(village);
        sem_post(&village->fill_potion);
    }
    printf(DRUID_STOP_MSG);
    village->druid_alive = false;
    int *ret = malloc(sizeof(int));
    *ret = 0;
    return ret;
}
