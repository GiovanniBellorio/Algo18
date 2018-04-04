#include <cstdio>
#include <cassert>
#include <string>

using namespace std;

#if 0
bool nota[100000];
long long memo[100000];

// ricorsione con memorizzazione
long long num_piastrellature(int n){
	// ritorna il numero di piastrellature
	// in un bagno di dimensione n

	if (nota[n])
		return memo[n];

	assert(n >= 0);
	if(n == 0 || n == 1)
		return 1;

	memo[n] = num_piastrellature(n-1) + num_piastrellature(n-2);
	nota[n] = true;
	return memo[n];
}
#endif

// ricorsione con stampa delle configurazioni
void print_piastrellature(int n, string result, string tmp) {
	if(n == 0){
		printf("%s\n", (result + tmp).c_str());
		return;
	}
	
	result += tmp;
	print_piastrellature(n-1, result, "[O]");
	
	if(n > 1)
		print_piastrellature(n-2, result, "[OOOO]");
		
	return;
}

int main(){
#ifdef 	EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int N;
	scanf("%d", &N);

#if 0
	printf("%lld\n", num_piastrellature(N) );
#endif

#if 1
	print_piastrellature(N, "", "");
#endif

	return 0;
}