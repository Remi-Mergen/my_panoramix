/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-panoramix-remi.mergen [WSL: Ubuntu]
** File description:
** is_nbr
*/

/*
 * @brief Check if it's a nbr in the string
 * @param str String to check
 * @return 0 if it's a number, 1 if not,
 * @return -1 if str is null
*/
int is_nbr(char *str)
{
    if (str == (void *)0)
        return -1;
    if (str[0] == '-')
        str++;
    for (int i = 0; str[i]; ++i)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return 1;
    return 0;
}
