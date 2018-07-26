/**
* user:  VR419955
* fname: BELLORIO
* lname: GIOVANNI
* task:  pirelloneGFB
* score: 12.0
* date:  2018-06-18 09:50:40.291892
*/
#include <cassert>
#include <cstdio>


int main(){
#ifdef EVAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

    int M; // numero di righe
    int N; // numero di colonne
    int B; // ordine del pirellone
    scanf("%d%d%d", &M, &N, &B);

    int pirellone[M][N];

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            scanf("%d",&pirellone[i][j]);

#if 0
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++)
            printf("%d ",pirellone[i][j]);
        printf("\n");
    }
    printf("\n");
#endif

    int row[M], col[N];
    for (int j = 0; j < N; j++)
         col[j] = pirellone[0][j];
 
    row[0] = 0; 
    for (int i = 1; i < M; i++)
        row[i] = (pirellone[i][0] ^ col[0]);

#if 0
    printf("\n");
    printf("riga: ");
    for (int i = 0; i < M; i++)
        printf("%d ",row[i]);
    printf("\n");
    printf("colo: ");
   for (int j = 0; j < N; j++)
        printf("%d ",col[j]);
    printf("\n");
    printf("\n");
#endif

    int ok = 1;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if ((pirellone[i][j] ^ col[j] ^ row[i]))
                ok = 0;

    if (ok)
    {
        for (int i = 0; i < M; i++)
            printf("%d ", row[i]);
        printf("\n");
        
        for (int j = 0; j < N; j++)
            printf("%d ", col[j]);
        printf("\n");
    }
    else
    {
        for (int i = 0; i < N; i++)
            printf("%d ", 0);
        printf("\n");
        
        for (int j = 0; j < N; j++)
            printf("%d ", 0);
        printf("\n");
    }

    return 0;
}
