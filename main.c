#include <stdio.h>
#include <limits.h>

#define TAM 7
#define SRC 0

int printGrafo(int dist[], int tam){
    
    printf(" [ R E S U L T A D O ]\n");
    printf(" SRC -> vetor -> distancia \n");
    for (int i = 0; i < tam; i++) {
        printf("  %d -> \t %d \t -> \t %d \n", SRC, i, dist[i]);
    }
    
}

int getMinDist(int dist[], int sptSet[], int tam){

    int min = INT_MAX;
    int imin;

    for (int i = 0; i < TAM; i++) {
        if(sptSet[i] == 0 && dist[i] <= min) {
            min = dist[i];
            imin = i;
        }
    }

    return imin;
}

void dijkstra(int grafo[][TAM], int inicio){

    int minDist;
    int distancia[TAM];
    int sptSet[TAM];

    // Inicializando valores de distancia
    for(int i = 0; i < TAM; i++){
        distancia[i] = INT_MAX;
        sptSet[i] = 0;
    }

    distancia[inicio] = 0;

    // Procura o menor caminho
    for(int i = 0; i < TAM - 1; i++){
        minDist = getMinDist(distancia, sptSet, TAM);
        sptSet[minDist] = 1;
        for (int j = 0; j < TAM; j++) {
            if(!sptSet[j] && grafo[minDist][j] && distancia[minDist] != INT_MAX && distancia[minDist] + grafo[minDist][j] < distancia[j]){
                distancia[j] = distancia[minDist] + grafo[minDist][j];
            }

        }
    }

    printGrafo(distancia, TAM);
}

int main(){

    int grafo[TAM][TAM] =
            { { 0,  7,  0,  5,  0,  0,  0 },
              { 7,  0,  8,  9,  7,  0,  0 },
              { 0,  8,  0,  0,  5,  0,  0 },
              { 5,  9,  0,  0,  15, 6,  0 },
              { 0,  7,  5,  15, 0,  0,  9 },
              { 0,  0,  0,  6,  8,  0, 11 },
              { 0,  0,  0,  0,  9,  11, 0 },
              };

    dijkstra(grafo, SRC);

    return 0;
}