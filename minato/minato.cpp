#include <cstdio>
#include <cassert>


int main() {
#ifdef  EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    // matrice di CHAR campo contenente caratteri + e *
	char campo[N][M];
	
	// matrice INT in cui salvo il numero di percorsi
	int percorsi[N][M];
	
	// inizializzo percorsi[][] a 0
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			percorsi[i][j] = 0;
	
	// salvo il campo su una matrice
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf(" %c", &campo[i][j]);

#if 0
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			printf("%c", campo[i][j] );
		printf("\n");
	}
#endif

	// se l'arrivo è chiuso (+):
	if(campo[N-1][M-1] == '+'){
		printf("0\n");
		return 0;
	}

	// altrimenti calcolo il numero di percorsi:
	for(int i = N-1; i >= 0; i--){
		for(int j = M-1; j >= 0; j--){

			// se sono all'arrivo allora l'unico percorso è stare fermi
			if(i == N-1 && j == M-1)
				percorsi[i][j] = 1;	
			else if(campo[i][j] == '+')
				percorsi[i][j] = 0;
			else{
								
				// se la cella sotto NON è fuori range e NON è una mina allora la considero
				if( (i+1 < N) && (campo[i+1][j] != '+'))
					percorsi[i][j] += percorsi[i+1][j];
				
				// se la cella a destra NON è fuori range e NON è una mina allora la considero	
				if( (j+1 < M) && (campo[i][j+1] != '+'))
					percorsi[i][j] += percorsi[i][j+1];
			}
		}
	}

#if 0
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			printf("%d", percorsi[i][j] );
		printf("\n");
	}
#endif

	printf("%d\n", percorsi[0][0]);
    return 0;
}