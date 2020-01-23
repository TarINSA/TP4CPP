/*************************************************************************
                   Main  -  Classe principale de gestion de l'application
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par BRANCHEREAU, OECHSLIN
*************************************************************************/

//---------- Réalisation de la classe <Main> (fichier Main.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Lecture.h"
#include "Statistiques.h"
#include "Requete.h"
//----------------------------------------------------------------- PUBLIC
bool filtre_e=false;
bool filtre_g=false;
bool filtre_t=false;
int temps;
string nomFichier;
string nomGraphe;
string baseUrl;
// -----------------------------------------------Déclaration de Fonctions
int ChoixOption(int argc,char ** argv);
inline void ErreurSyntaxe();
inline void ErreurFichier();
inline void ErreurTemps();
inline void ErreurGraphe();
//---------------------------------------------------- Fonctions publiques
int main(int argc, char **argv)
{
  if(ChoixOption(argc,argv)==0)
  {
      // lecture du fichier config pour obtenir la base de l'url (adresse local) :
      // on récupère d'abord le chemin d'accès du fichier config
      string cheminConfig=string(argv[0]);
      cheminConfig.erase(cheminConfig.find("analog"));
      cheminConfig+="config.txt";
      ifstream fichierConfig(cheminConfig);
      if(!fichierConfig.is_open())
      {
        cerr<<"Erreur lors de l'ouverture du fichier config.txt. Vérifiez que ce fichier existe et que vous disposez des droits d'accès nécessaires"<<endl;
        fichierConfig.close();
        return -1;
      }
      else
      {
        fichierConfig>>baseUrl;
        fichierConfig.close();
      }

      // création des objets nécessaires pour la lecture et l'analyse des logs
      Requete requeteTemporaire;
      Statistiques statLog;
      Lecture fichierLecture(nomFichier);

      //on lance la lecture tant qu'il y a des logs a lire dans le fichier
      while(fichierLecture.LireLigneLog(requeteTemporaire))
      {
        requeteTemporaire.EnleverBaseUrlSource(baseUrl); //on enleve la base de l'url lorsque elle est locale
        if(fichierLecture.PassageFiltre(requeteTemporaire,filtre_e,filtre_t,temps))
        {
          // si la requête a passé les filtres on l'ajoute aux statistiques
          statLog.AjouterLien(requeteTemporaire.GetPageSource(),requeteTemporaire.GetPageCible());
        }
      }

      if(filtre_g)
      {
         if(statLog.ConstruireGraphe(nomGraphe))
         {
           statLog.AfficherTopDix();
         }
         else
         {
           ErreurGraphe();
           return -1;
         }
      }
      else
      {
        statLog.AfficherTopDix();
      }
  }
  else // il y a eu une erreur
  {
    return -1;
  }
  return 0;
}


int ChoixOption(int argc,char ** argv)
// Algorithme : La méthode lit un à un les paramètres passés par l'utilisateur au
// lancement et en déduit les filtres à activer.
//
// Elle s'occupe également de vérifier qu'il n'y a pas d'erreur de syntaxe,
// d'ouverture de fichier, ou une erreur dans les arguments des options
//
{
  int i=1;
  while (i < argc)
  {
    if(i==argc-1) // dernier argument passé lors de l'appel
    {
      // on vérifie que l'extension est .log
      if (strlen(argv[i])>=5 && argv[i][strlen(argv[i])-4]=='.' && argv[i][strlen(argv[i])-3]=='l' && argv[i][strlen(argv[i])-2]=='o' && argv[i][strlen(argv[i])-1]=='g')
      {
        // on vérifie que le fichier existe et peut être ouvert
        if(Lecture::TestOuvertureFichier((string)argv[i]))
        {
          nomFichier=(string)argv[i];
        }
        else
        {
          ErreurFichier();
          return -1;
        }
      }
      else
      {
        ErreurSyntaxe();
        return -1;
      }
    }

    // vérification de l'option -g
    else if( !filtre_g && strcmp( argv[i],"-g" )==0 )
    {
      if (i!=argc-2 && strlen(argv[i+1])>=5 && argv[i+1][strlen(argv[i+1])-4]=='.' && argv[i+1][strlen(argv[i+1])-3]=='d' && argv[i+1][strlen(argv[i+1])-2]=='o' && argv[i+1][strlen(argv[i+1])-1]=='t')
      {
        filtre_g=true;
        i++;
        nomGraphe=(string)argv[i];
      }
      else
      {
        ErreurSyntaxe();
        return -1;
      }
    }

    // vérification de l'option -e
    else if( !filtre_e && strcmp( argv[i],"-e" )==0 )
    {
      filtre_e=true;
    }

    // vérification de l'option -t
    else if( !filtre_t && strcmp( argv[i],"-t" )==0 )
    {
      if( i!=argc-2)
      {

        if(strlen(argv[i+1])==1 && argv[i+1][0]<='9' && argv[i+1][0]>='0')
        {
          temps = argv[i+1][0]-'0';
          i++;
          filtre_t=true;
        }
        else if(strlen(argv[i+1])==2 && argv[i+1][0]<='9' && argv[i+1][0]>='0' && argv[i+1][1]<='9' && argv[i+1][1]>='0')
        {
          temps = ( 10*(argv[i+1][0]-'0') ) + ( argv[i+1][1]-'0' );
          if(temps<=23)
          {
            i++;
            filtre_t=true;
          }
          else
          {
            ErreurTemps();
            return -1;
          }
        }
        else
        {
          ErreurSyntaxe();
          return -1;
        }
      }
      else
      {
        ErreurSyntaxe();
        return -1;
      }
    }
    else
    {
      ErreurSyntaxe();
      return -1;
    }
    i++;
  }

  if(argc==1) // aucun paramètre n'a été passé
  {
    ErreurSyntaxe();
    return -1;
  }
  return 0;
} //----- Fin de ChoixOption


// ces fonctions nous permettent de pouvoir changer facilement les messages d'erreur si il y a besoin
inline void ErreurSyntaxe()
{
  cerr<<"Erreur de syntaxe : veuillez vous référez au manuel en tapant \"man ./analogman\""<<endl;
}

inline void ErreurFichier()
{
  cerr << "Erreur: Problème sur l'ouverture du fichier .log. Vérifiez que celui-ci existe, et que vous disposez des droits nécessaires"<<endl;
}

inline void ErreurTemps()
{
  cerr<<"Erreur : L'heure doit être comprise entre 0 et 23"<<endl;
}
inline void ErreurGraphe()
{
  cerr<<"Erreur lors de l'ouverture du fichier .dot. Vérifiez que vous disposez des droits nécessaires."<<endl;
}
