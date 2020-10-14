#include <stdio.h>
#include <stdlib.h>
#define M 100
int main(void){

    int n;
    int N;
    int p;

    int i, j;
    printf("vertices: ");
    scanf("%d", &N);
    printf("edges: ");
    scanf("%d", &n);
    p = 0.5 * (N - 1) * (N - 2);
    if (n > p) {
        printf("Graph is connected\n");
    }
    if (n <= p) {
        printf("Graph is not connected\n");
    }

    int *A = (int *)malloc(n * N * sizeof(int));

    FILE *s;
    s = fopen("platon.dot", "w");
    fprintf(s, "digraph G {\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &A[i*N + j]);

    for (i = 0; i < N; i++)
        for (j = 0; j < n; j++) {
            if (A[i*N + j] != 0){
                while(A[i*N + j] >= 1){
                    fprintf(s, "%d -> %d; \n", i + 1, j + 1);
                    A[i*N + j]--;
                }
            }
        }
    fprintf(s, "}");


    fclose(s);
    system("dot -Tpng -O platon.dot");
    system("xdg-open platon.dot.png");
    free(A);

    return 0;
}