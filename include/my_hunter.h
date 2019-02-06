/*
** EPITECH PROJECT, 2018
** my_hunter.h
** File description:
** structure
*/

#ifndef HUNTER_H
#define HUNTER_H

#include  <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <stdlib.h>
#include <unistd.h>

int my_put_nbr(int nb);

#define def sfDefaultStyle

typedef struct hunter_s
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfSprite *background;
    sfSprite *target;
    sfSprite *coeur;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
    sfTime time;
    float seconde;
    float speed;
    int life;
    int score;
} hunter_t;

int touch_sprite(sfEvent *event, hunter_t *my_struct);
sfIntRect anim(hunter_t *my_struct);
void destroy_all(hunter_t *my_struct);
void display_game(hunter_t *my_struct);
void set_my_struct(hunter_t *my_struct);
void *set_sprite(char const *pathfile);
void my_putstr(char *str);

#endif
