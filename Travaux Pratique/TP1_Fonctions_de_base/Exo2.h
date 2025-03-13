


typedef struct {
    float x;
    float y;
} Point;

void remplissage(Point tab[], int taille);
void affichage(Point tab[], int taille);
float distanceOrigine(Point p);
float plusPetiteDistanceOrigine(Point tab[], int taille);
void deuxPointsPlusEloignes(Point tab[], int taille, int *indice1, int *indice2);
void triParDistanceOrigine(Point tab[], int taille);

