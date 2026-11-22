#ifndef STRUCTURES_H
#define STRUCTURES_H

#define NOM 30
#define CNE 15
#define FIL 10
#define SURV 4

typedef struct Etudiant {
    int id;
    char cne[CNE];
    char nom[NOM];
    char prenom[NOM];
    char filiere[FIL];
    int niveau;
    struct Etudiant *sui; /* liste chainee */
} Etudiant;

typedef struct Enseignant {
    int id;
    char nom[NOM];
    char prenom[NOM];
    int nbSurv; /* pour equilibrer la charge */
    struct Enseignant *sui; /* liste chainee */
} Enseignant;

typedef struct Module {
    int id;
    char nom[50];
    char filiere[FIL];
    int semestre;
    int duree; /* en minutes */
    int idEnseignant; /* responsable */
    int nbInscrits;
    Etudiant *insc; /* liste chainee (copies) */
    struct Module *sui; /* liste chainee */
} Module;

typedef struct Salle {
    int id;
    char nom[20];
    int capacite;
} Salle;

typedef struct Creneau {
    int id;
    char date[11]; /* JJ/MM/AAAA */
    char heureDebut[6]; /* HH:MM */
    char heureFin[6]; /* HH:MM */
} Creneau;

typedef struct Examen {
    int idModule;
    int idCreneau; /* couleur du graphe */
    int idSalle;
    int surveillants[SURV];
} Examen;

#endif