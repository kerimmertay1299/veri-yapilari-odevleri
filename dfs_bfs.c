#include <stdio.h>

#define N 6   /* Dugum sayisi  */

/* Graph adjacency matrix */
int graph[N][N] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 1},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0}
};

int ziyaret[N] = {0};

/* -------- DFS (Depth First Search) -------- */
void DFS(int dugum) {
    int i;
    ziyaret[dugum] = 1;
    printf("%d ", dugum);

    for (i = 0; i < N; i++) {
        if (graph[dugum][i] == 1 && ziyaret[i] == 0) {
            DFS(i);
        }
    }
}

/* -------- BFS (Breadth First Search) -------- */
void BFS(int baslangic) {
    int kuyruk[N];
    int on = 0, arka = 0;
    int i;

    for (i = 0; i < N; i++)
        ziyaret[i] = 0;

    ziyaret[baslangic] = 1;
    kuyruk[arka++] = baslangic;

    while (on < arka) {
        int aktif = kuyruk[on++];
        printf("%d ", aktif);

        for (i = 0; i < N; i++) {
            if (graph[aktif][i] == 1 && ziyaret[i] == 0) {
                ziyaret[i] = 1;
                kuyruk[arka++] = i;
            }
        }
    }
}

int main() {

    printf("DFS Gezme Sirasi: ");
    DFS(0);

    printf("\n\nBFS Gezme Sirasi: ");
    BFS(0);

    return 0;
}
