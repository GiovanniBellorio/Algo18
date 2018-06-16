#include <cstdio>
#include <cassert>
#include <string>

using namespace std;

bool nota[100000];
long long memo[100000];

// ricorsione con memorizzazione
long long fibonacci(int n){

	if (nota[n])
		return memo[n];

	assert(n >= 0);
	if(n == 0 || n == 1)
		return 1;

	memo[n] = fibonacci(n-1) + fibonacci(n-2);
	nota[n] = true;
	return memo[n];
}

int main(){
#ifdef 	EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int N;
	scanf("%d", &N);

	printf("%lld\n", fibonacci(N) );

	return 0;
}