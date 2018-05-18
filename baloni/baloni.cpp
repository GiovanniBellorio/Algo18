#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> p;
vector<int> soluzione;

int baloni()
{
    int frecce = 0;
    
    for (int i = 0; i < N; i++)
    {
    	soluzione[p[i]]++;

    	if (soluzione[p[i]+1] > 0)
    		soluzione[p[i]+1]--;

    	#if 0
    	printf("%d\n", p[i] );
    	for (int j = 0; j <= N; j++)
    		printf("%d ", soluzione[j] );
    	printf("\n");
    	#endif
    }

    for (int i = 0; i <= N; i++)
    	frecce += soluzione[i];

    return frecce;
}


int main() 
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &N);

    p.resize(N);
    soluzione.resize(N+1);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &p[i]);
        soluzione[i] = 0;
    }
    
    printf("%d\n", baloni());
    return 0;
}