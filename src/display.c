/*
** EPITECH PROJECT, 2018
** my_hunter.c
** File description:
** game
*/

#include "my_hunter.h"

void display_game(hunter_t *my_struct)
{
    my_struct->pos.x = my_struct->pos.x + my_struct->speed;
    if (my_struct->pos.x > 1920) {
        my_struct->pos.x = -300;
        my_struct->pos.y =  rand() % 800;
        my_struct->life = my_struct->life - 1;
    }
    sfRenderWindow_drawSprite(my_struct->window, my_struct->background, NULL);
    sfRenderWindow_drawSprite(my_struct->window, my_struct->target, NULL);
}

void destroy_all(hunter_t *my_struct)
{
    sfSprite_destroy(my_struct->background);
    sfSprite_destroy(my_struct->target);
    sfClock_destroy(my_struct->clock);
    sfRenderWindow_destroy(my_struct->window);
}

sfIntRect anim(hunter_t *my_struct)
{
    my_struct-> time = sfClock_getElapsedTime(my_struct->clock);
    if (my_struct->time.microseconds < 150000)
        my_struct->rect.left = 0;
    if (my_struct->time.microseconds > 150000 &&
        my_struct->time.microseconds < 300000)
        my_struct->rect.left = 110;
    if (my_struct-> time.microseconds > 300000 &&
        my_struct-> time.microseconds < 450000)
        my_struct->rect.left = 220;
    if (my_struct->time.microseconds > 500000)
        sfClock_restart(my_struct->clock);
    return (my_struct->rect);
}

int touch_sprite(sfEvent *event, hunter_t *my_struct)
{
    if (event->mouseButton.x >= my_struct->pos.x &&
        event->mouseButton.x <= my_struct->pos.x + 110) {
        if (event->mouseButton.y >= my_struct->pos.y &&
            event->mouseButton.y <= my_struct->pos.y +110) {
            my_struct->pos.x = -300;
            my_struct->pos.y = rand() % 800;
            my_struct->speed = my_struct->speed + 0.1;
            my_struct->score = my_struct->score + 1;
        }
    }
    return (0);
}
