#include <cstdio>
#include <cassert>
#include <algorithm>

int max3(int n1, int n2, int n3)
{
	return std::max(std::max(n1,n2),n3);
}

int main() 
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int M, N;
    scanf("%d", &M); // numero di righe
    scanf("%d", &N); // numero di colonne

    int celle[M][N];
    for (int i = 0; i < M; i++ )
    	for (int j = 0; j < N; j++)
    		scanf("%d", &celle[i][j]);

#if 0
    for (int i = 0; i < M; i++ )
    {
    	for (int j = 0; j < N; j++)
    		printf("%d ", celle[i][j]);
    	printf("\n");
    }
#endif

    if (M == 1) // ho solo una riga
    {
    	int max = 0;
    	for (int i = 0; i < N; i++)
    		max += celle[0][i];
    	printf("%d\n", max );
    }
    else if (N == 1) // ho solo una colonna
    {
    	int max = 0;
    	for (int i = 0; i < M; i++)
    		if (max < celle[i][0])
    			max = celle[i][0];
    	printf("%d\n", max );
    }
    else // altrimenti:
    {
    	int percorso[M][N];
    	for (int i = 0; i < M; i++ )
    		for (int j = 0; j < N; j++)
    			percorso[i][j] = 0;

    	// copio ultima colonna:
    	for (int i = 0; i < M; i++)
    		percorso[i][N-1] = celle[i][N-1];

    	// calcolo cammino massimo dinamicamente:
    	for (int j = N-2; j>=0; j--)
    	{
    		for (int i = M-1; i>=0; i--)
    		{
    			if (i == 0) // sono sulla prima riga:
    				percorso[i][j] = celle[i][j] + max3(percorso[i][j+1], percorso[i+1][j+1], 0);
    			else if (i == M - 1) // sono sull'ultima riga:
    				percorso[i][j] = celle[i][j] + max3(percorso[i][j+1], percorso[i-1][j+1], 0);
    			else // altrimenti:
    				percorso[i][j] = celle[i][j] + max3(percorso[i][j+1], percorso[i-1][j+1], percorso[i+1][j+1]);
    		}
    	}

#if 0
    	printf("\n");
		for (int i = 0; i < M; i++ )
		{
			for (int j = 0; j < N; j++)
				printf("%d ", percorso[i][j]);
			printf("\n");
		}
#endif

		// trovo il cammino massimo sulla prima colonna di percorso:
		int max = 0;
    	for (int i = 0; i < M; i++)
    		if (max < percorso[i][0])
    			max = percorso[i][0];
    	printf("%d\n", max );
    }

    return 0;
}