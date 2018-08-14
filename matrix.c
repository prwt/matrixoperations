#include <stdio.h>
#include <matrix.h>


//1.1.1 Initialisation

/*Cette fonction crée une matrice creuse en allouant de la mémoire pour celle-ci et en l’initialisant. Elle retourne
un pointeur vers la matrice ou NULL si une erreur s’est produite. Tous les éléments de la nouvelle matrice ont
la valeur 0 (zéro).*/

//ok
struct matrix * matrix_init ( unsigned int nlines , unsigned int ncols )
{
    struct matrix* tab [nlines][ncols] = malloc (sizeof(int)*ncols*nlines);
    if (tab==NULL) return NULL;
    return tab;
}

//WIP
struct sp_matrix * sp_matrix_init ( double precision , unsigned int nlines ,
unsigned int ncols ){
    
    struct sp_matrix* newmatrix = (struct sp_matrix*) malloc (sizeof(struct sp_matrix));
    if (newmatrix==NULL) return NULL;

    newmatrix->precision = precision;
    newmatrix->nlines = nlines;
    newmatrix->ncols = ncols;

    return newmatrix;
}


//1.1.2 Destruction
//ok
void matrix_free ( struct matrix * matrix ){
    free(matrix);
}
//ok
void sp_matrix_free ( struct sp_matrix * matrix ) {

    struct line* tracker = (struct line*) malloc(sizeof(struct line));
    tracker = matrix->lines;
    struct elem* elemtracker = (struct elem*) malloc(sizeof(struct elem));
    elemtracker= matrix->lines->elems;

    while (tracker!=NULL){
        
        while(elemtracker!=NULL){
            elemtracker = matrix->lines->elems->next;
            free (matrix->lines->elems);
            matrix->lines->elems = elemtracker;

        }
        tracker = matrix->lines->next;
        free (matrix->lines)
        matrix->lines = tracker;
    }

}

//Cette fonction libère l’entièreté de la mémoire qui a été allouée pour une matrice. Après appel, le contenu de la matrice est indéfini.

//1.1.3 Définition de la valeur d’un élément d’une matrice
//ok
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
    struct line* tracker = (struct line*) malloc(sizeof(struct line));
    newmatrix->lines = (struct line*) malloc(sizeof(struct line))
    tracker = sp_matrix->lines;
    struct elem* elemtracker = (struct elem*) malloc(sizeof(struct elem));
    elemtracker=sp_matrix->lines->elems;
    int nlinescount = nlines;
    
    //cas 1: la ligne n'existe pas (et donc l'élément non plus)
    //cas 2: la ligne existe 
    //cas 2.1: la ligne existe et l'élément existe
    //cas 2.2: la ligne existe et l'élément n'existe pas 
    
    //newmatrix->lines->next = (struct line*) malloc(sizeof(struct line));
        

    while (i < tracker->next->i){
        
        tracker = tracker->next;

    }   

    // La ligne cible n'existe pas 
    if (tracker->next->i>i){
        struct line* newline = (struct line*) malloc(sizeof(struct line));
        struct line* temp = (struct line*) malloc(sizeof(struct line));
        newline->i=i;
        temp = tracker->next;
        tracker= newline;
        tracker->next = temp;
        free(temp);    

    }

    elemtracker = tracker->elems;
    while(elemtracker->j<j){
        elemtracker = elemtracker->next; 
    }

    // L'élément cible n'existe pas
    if (elemtracker->next->j>j){
        struct elem* newelem = (struct elem*) malloc(sizeof(struct elem));
        struct elem* tempelem = (struct elem*) malloc(sizeof(struct elem));
        
        newelem->j = j;
        newelem->value = value;
        temp = elemtracker->next;
        tracker = newelem;
        elemtracker->next = tempelem;
        free(tempelem);


    }    

    return sp_matrix;
   
   //Quid si matrice vide à la base? Quid si aucun élément dans la ligne à la base? 


    

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

double matrix_get ( const struct matrix *matrix , unsigned int i, unsigned int j){

    return matrix[i][j];
};
doub    le sp_matrix_get ( const struct sp_matrix *matrix , unsigned int i,
unsigned int j){

    struct line* tracker = (struct line*) malloc(sizeof(struct line));
    tracker = newmatrix->lines;
    struct elem elemtracker = (struct elem*) malloc(sizeof(struct elem));
    
    while((tracker->i!=i)&&(tracker!=NULL)){
        tracker = tracker->next;
    }

    elemtracker=tracker->elems;
    

    while((elemtracker->j!=j)&&(elemtracker!=NULL))
    {
        
        elemtracker = elemtracker->next;

    }
    
    if ((elemtracker==NULL)||(tracker==NULL)){return 0;}
    
    else {

        return elemtracker->value;
    
    }
    
}

//Cette fonction retourne la valeur associée à un élément de la matrice.


//1.1.5 Addition de deux matrices
struct matrix * matrix_add ( const struct matrix *m1 , const struct matrix *m2 ){

    //Cas limite, taille de matrices différentes

    if ((m1->nlines != m2->nlines) || (m1->ncols!=m2->ncols)){return NULL;}

   struct matrix* sumtab [nlines][ncols] = malloc (sizeof(int)*ncols*nlines);

    for (int i=0; i<m1->nlines;i++){
        
        for (int j=0; j<m1->ncols;j++)
        {

            sumtab[i][j]=m1[i][j] + m2[i][j];
        }
    }

    return sumtab;
}


struct sp_matrix * sp_matrix_add ( const struct sp_matrix *m1 ,
const struct sp_matrix *m2 ){
    if ((m1->nlines!=m2->nlines)||(m1->ncols!=m2->ncols)){return NULL;}
    
    struct matrix* output = sp_matrix_init ( m1->precision, m1->nlines, m1->ncols);
    double temp = 0; 

    for (int i=0; i<m1->nlines;i++){
        
        for (int j=0; j<m1->ncols;j++){
            
            temp = sp_matrix_get(m1, i, j) + sp_matrix_get(m2, i, j)
            sp_matrix_set(output,i,j, temp);
            temp = 0;

        }
    }
    
    return output;

}

/*Cette fonction retourne une nouvelle matrice résultant de l’addition des deux matrices données en paramètre.
En cas d’erreur, NULL est retourné. Les deux matrices m1 et m2 ne sont pas modifiées.*/


//1.1.6 Transposée d’une matrice
struct matrix * matrix_transpose ( const struct matrix * matrix ){
    
    struct matrix* tab = matrix_init(matrix->ncols,matrix->nlines);
    double temp = 0;
    for (int i=0; i<matrix->nlines;i++){
        
        for (int j=0; j<matrix->ncols;j++){
            temp = matrix_get(matrix,i,j);
            matrix_set(tab,j,i,temp);
            temp = 0;
            
        }
    }

    return tab;
}



struct sp_matrix * sp_matrix_transpose ( const struct sp_matrix * matrix ){

    struct matrix* output = sp_matrix_init ( m1->precision, m1->nlines, m1->ncols);

    for (int i=0; i<matrix->nlines;i++){
        
        for (int j=0; j<matrix->ncols;j++){
            temp = sp_matrix_get(matrix,i,j);
            matrix_set(output,j,i,temp);
            temp = 0;
        }
    }
    return output;
}



/*Cette fonction calcule la transposée de la matrice passée en paramètre. Cette transposée est une nouvelle
matrice et est retournée par la fonction. En cas d’erreur, NULL est retourné. La matrice matrix passée en
paramètre n’est pas modifiée.*/

//1.1.7 Multiplication de deux matrices
struct matrix * matrix_mult ( const struct matrix *m1 , const struct matrix *m2 ){

    struct matrix* tab = matrix_init(matrix->ncols,matrix->nlines);
    double temp=0;
    for (int i=0; i<m1->nlines){
        
        for (int j=0;j<m1->ncols){
        
            for (int k=0; k<m1->nlines){
                temp = temp + matrix_get(m1,i,k)*matrix_get(m2,k,j);
            }
            matrix_set(tab,i,j,temp);
            temp=0;
        }
    }
    
    return tab;

}




struct sp_matrix * sp_matrix_mult ( const struct sp_matrix *m1 ,
const struct sp_matrix *m2 ){

    struct matrix* tab = matrix_init(matrix->ncols,matrix->nlines);
    
    double temp=0;
    for (int i=0; i<m1->nlines){
        
        for (int j=0;j<m1->ncols){
        
            for (int k=0; k<m1->nlines){
                temp = temp + sp_matrix_get(m1,i,k)*sp_matrix_get(m2,k,j);
            }
            sp_matrix_set(output,i,j,temp);
            temp=0;
        }
    }
    
    return output;



}
/*Cette fonction calcule la nouvelle matrice, résultant du produit des deux matrices données en paramètre. Cette
transposée est une nouvelle matrice et est retournée par la fonction. En cas d’erreur, NULL est retourné. Les
deux matrices m1 et m2 ne sont pas modifiées.*/

//1.1.8 Conversion d’une matrice tableau vers une matrice creuse

struct sp_matrix * matrix_to_sp_matrix ( const struct matrix *matrix, double precision ){

    struct matrix* output = sp_matrix_init (precision, matrix->nlines, matrix->ncols);
    double temp=0;

    for (int i=0; i<matrix->nlines;i++){
        
        for (int j=0; j<matrix->ncols;j++){
    
            temp = matrix_get(matrix,i,j);
            sp_matrix_set(output,i,j,temp);
            temp = 0;
    
        }
    }

    return output;
}

/*Cette fonction crée une matrice creuse dont les éléments correspondent à la matrice tableau matrix. Autrement
dit, la valeur de l’élément (i,j) de la nouvelle matrice est égal à matrix->elems[i][j].*/

//1.1.9 Conversion d’une matrice creuse vers une matrice tableau

struct matrix * sp_matrix_to_matrix ( const struct sp_matrix * matrix ){

    struct matrix* tab = matrix_init(matrix->ncols,matrix->nlines);
    
    for (int i=0; i<matrix->nlines;i++){
        
        for (int j=0; j<matrix->ncols;j++){
    
            temp = sp_matrix_get(matrix,i,j);
            matrix_set(tab,i,j,temp);
            temp = 0;
    
        }
    }

    return tab;

}

/*Cette fonction crée une matrice tableau dont les éléments correspondent à la matrice cruse matrix. Autrement
dit, la valeur de elems[i][j] de la nouvelle matrice est égal à l’élément (i,j).*/

//1.1.10 Sauvegarde d’une matrice dans un fichier
int matrix_save ( const struct matrix *matrix , char * path ){

    FILE* fp;
    //make sure this works with path like this!
    filename = strcat(path,".csv");
    fp = fopen(filename, "w+");
    if(fp==NULL){return -1;}
    double temp=0;
    for (int i=0; i<matrix->ncols;i++){
        
        fprintf(fp,"\n");
        
        for (int j=0; j<matrix->ncols;j++){
            
            temp = matrix_get(matrix,i,j);      
            fpritnf(fp,",%d",temp);
            temp = 0;
        
        }
    }    
    int closingstatus = fclose(fp);
    if (closingstatus!=0){return -1;}

    return 0;


}
int sp_matrix_save ( const struct sp_matrix *matrix , char * path ){

    FILE* fp;
    //make sure this works with path like this!
    filename = strcat(path,".csv");
    fp = fopen(filename, "w+");
    if(fp==NULL){return -1;}
    double temp=0;
    
    for (int i=0; i<matrix->ncols;i++){
        
        fprintf(fp,"\n");
        
        for (int j=0; j<matrix->ncols;j++){
            
            temp = sp_matrix_get(matrix,i,j);      
            fpritnf(fp,",%d",temp);
            temp = 0;
        
        }
    }    

    int closingstatus = fclose(fp);
    if (closingstatus!=0){return -1;}

    return 0;


}

/* Cette fonction sauvegarde une matrice matrix dans un fichier dont le chemin est donné par l’argument path.
Si le fichier existe, son contenu est remplacé. Elle retourne 0 en cas de succès, -1 en cas d’erreur.
Afin de mener à bien cette opération, vous devez choisir un format de fichier qui vous semble le plus approprié.
Ce choix devra être justifié dans un rapport annexe. */

//1.1.11 Chargement d’une matrice à partir d’un fichier

struct matrix * matrix_load ( char * path ){

    fp= fopen(path, "r");
    char ch;
    int nbrlignes=0;
    if (fp==NULL){return -1;}
    int maxcharperline=0;
    int nbcharthisline=0;
        //compter les lignes du fichier 
    
    while(!=feof(fp)){
        ch = fgetc(fp);
        nbcharthisline++;
        if (nbcharthisline>maxcharperline){maxcharperline=nbcharthisline;}
        if (ch== '\n'){
            nbrlignes++;
            nbcharthisline=0;
        }

    }

    rewind(fp);


    struct matrix* tab = matrix_init(nbrlignes,maxcharperline);


      for (int i=0; i<tab->ncols;i++){
        
        
        for (int j=0; j<tab->ncols;j++){
            
            ch = fgetc(fp);
            matrix_set(matrix,i,j,ch);
            
        }
    }    

    return tab;
}

struct sp_matrix * sp_matrix_load ( char * path );
{
    
    struct matrix* output = sp_matrix_init (precision, matrix->nlines, matrix->ncols);
    
    fp= fopen(path, "r");
    char ch;
    int nbrlignes=0;
    if (fp==NULL){return -1;}
    int maxcharperline=0;
    int nbcharthisline=0;
        //compter les lignes du fichier 
    
    while(!=feof(fp)){
        ch = fgetc(fp);
        nbcharthisline++;
        if (nbcharthisline>maxcharperline){maxcharperline=nbcharthisline;}
        if (ch== '\n'){
            nbrlignes++;
            nbcharthisline=0;
        }

    }

    rewind(fp);


    struct matrix* output = matrix_init(nbrlignes,maxcharperline);


      for (int i=0; i<output->ncols;i++){
        
        
        for (int j=0; j<output->ncols;j++){
            
            ch = fgetc(fp);
            sp_matrix_set(output,i,j,ch);
            
        }
    }    

    return output;
}



/*Cette fonction charge et retourne une matrice depuis un fichier dont le chemin est donné par l’argument path.
En cas d’erreur, elle retourne -1.
Une matrice respectivement sauvegardée à l’aide des fonctions matrix_save et sp_matrix_save doit pouvoir
être chargée à l’aide des fonctions matrix_load et sp_matrix_load.*/