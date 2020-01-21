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
  #include "Requete.h"
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

    bool LireLigneLog(Requete & reqTemp);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Statistiques & GetStatLog();
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool PassageFiltre(Requete & req, bool filtre_e, bool filtre_t, int heure);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool VerifieFichierExclu(string nomPage);
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

    Lecture (string nomFichier);
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
ifstream fichierLog;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Lecture>

#endif // Lecture_H
