/* 
 * File:   button.h
 * Author: jukenigon
 *
 * Created on 22 octobre 2014, 15:55
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include "../Structures/game_struct.h"
#include "../Structures/button_struct.h"

Button init_button(int x, int y, int w, int h, char *text);
void hover(Game *game, Button *button);
void print_button(Game *game, Button *button);

#endif	/* BUTTON_H */

