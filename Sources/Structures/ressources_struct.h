#ifndef RESSOURCES_STRUCT_H
#define	RESSOURCES_STRUCT_H

#include "batiment_struct.h"
#include "defense_struct.h"
#include "chantier_struct.h"
#include "caserne_struct.h"

typedef struct
{
    Batiment senat;
    Batiment mine;
    Batiment chantier;
    Batiment caserne;
    Defense canon;
    Defense tourelle;
    Defense drone;
    Defense puit;
    Chantier chasseur;
    Chantier chasseur2;
    Chantier transport;
    Chantier croiseur;
    Chantier destroyer;
    Chantier etoile;
    Caserne droides;
    Caserne clones;
    Caserne commando;
    Caserne jedi;
}Ressources;

#endif	/* RESSOURCES_STRUCT_H */

