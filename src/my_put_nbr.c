/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** THE put_nbr
*/

#include <unistd.h>
void my_putchar(char c)
{
    write(1, &c, 1);
}
int random1(int nb)
{
    my_putchar('-');
    nb = nb * -1;
    return (nb);
}

int my_put_nbr(int nb)
{
    int n = 1;

    if(nb < 0)
    {
        nb = random1(nb);
    }
    while (nb / n >= 10)
    {
        n = n * 10;
    }
    while (n  >= 1)
    {
        my_putchar((nb / n) % 10 + 48);
        n = n /10;
            }
    return (0);
}
