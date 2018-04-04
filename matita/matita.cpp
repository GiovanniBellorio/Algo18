#include <cstdio>
#include <cassert>
#include <algorithm>

int idx = 1;

void fn_matita(int matita[][2], int marcatura[], int N, int M, int A, int B, int result[][2]){
	int new_a, init;

	for(int i = 0; i < M; i++){
		if(matita[i][0] == A){
			new_a = matita[i][1];
			init  = matita[i][0];
		}
		else{
			new_a = matita[i][0];
			init  = matita[i][1];
		}

		if(marcatura[i] == 0 && (new_a == A || init == A)){
			marcatura[i] = 1;

			if(new_a != B)
				fn_matita(matita, marcatura, N, M, new_a, B, result);
			result[M-idx][0] = init;
			result[M-idx][1] = new_a;
			idx++;
			B = A;
		}
	}
}

// MAIN
int main(){
#ifdef 	EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int N, M, A, B;
	scanf("%d%d%d%d", &N, &M, &A, &B);

	int matita[M][2];
	int tmp1, tmp2;
	for(int i = 0; i < M; i++){
		scanf("%d", &tmp1);
		scanf("%d", &tmp2);
		if(tmp1<tmp2){
			matita[i][0] = tmp1;
			matita[i][1] = tmp2;
		}
		else{
			matita[i][0] = tmp2;
			matita[i][1] = tmp1;
		}
	}

#if 0
	// bubble sort
	int min, temp1, temp2;
	for(int i = 0; i < M-1; i++) { 
		min = i;

		for(int j = i+1; j < M; j++) 
  			if( (matita[j][0]*10 + matita[j][1]) < (matita[min][0]*10 + matita[min][1]))
    			min = j;

		temp1 = matita[min][0];
		temp2 = matita[min][1];
		matita[min][0] = matita[i][0]; 
		matita[min][1] = matita[i][1];
		matita[i][0] = temp1;
		matita[i][1] = temp2;
	}
#endif

#if 0
	for(int i = 0; i < M; i++){
		for(int j = 0; j < 2; j++){
			printf("%d ", matita[i][j]);
		}
		printf("\n");
	}
	printf("\n");
#endif

	int marcatura[M];
	for(int i = 0; i < M; i++)
		marcatura[i] = 0;

	int result[M][2];
	fn_matita(matita, marcatura, N, M, A, B, result);

	for(int i = 0; i < M; i++)
		printf("%d %d\n", result[i][0], result[i][1]);

	return 0;
}