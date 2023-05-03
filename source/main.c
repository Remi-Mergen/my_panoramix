/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-panoramix-remi.mergen [WSL: Ubuntu]
** File description:
** main
*/

#include "define.h"
#include "struct.h"

static void init_struct(village_t *v)
{
    v->params = malloc(sizeof(params_t));
    v->shared = malloc(sizeof(shared_t));
    v->params->nb_villagers = 0;
    v->params->pot_size = 0;
    v->params->nb_fights = 0;
    v->params->nb_refills = 0;
    v->druid_alive = false;
    v->mutex = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init((v->mutex), NULL);
    sem_init(&(v->empty_potion), 0, 0);
    sem_init(&(v->fill_potion), 0, 0);
    return;
}

static void fill_struct(village_t *v, char **av)
{
    v->params->nb_villagers = atoi(av[1]);
    v->params->pot_size = atoi(av[2]);
    v->params->nb_fights = atoi(av[3]);
    v->params->nb_refills = atoi(av[4]);
    v->shared->cooking_pot = v->params->pot_size;
    v->villagers = malloc(sizeof(villager_t) * v->params->nb_villagers);
    return;
}

static void free_struct(village_t *v)
{
    free(v->params);
    free(v->shared);
    free(v);
    return;
}

static int error_handling(char **av)
{
    for (int i = 1; i < 5; ++i)
        if (is_nbr(av[i]))
            return 1;
    if (atoi(av[1]) <= 0 || atoi(av[2]) <= 0 ||
                                        atoi(av[3]) <= 0 || atoi(av[4]) <= 0) {
        write(2, "USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> \
<nb_refills>\n", 70);
        write(2, "Values must be >0.\n", 19);
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    int return_val = 0;
    if ((ac == 2 && (strcmp(av[1], "-h") == 0 || strcmp(av[1], "--help") == 0))
    || ac != 5) {
        write(2, HELP_MESSAGE, strlen(HELP_MESSAGE));
        return 84;
    }
    if (error_handling(av))
        return 84;
    village_t *v = malloc(sizeof(village_t));
    init_struct(v);
    fill_struct(v, av);
    return_val = core(v);
    free_struct(v);
    if (return_val == -1)
        return 84;
    else
        return 0;
}
