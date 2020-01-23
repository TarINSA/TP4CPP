/*************************************************************************
                           Requete  -  Classe stockant les informations liées à une requête lue dans les logs
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par BRANCHEREAU, OECHSLIN
*************************************************************************/

//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if ! defined (REQUETE_H)
#define REQUETE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Requete>
// Cette classe sert uniquement à stocker les informations relatives à une requête
// lue dans le fichier de log, et à renvoyer ces informations.
//
//------------------------------------------------------------------------
class Requete
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string GetPageCible();
    // Mode d'emploi : Renvoie la page cible de la requête
    //
    // Contrat : Aucun
    //

     string GetPageSource();
    // Mode d'emploi : Renvoie la page source de la requête
    //
    // Contrat : Aucun
    //

    void EnleverBaseUrlSource(string baseUrl);
    // Mode d'emploi : Cette méthode détecte si la page source de la requête
    // a pour URL de base celle donnée en paramètre. Si tel est le cas, elle
    // s'occupe de retirer cette base afin de ne pas l'avoir lorsque la page est
    // en local.
    //
    // Contrat : Aucun
    //

    int ExtraireHeure();
    // Mode d'emploi : Cette méthode renvoie l'heure de la requête, en l'extrayant
    // depuis la date complète.
    //
    // Contrat : Aucun
    //

//------------------------------------------------- Surcharge d'opérateurs

    friend ifstream & operator >> (ifstream & in, Requete & r);
    // Mode d'emploi : Cette surcharge permet de lire plus facilement une requête
    // à partir du fichier de log.
    //
    // Contrat : La syntaxe dans le fichier log doit respecter celle des logs Apache
    //

//-------------------------------------------- Constructeurs - destructeur
    Requete ( );
    // Mode d'emploi : Constructeur par défaut, n'a pas d'action particulière
    //
    // Contrat : Aucun
    //

    virtual ~Requete ( );
    // Mode d'emploi : Destructeur, n'a pas d'action particulière
    //
    // Contrat : Aucun
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

inline ifstream & operator >> (ifstream & in, Requete & r)
{
  string ligneReq;

  // dans cette surcharge, on lit et stocke un à un les attributs de la requête

  // IP
  getline(in,ligneReq,' ');
  r.ip=ligneReq;

  // USERLOGNAME
  getline(in,ligneReq,' ');
  r.userLogName=ligneReq;

  // AUTHENTICATEDUSER
  getline(in,ligneReq,' ');
  r.authenticatedUser=ligneReq;

  // DATE
  getline(in,ligneReq,']');
  ligneReq+=']'; // on rajoute le ']' enlevé par le getline
  r.date=ligneReq;

  // ACTION
  in.get(); // enlève l'espace
  in.get(); // enlève le "
  getline(in,ligneReq,' ');
  r.action=ligneReq;

  // PAGECIBLE
  getline(in,ligneReq,' ');
  for(int i=0;i<ligneReq.size();i++)
  {
    // si il y a un '?' dans le nom de la page, on l'enlève ainsi que tout ce qui suit
    // ceci permet d'avoir des noms de page communs pour des sites tel que Google
    if(ligneReq[i]=='?')
    {
      ligneReq.erase(i);
      break;
    }
  }
  r.pageCible=ligneReq;

  // PROTOCOLE
  getline(in,ligneReq,'\"');
  r.protocole=ligneReq;

  // CODERETOUR
  in.get(); // enlève l'espace
  getline(in,ligneReq,' ');
  istringstream(ligneReq)>>r.codeRetour; // convertit le string en int

  // QUANTITEDONNEES
  getline(in,ligneReq,' ');
  if(ligneReq=="-")
  {
    // si la quantité de données n'est pas indiqué ("-") on l'a fixe à 0
    r.quantiteDonnees=0;
  }
  else
  {
    istringstream(ligneReq)>>r.quantiteDonnees;
  }

  // PAGESOURCE
  in.get(); // enlève le "
  getline(in,ligneReq,'\"');
  for(int i=0;i<ligneReq.size();i++)
  {
    // si il y a un '?' dans le nom de la page, on l'enlève ainsi que tout ce qui suit
    // ceci permet d'avoir des noms de page communs pour des sites tel que Google
    if(ligneReq[i]=='?')
    {
      ligneReq.erase(i);
      break;
    }
  }
  r.pageSource=ligneReq;

  // NAVIGATEUR
  in.get(); // enlève l'espace
  getline(in,ligneReq,'\n');
  r.navigateur=ligneReq;

  return in;
}

#endif // REQUETE_H
