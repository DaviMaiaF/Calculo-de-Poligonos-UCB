#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

typedef struct {
    float X;
    float Y;
} Ponto;

//calculo da area do triângulo
float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    return fabs((A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y)) / 2.0); //utilização fabs
}

//calculo de area do poligono 
float AreaPoligono(Ponto *vert, int numVert) {
    float areaTotal = 0.0;
    int i;
    for(i = 1; i < numVert - 1; i++) {
        areaTotal += AreaTriangulo(vert[0], vert[i], vert[i + 1]);
    }
    return areaTotal;
}

int main() {
    FILE *file;
    file = fopen("vertices.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    int numVert;
    fscanf(file, "%d", &numVert);

    Ponto *vert = (Ponto *)malloc(numVert * sizeof(Ponto));   
    //Prevenção de Erro 
    if (vert == NULL) {
        printf("Erro de alocacao de memoria.");
        return 1;
    }

    int i;
    for (i = 0; i < numVert; i++) {
        fscanf(file, "%f %f", &vert[i].X, &vert[i].Y);
    }

    fclose(file);

    float area = AreaPoligono(vert, numVert);
    printf("A area do poligono eh %.2f\n", area);

    free(vert);
    return 0;
}
