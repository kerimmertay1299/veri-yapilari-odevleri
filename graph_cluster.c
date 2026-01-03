#include <stdio.h>

#define N 6   /* Dugum sayisi  */

/* Graph adjacency matrix olarak tutuluyor */
int graph[N][N] = {
    {0, 1, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0}
};

int ziyaretEdildi[N] = {0};

/* DFS ile ayni cluster icindeki dugumleri bul */
void dfs(int dugum) {
    int i;
    ziyaretEdildi[dugum] = 1;
    printf("%d ", dugum);

    for (i = 0; i < N; i++) {
        if (graph[dugum][i] == 1 && ziyaretEdildi[i] == 0) {
            dfs(i);
        }
    }
}

int main() {

    int i;
    int clusterNo = 1;

    printf("Graph Cluster (Connected Component) Cikarma\n\n");

    for (i = 0; i < N; i++) {
        if (ziyaretEdildi[i] == 0) {
            printf("Cluster %d: ", clusterNo);
            dfs(i);
            printf("\n");
            clusterNo++;
        }
    }

    return 0;
}
