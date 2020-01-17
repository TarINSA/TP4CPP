/*************************************************************************
                           Requete  -  description
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par Killian OECHSLIN, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if ! defined ( REQUETE_H )
#define REQUETE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Requete>
//
//
//------------------------------------------------------------------------

class Requete 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetDate();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetAction();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetPageCible();
    // Mode d'emploi :
    //
    // Contrat :
    //

     string GetPageSource();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Requete & operator = ( const Requete & uneRequete );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Requete ( const Requete & uneRequete );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Requete ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Requete (string ipR, string logname, string user, string d, string actionR, string cible, string prtcl, int codeR, int qDonne, string source,string nav);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~Requete ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string ip;
    string userLogName;
    string authenticatedUser;
    string date;
    string action;
    string pageCible;
    string protocole;
    int codeRetour;
    int quantiteDonnees;
    string pageSource;
    string navigateur;
};

//-------------------------------- Autres définitions dépendantes de <Requete>

#endif // REQUETE_H

