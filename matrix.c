#include <stdio.h>
#include <matrix.h>


//1.1.1 Initialisation

/*Cette fonction crée une matrice creuse en allouant de la mémoire pour celle-ci et en l’initialisant. Elle retourne
un pointeur vers la matrice ou NULL si une erreur s’est produite. Tous les éléments de la nouvelle matrice ont
la valeur 0 (zéro).*/

//ok
struct matrix * matrix_init ( unsigned int nlines , unsigned int ncols )
{
    int tab [nlines][ncols] = malloc (sizeof(int)*ncols*nlines);
    if (tab==NULL) return NULL;
};

//WIP
struct sp_matrix * sp_matrix_init ( double precision , unsigned int nlines ,
unsigned int ncols ){
    
    struct sp_matrix newmatrix = (struct sp_matrix*) malloc (sizeof(struct sp_matrix));
    if (newmatrix==NULL) return NULL;

    newmatrix->precision = precision;
    newmatrix->nlines = nlines;
    newmatrix->ncols = ncols;

    struct line* tracker = (struct line*) malloc(sizeof(struct line));
    newmatrix->lines = (struct line*) malloc(sizeof(struct line))
    tracker = newmatrix->lines;
    struct elem elemtracker = (struct elem*) malloc(sizeof(struct elem));
    elemtracker=newmatrix->lines->

    while (tracker->next!=NULL){
        newmatrix->lines->next = (struct line*) malloc(sizeof(struct line));
        
        tracker = newmatrix->lines->next;
    }


};


//1.1.2 Destruction

void matrix_free ( struct matrix * matrix ){
    free(matrix);
}
void sp_matrix_free ( struct sp_matrix * matrix ) {
    
    while(tracker!=null){

    }
}

//Cette fonction libère l’entièreté de la mémoire qui a été allouée pour une matrice. Après appel, le contenu de la matrice est indéfini.

//1.1.3 Définition de la valeur d’un élément d’une matrice

int matrix_set ( struct matrix *matrix , unsigned int i, unsigned int j, double val ){

matrix[i][j] = val;
return matrix;

}

int sp_matrix_set ( struct sp_matrix * sp_matrix , unsigned int i, unsigned int j,
double val ){

    //gestion erreur

    //La ligne n'existe pas
    //La ligne existe mais pas la valeur
    //La ligne existe et la valeur aussi 



    return 0;
}

/*Cette fonction définit la valeur d’un élément d’une matrice. La fonction retourne −1 en cas d’erreur, 0 sinon.
Il s’agit de la fonction la plus importante de l’implémentation des matrices creuses. Si elle est correctement
réalisée, les fonctions d’addition, de transposée et de conversion de tableau devraient être relativement triviales
à implémenter.
Réfléchissez notamment aux cas suivants (liste non exhaustive) :
— val 6= 0 et la ligne i ne contient que des zéros
— val 6= 0 et l’élément (i,j) est nul
— val = 0 et la ligne ne contient que l’élément (i,j) comme élément non-nul*/

//1.1.4 Récupération de la valeur d’un élément d’une matrice

double matrix_get ( const struct matrix *matrix , unsigned int i, unsigned int j);
double sp_matrix_get ( const struct sp_matrix *matrix , unsigned int i,
unsigned int j);

//Cette fonction retourne la valeur associée à un élément de la matrice.


//1.1.5 Addition de deux matrices
struct matrix * matrix_add ( const struct matrix *m1 , const struct matrix *m2 );
struct sp_matrix * sp_matrix_add ( const struct sp_matrix *m1 ,
const struct sp_matrix *m2 );
/*Cette fonction retourne une nouvelle matrice résultant de l’addition des deux matrices données en paramètre.
En cas d’erreur, NULL est retourné. Les deux matrices m1 et m2 ne sont pas modifiées.*/


//1.1.6 Transposée d’une matrice
struct matrix * matrix_transpose ( const struct matrix * matrix );
struct sp_matrix * sp_matrix_transpose ( const struct sp_matrix * matrix );
/*Cette fonction calcule la transposée de la matrice passée en paramètre. Cette transposée est une nouvelle
matrice et est retournée par la fonction. En cas d’erreur, NULL est retourné. La matrice matrix passée en
paramètre n’est pas modifiée.*/

//1.1.7 Multiplication de deux matrices
struct matrix * matrix_mult ( const struct matrix *m1 , const struct matrix *m2 );
struct sp_matrix * sp_matrix_mult ( const struct sp_matrix *m1 ,
const struct sp_matrix *m2 );

/*Cette fonction calcule la nouvelle matrice, résultant du produit des deux matrices données en paramètre. Cette
transposée est une nouvelle matrice et est retournée par la fonction. En cas d’erreur, NULL est retourné. Les
deux matrices m1 et m2 ne sont pas modifiées.*/

//1.1.8 Conversion d’une matrice tableau vers une matrice creuse

struct sp_matrix * matrix_to_sp_matrix ( const struct matrix *matrix ,
double precision );

/*Cette fonction crée une matrice creuse dont les éléments correspondent à la matrice tableau matrix. Autrement
dit, la valeur de l’élément (i,j) de la nouvelle matrice est égal à matrix->elems[i][j].*/

//1.1.9 Conversion d’une matrice creuse vers une matrice tableau

struct matrix * sp_matrix_to_matrix ( const struct sp_matrix * matrix );

/*Cette fonction crée une matrice tableau dont les éléments correspondent à la matrice cruse matrix. Autrement
dit, la valeur de elems[i][j] de la nouvelle matrice est égal à l’élément (i,j).*/

//1.1.10 Sauvegarde d’une matrice dans un fichier
int matrix_save ( const struct matrix *matrix , char * path );
int sp_matrix_save ( const struct sp_matrix *matrix , char * path );

/* Cette fonction sauvegarde une matrice matrix dans un fichier dont le chemin est donné par l’argument path.
Si le fichier existe, son contenu est remplacé. Elle retourne 0 en cas de succès, -1 en cas d’erreur.
Afin de mener à bien cette opération, vous devez choisir un format de fichier qui vous semble le plus approprié.
Ce choix devra être justifié dans un rapport annexe. */

//1.1.11 Chargement d’une matrice à partir d’un fichier

struct matrix * matrix_load ( char * path );
struct sp_matrix * sp_matrix_load ( char * path );

/*Cette fonction charge et retourne une matrice depuis un fichier dont le chemin est donné par l’argument path.
En cas d’erreur, elle retourne -1.
Une matrice respectivement sauvegardée à l’aide des fonctions matrix_save et sp_matrix_save doit pouvoir
être chargée à l’aide des fonctions matrix_load et sp_matrix_load.*/