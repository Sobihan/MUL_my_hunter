/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** main
*/

#include "my_hunter.h"

void eventclose(sfEvent *event, hunter_t *my_struct)
{
    if (event->type == sfEvtClosed || my_struct->life == 0) {
        sfRenderWindow_close(my_struct->window);
        my_struct->life = my_struct->life - 1;
    }
    if (event->mouseButton.type == sfEvtMouseButtonReleased &&
        event->mouseButton.button == sfMouseLeft )
        touch_sprite(event, my_struct);
}
void result(hunter_t *my_struct)
{
    my_putstr("Your score : ");
    my_put_nbr(my_struct->score);
    my_putstr("\n");
    if (my_struct->life != -1)
        my_putstr("You rage Quit\n");
    else
        my_putstr("The Dunk escaped you 3 times\nTry Again!\n");
}

void game(void)
{
    hunter_t my_struct;
    sfEvent event;

    set_my_struct(&my_struct);
    my_struct.window = sfRenderWindow_create(my_struct.video_mode, "my_hunter",
                                             def, NULL);
    while (sfRenderWindow_isOpen(my_struct.window)) {
        sfSprite_setPosition(my_struct.target, my_struct.pos);
        sfRenderWindow_display(my_struct.window);
        display_game(&my_struct);
        sfSprite_setTextureRect(my_struct.target, my_struct.rect);
        my_struct.rect = anim(&my_struct);
        while (sfRenderWindow_pollEvent(my_struct.window, &event)
               || my_struct.life == 0)
            eventclose(&event, &my_struct);
    }
    destroy_all(&my_struct);
    result(&my_struct);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_putstr("Hello Gamer ! \n");
        my_putstr("Rules : You have to kill my duck with your mouse\n");
        my_putstr("/! Warning !\\ \n");
        my_putstr("You have just 3 chances\n");
    } else if (ac == 1)
        game();
    else {
        write(2, "Invalid Option\n", 15);
        return (84);
    }
    return (0);
}
