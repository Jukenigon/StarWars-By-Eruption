#ifndef PLAYER_STRUCT_H
#define	PLAYER_STRUCT_H

#include "batiment_struct.h"

typedef struct
{
    int credits;
    int id;
    int attaque;
    int lvl_senat;
    int lvl_mine;
    int lvl_chantier;
    int lvl_caserne;
    int lvl_canon;
    int lvl_tourelle;
    int lvl_drone;
    int lvl_puit;
    int lvl_chasseur;
    int lvl_chasseur2;
    int lvl_transport;
    int lvl_croiseur;
    int lvl_destroyer;
    int lvl_etoile;
    int lvl_droides;
    int lvl_clones;
    int lvl_commando;
    int lvl_jedi;
    
    int planete;
}Player;

#endif	/* PLAYER_STRUCT_H */

