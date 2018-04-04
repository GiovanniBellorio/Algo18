#include <cstdio>
#include <cassert>


int main(){
#ifdef 	EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int M, N;

	scanf("%d%d", &M, &N);

	//printf("%d %d", M, N);

	int pirellone[M][N];
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &pirellone[i][j]);
		}
	}

#if 0
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			printf("Riga %d, colonna %d: %d\n", i, j, pirellone[i][j]);
		}
	}
#endif

	int row[M], col[N];
	for(int j = 0; j < N; j++){
		col[j] = pirellone[0][j];
	}

	row[0] = 0;
	for(int i = 1; i < M; i++){
		row[i] = pirellone[i][0] ^ col[0];
	}

#if 0
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			printf("%d ", pirellone[i][j] ^ col[j] ^ row[i]);
		}
		printf("\n");
	}
#endif

	int ok = 1;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(pirellone[i][j] ^ col[j] ^ row[i]){
				ok = 0;
			}
		}
	}

	if(ok){
		for(int i = 0; i < M; i++){
			printf("%d ", row[i]);
		}
		printf("\n");
		for(int j = 0; j < N; j++){
			printf("%d ", col[j]);
		}
		printf("\n");
	}
	else{
		for(int i = 0; i < M; i++){
			printf("%d ", 0);
		}
		printf("\n");
		for(int j = 0; j < N; j++){
			printf("%d ", 0);
		}
		printf("\n");
	}

	return 0;
}