/*************************************************************************
                           Statistiques  -  Classe gérant les statistiques d'un fichier log
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par BRANCHEREAU, OECHSLIN
*************************************************************************/

//---------- Interface de la classe <Statistiques> (fichier Statistiques.h) ----------------
#if ! defined ( STATISTIQUES_H )
#define STATISTIQUES_H

//--------------------------------------------------- Interfaces utilisées
#include <iterator>
#include <map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Statistiques>
// Cette classe a pour objectif de comptabiliser tous les liens qu'il existe entre
// les pages, ainsi que le nombre de fois que chaque page a été visitée afin par
// la suite d'afficher les statistiques désirées par l'utilisateur
//
//------------------------------------------------------------------------

class Statistiques
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterLien(string pageSource, string pageCible);
    // Mode d'emploi : Cette méthode permet d'ajouter dans l'ensemble des pages
    // un lien entre les pages "pageSource" et "pageCible"
    //
    // Contrat : Aucun
    //

    bool ConstruireGraphe(string nomGraphe);
    // Mode d'emploi : Cette méthode s'occupe de construire, à partir du nom de
    // fichier passé en paramètre, un fichier .dot permettant de créer un graphe
    // représentant les liens existant entre toutes les pages présentes dans les logs.
    //
    // Contrat : L'utilisateur doit disposer des droits en écriture sur le fichier
    // "nomGraphe", sans quoi une erreur lui sera affichée.
    //

    void AfficherTopDix();
    // Mode d'emploi : Cette méthode affiche le classement des 10 pages les plus
    // populaires (ayant le plus de hits) par ordre décroissant.
    //
    // Contrat : Aucun
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Statistiques ( );
    // Mode d'emploi : Constructeur par défaut, n'a pas d'action particulière.
    //
    // Contrat : Aucun
    //

    virtual ~Statistiques ( );
    // Mode d'emploi : destructeur, n'a pas d'action particulière
    //
    // Contrat : Aucun
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    void AjouterPage(string nomPage);
    // Mode d'emploi : Cette méthode s'occupe d'ajouter à l'ensemble des pages
    // la page dont le nom est donné en paramètre.
    //
    // Contrat : Aucun
    //

//----------------------------------------------------- Attributs protégés

    // structure stockant, pour une page donnée, son nombre de hits ainsi que l'ensemble des pages vers lesquelles elle pointe (avec à chaque fois le nombre de fois qu'elle les pointe)
    typedef struct
    {
        map <string,int> pagesPointees;
        int nbHit;
    } infoPage;

    map <string,infoPage> EnsemblePages;

};

//-------------------------------- Autres définitions dépendantes de <Statistiques>

#endif // STATISTIQUES_H
