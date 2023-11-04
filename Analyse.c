#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "SortAlgs.c"

#define NB_PTS_MAX 100000
#define NB_METH_MAX 10

void RandomInit(int T[],int n){
    int i;
    srand(time(NULL));
    for(i=0 ; i<n ; i++){
        T[i] = rand()%101;
    }
}

void tracer(){
    char const *gnuname = "D:\\gnuplot\\bin\\plotingFile.txt";
    FILE *f_plot = fopen(gnuname, "w");
    if(f_plot != NULL){
        fprintf(f_plot,"set grid; \n");
        fprintf(f_plot,"set xrange[0:%d]; \n",NB_PTS_MAX);
        fprintf(f_plot,"set yrange[0:1]; \n");
        fprintf(f_plot,"set key box; \n");
        fprintf(f_plot,"set multiplot; \n");

        fprintf(f_plot,"set size 1,1; \n");
        fprintf(f_plot,"set origin 0.0,0.0; \n");
        fprintf(f_plot,"plot 'data.txt' u 1:2 title 'bulle'       w lp lt rgb 'red'   lw 2 axes x1y1 ,");
        fprintf(f_plot,"     'data.txt' u 1:3 title 'insertion'   w lp lt rgb 'green' lw 2 axes x1y1 ,");
        fprintf(f_plot,"     'data.txt' u 1:4 title 'selection'   w lp lt rgb 'blue'  lw 2 axes x1y1 ;\n");
        fprintf(f_plot,"unset multiplot; \n");
        fclose(f_plot);
        FILE *gnuplot = popen("D:\\gnuplot\\bin\\gnuplot -persist D:\\gnuplot\\bin\\plotingFile.txt", "w");
    }
    else{
        printf("Ouverture de fichier ploting est impossible");
    }
}

int main() {        
    FILE *f = fopen("data.txt", "w");
    if(f != NULL){
        int* T = (int*)malloc(NB_PTS_MAX*sizeof(int)), nb_pts, nb_meth;
        double* M = (double*)malloc(NB_METH_MAX*sizeof(double));
        srand(time(NULL));
        for (nb_pts=0 ; nb_pts<=NB_PTS_MAX ; nb_pts+=1000){
            RandomInit(T,nb_pts);
            M[0] = tri_bulle(T,nb_pts);
            M[1] = tri_insertion(T,nb_pts);
            M[2] = tri_selection(T,nb_pts);
            printf("%d\t%f\t%f\t%f\n",nb_pts,M[0],M[1],M[2]);
            fprintf(f,"%d\t%f\t%f\t%f\n",nb_pts,M[0],M[1],M[2]);
        }
        fclose(f);
        tracer();
        free(T);
        free(M);
    }
    else{
        printf("Ouverture de fichier impossible ! \n");
    }
    return 0;
}

