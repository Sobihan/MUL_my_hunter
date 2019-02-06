/*
** EPITECH PROJECT, 2018
** set_struc.c
** File description:
** set
*/

#include "my_hunter.h"

void *set_sprite(char const *pathfile)
{
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();
    texture = sfTexture_createFromFile(pathfile, NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

void set_my_struct(hunter_t *my_struct)
{
    my_struct->video_mode.width = 1920;
    my_struct->video_mode.height = 1080;
    my_struct->video_mode.bitsPerPixel = 32;
    my_struct->background = set_sprite("outil/hunter2.jpg");
    my_struct->target = set_sprite("outil/sprite2.PNG");
    my_struct->rect.top = 0;
    my_struct->rect.left= 0;
    my_struct->rect.width = 110;
    my_struct->rect.height = 110;
    my_struct->pos.x = -200.0;
    my_struct->pos.y = (float)(rand() % 700);
    my_struct->clock = sfClock_create();
    my_struct->speed = 1.0;
    my_struct->life = 3;
    my_struct->score = 0;
}
