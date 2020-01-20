/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Lecture> (fichier Lecture.h) ----------------
#if ! defined ( LECTURE_H )
#define LECTURE_H

//--------------------------------------------------- Interfaces utilisées
  #include <fstream>
  #include "Statistiques.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Lecture>
//
//
//------------------------------------------------------------------------

class Lecture
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool TestExistanceFichier(string fichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AnalyseLog();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Statistiques & GetStatLog();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
    Lecture ( const Lecture & unLecture );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Lecture (bool e, bool t, int h, string nomFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Lecture ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
bool filtre_e;
bool filtre_t;
int heure;
ifstream fichierLog;
Statistiques statLog;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Lecture>

#endif // Lecture_H
