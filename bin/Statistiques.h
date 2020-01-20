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

    void AfficherTopDix();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //TEST
    void printMap()
    {
      map<string,infoPage>::iterator it;
    	for(it=EnsemblePages.begin();it!=EnsemblePages.end();++it)
    	{
    		cout<<" test source : "<<it->first<<endl;
        map<string,int>::iterator itCible;
        for(itCible=it->second.pagesPointees.begin();itCible!=it->second.pagesPointees.end();++itCible)
        {
          cout<<"\t test cible : "<<itCible->first<<endl;
        }
    	}
    }



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
