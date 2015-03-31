/* 
 * File:   loading_struct.h
 * Author: jukenigon
 *
 * Created on 21 octobre 2014, 11:51
 */
#include "game_struct.h"

#ifndef LOADING_STRUCT_H
#define	LOADING_STRUCT_H



typedef struct Loading
{
    void (*previous)(Game *);
}Loading;

#endif	/* LOADING_STRUCT_H */

