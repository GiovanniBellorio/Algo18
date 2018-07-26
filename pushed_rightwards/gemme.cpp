#include <cstdio>
#include <cassert>

int max_guadagno(int result[], int k, int N){
	int max = 0;
	for (int i = k; i<=N; i++)
		if (result[i]>max)
			max = result[i];
	return max;
}

int main(){
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N;
    scanf("%d", &N);

    int gemme[N+1];
    int troll[N+1];

    for (int i = 1; i<=N; i++)
    	scanf("%d", &gemme[i]);

    for (int i = 1; i<=N; i++)
    	scanf("%d", &troll[i]);

    int result[N+1];
    int gemme_future = 0;
    for(int i = N; i>=1; i--){
    	gemme_future = max_guadagno(result, troll[i]+i+1, N);
    	result[i] = gemme[i] + gemme_future;
    }

    printf("%d\n", result[1]);

	return 0;
}