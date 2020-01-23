/*************************************************************************
                           Lecture  -  Classe de lecture du fichier log
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par BRANCHEREAU, OECHSLIN
*************************************************************************/

//---------- Interface de la classe <Lecture> (fichier Lecture.h) ----------------
#if ! defined ( LECTURE_H )
#define LECTURE_H
//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include "Requete.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Lecture>
// La classe Lecture a pour rôle de gérer l'ouverture du fichier de log, de le
// lire et extraire les requêtes qu'il contient. Elle permet également de filtrer
// ces requêtes en fonction des options que l'utilisateur a spécifié
//
//------------------------------------------------------------------------
class Lecture
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    static bool TestOuvertureFichier(string fichier);
    // Mode d'emploi : Cette méthode vérifie que le fichier dont le nom est passé
    // en paramètre existe bien et que l'utilisateur dispose des droits en lecture
    // dessus.
    //
    // Contrat : Aucun
    //

    bool LireLigneLog(Requete & reqTemp);
    // Mode d'emploi : Cette méthode lit une ligne depuis le fichier log et stocke
    // les informations de cette ligne dans la requête passée en paramètre.
    // Elle renvoie ensuite un booléen indiquant si la fin du fichier a été atteinte
    // ou non.
    //
    // Contrat : Lorsque la méthode est appelée, il ne faut pas avoir atteint la fin
    // du fichier de log.
    //

    bool PassageFiltre(Requete & req, bool filtre_e, bool filtre_t, int heure);
    // Mode d'emploi : Cette méthode fait passer la requête donnée en paramètre à
    // travers les filtres actifs (symbolisés par les booléens) et renvoie true
    // seulement si la requête a passé avec succès les filtres.
    //
    // Contrat : La requête fournie en paramètre doit avoir toutes ses informations
    // de remplies.
    // L'heure doit être un entier compris entre 0 et 23 (inclus)
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Lecture (string nomFichier);
    // Mode d'emploi : Ce constructeur initialise l'objet en ouvrant (en lecture)
    // le fichier dont le nom est passé en paramètre.
    //
    // Contrat : Le fichier spécifié doit existé et l'utilisateur doit disposer
    // des droits en lecture dessus.
    //

    virtual ~Lecture ( );
    // Mode d'emploi : Ce destructeur s'occupe de fermer le fichier de log ouvert
    // par le constructeur
    //
    // Contrat : Aucun
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    bool VerifieFichierExclu(string nomPage);
    // Mode d'emploi : Cette méthode vérifie si la page passée en paramètre possède
    // une des extensions qui doivent être filtrées (fichier image, css ou javascript)
    //
    // Contrat : Aucun
    //

//----------------------------------------------------- Attributs protégés
    ifstream fichierLog;
};

//-------------------------------- Autres définitions dépendantes de <Lecture>

#endif // LECTURE_H
