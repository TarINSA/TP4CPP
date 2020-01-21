/*************************************************************************
                           Requete  -  Classe stockant les informations liées à une requête lue dans les logs
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par OECHSLIN, BRANCHEREAU
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

    void EnleverBaseUrlSource(string baseUrl);
    // Mode d'emploi :
    //
    // Contrat :
    //

    int ExtraireHeure();
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

    friend ifstream & operator >> (ifstream & in, Requete & r);
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

inline ifstream & operator >> (ifstream & in, Requete & r)
{
  string ligneReq;

  getline(in,ligneReq,' '); // on récupère toute la ligne puis on extrait chaque élément par la suite
  r.ip=ligneReq;

  getline(in,ligneReq,' ');
  r.userLogName=ligneReq;

  getline(in,ligneReq,' ');
  r.authenticatedUser=ligneReq;

  getline(in,ligneReq,']');
  ligneReq+=']';
  r.date=ligneReq;

  in.get(); // enlève l'espace
  in.get(); // enlève le "
  getline(in,ligneReq,' ');
  r.action=ligneReq;

  getline(in,ligneReq,' ');
  for(int i=0;i<ligneReq.size();i++)
  {
    if(ligneReq[i]=='?')
    {
      ligneReq.erase(i);
      break;
    }
  }
  r.pageCible=ligneReq;

  getline(in,ligneReq,'\"');
  r.protocole=ligneReq;

  in.get(); // enlève l'espace
  getline(in,ligneReq,' ');
  istringstream(ligneReq)>>r.codeRetour; // convertit le string en int

  getline(in,ligneReq,' ');
  if(ligneReq=="-")
  {
    r.quantiteDonnees=0;
  }
  else
  {
    istringstream(ligneReq)>>r.quantiteDonnees;
  }

  in.get(); // enlève le "
  //on récupère la page source en entière (avec la base qu'on enlèvera plus tard si nécessaire)
  getline(in,ligneReq,'\"');

  // gestion des recherches: on supprime ce qui apparait après les ?
  for(int i=0;i<ligneReq.size();i++)
  {
    if(ligneReq[i]=='?')
    {
      ligneReq.erase(i);
      break;
    }
  }
  r.pageSource=ligneReq;

  in.get(); // enlève l'espace
  getline(in,ligneReq,'\n');
  r.navigateur=ligneReq;

  return in;
}

#endif // REQUETE_H
