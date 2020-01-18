/*************************************************************************
                           Statistiques  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Statistiques> (fichier Statistiques.h) ----------------
#if ! defined ( STATISTIQUES_H )
#define STATISTIQUES_H

//--------------------------------------------------- Interfaces utilisées
#include <iterator>
#include <map>
#include "PageInfo.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Statistiques>
//
//
//------------------------------------------------------------------------

class Statistiques
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterPage(string nomPage);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterLien(string pageSource, string pageCible);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void ConstruireGraphe(string nomGraphe);
    // Mode d'emploi :
    //
    // Contrat :
    //



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Statistiques ( const Statistiques & unStatistiques );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Statistiques ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Statistiques ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    typedef struct
    {
        map <string,int> pagesPointees;
        int nbHit;
    } infoPage;
    map <string,infoPage> EnsemblePages;

};

//-------------------------------- Autres définitions dépendantes de <Statistiques>

#endif // Statistiques_H
