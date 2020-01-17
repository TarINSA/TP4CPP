/*************************************************************************
                           PageInfo  -  description
                             -------------------
                   début                : $14/01/2020$
                   copyright            : (C) OECHSLIN/BRANCHEREAU
                   e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <PageInfo> (fichier PageInfo.h) ----------------
#if ! defined ( PAGEINFO_H )
#define PAGEINFO_H

//--------------------------------------------------- Interfaces utilisées
#include <iterator>
#include <map>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PageInfo>
// PageInfo est un objet associé à une Page internet.
// cette classe permet de stocker les pages pointées par cette Page internet, associé au
// nombre de fois où elles sont pointées, et également le nombre total de fois
// où la Page internet est pointée (nbHit).
//
//------------------------------------------------------------------------

class PageInfo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterPagePointe(string page);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    PageInfo ( const PageInfo & unPageInfo );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PageInfo (int hit=0);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PageInfo ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  map <string,int> pagePointe;
  int nbHit;


};

//-------------------------------- Autres définitions dépendantes de <PageInfo>

#endif // PageInfo_H
