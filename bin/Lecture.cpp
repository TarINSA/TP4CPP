 /*************************************************************************
                           Lecture  -  Classe de lecture du fichier log
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par BRANCHEREAU, OECHSLIN
*************************************************************************/

//---------- Réalisation de la classe <Lecture> (fichier Lecture.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
//------------------------------------------------------ Include personnel
#include "Lecture.h"
#include "Requete.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Lecture::TestOuvertureFichier(string nomFichier)
// Algorithme : Aucun
//
{
  fstream fichier(nomFichier,ios::in);
  if(fichier.fail())
  {
    fichier.close();
    return false;
  }
  else
  {
    fichier.close();
    return true;
  }
} //----- Fin de TestOuvertureFichier

bool Lecture::LireLigneLog(Requete & reqTemp)
// Algorithme : Cette méthode utilise la surcharge de l'opérateur >> afin de
// remplir les informations de la requête passée en paramètre
//
{
  fichierLog>>reqTemp;
  // on indique si on a atteint la fin du fichier
  if(fichierLog.eof())
  {
    return false;
  }

  return true;
} //----- Fin de LireLigneLog

bool Lecture::PassageFiltre(Requete & req, bool filtre_e, bool filtre_t, int heure)
// Algorithme : Aucun
//
{
  bool filtre_t_ok=false;
  bool filtre_e_ok=false;
  if(filtre_e)
  {
    if(VerifieFichierExclu(req.GetPageCible()))
    {
      filtre_e_ok=false;
    }
    else
    {
      filtre_e_ok=true;
    }
  }
  else
  {
    filtre_e_ok=true;
  }

  if(filtre_t)
  {
    if(req.ExtraireHeure()>=heure && req.ExtraireHeure()<heure+1)
    {
      filtre_t_ok=true;
    }
    else
    {
      filtre_t_ok=false;
    }
  }
  else
  {
    filtre_t_ok=true;
  }

  if(filtre_t_ok && filtre_e_ok)
  {
    return true;
  }
  else
  {
    return false;
  }
} //----- Fin de PassageFiltre

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Lecture::Lecture (string nomFichier)
// Algorithme : Aucun
//
:fichierLog(nomFichier)
{
  #ifdef MAP
      cout << "Appel au constructeur de <Lecture>" << endl;
  #endif
} //----- Fin de Lecture

Lecture::~Lecture ( )
// Algorithme : Aucun
//
{
  fichierLog.close();
#ifdef MAP
    cout << "Appel au destructeur de <Lecture>" << endl;
#endif
} //----- Fin de ~Lecture


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool Lecture::VerifieFichierExclu(string nomPage)
// Algorithme : Cette méthode compare la fin du nom de la page avec les extensions
// qui doivent être filtrées. Au préalable elle passe nomPage en minuscule pour
// éviter d'avoir des problèmes liés à la casse
//
{
  // on convertit nomPage en minuscule
  transform(nomPage.begin(), nomPage.end(), nomPage.begin(),::tolower);

  if(nomPage.length()>3 && nomPage.substr(nomPage.length()-3,3)==".js")
  {
    return true;
  }
  if(nomPage.length()>4 && nomPage.substr(nomPage.length()-4,4)==".jpg")
  {
    return true;
  }
  if(nomPage.length()>4 && nomPage.substr(nomPage.length()-4,4)==".ico")
  {
    return true;
  }
  if(nomPage.length()>4 && nomPage.substr(nomPage.length()-4,4)==".gif")
  {
    return true;
  }
  if(nomPage.length()>4 && nomPage.substr(nomPage.length()-4,4)==".png")
  {
    return true;
  }
  if(nomPage.length()>4 && nomPage.substr(nomPage.length()-4,4)==".bmp")
  {
    return true;
  }
  if(nomPage.length()>4 && nomPage.substr(nomPage.length()-4,4)==".css")
  {
    return true;
  }
  return false;
} //----- Fin de VerifieFichierExclu
