/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-panoramix-remi.mergen [WSL: Ubuntu]
** File description:
** core
*/

#include "define.h"
#include "imports.h"

static int init_villagers(village_t *v)
{
    int check_val = 0;

    for (int i = 0; i < v->params->nb_villagers; i++) {
        v->villagers[i].id = i;
        v->villagers[i].nb_fights = v->params->nb_fights;
        v->villagers[i].village = v;
        check_val = pthread_create(&v->villagers[i].thread,
                                    NULL, villager, &v->villagers[i]);
        if (check_val != 0)
            return -1;
    }
    return 0;
}

static int wait_villagers(village_t *v)
{
    int rt_val;

    for (int i = 0; i < v->params->nb_villagers; i++)
        rt_val = pthread_join(v->villagers[i].thread, NULL);
    if (rt_val != 0)
        return -1;
    return 0;
}

static int init_druid(village_t *v)
{
    v->druid_alive = true;
    if (pthread_create(&v->druid_thread, NULL, druid, (void *)v) != 0)
        return -1;
    return 0;
}

static int wait_druid(village_t *v)
{
    pthread_join(v->druid_thread, NULL);
    return 0;
}

int core(village_t *v)
{
    if (init_druid(v) == -1 || init_villagers(v) == -1)
        return -1;
    if (wait_druid(v) == -1 || wait_villagers(v) == -1)
        return -1;
    return 0;
}
