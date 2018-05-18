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
    bool trovato;

    for(int i = 0; i < N; i++){

        if(soluzione[i] != -1)
            continue;
        
        soluzione[i] = p[i] - 1;
        int tmp = i;

        for(int j = i + 1; j < N; j++){
            if(soluzione[j] != -1)
                continue;

            if (soluzione[i] == p[j]){
                soluzione[j] = p[j] - 1;
                i = j;
            }
        }
        
        i = tmp;
        frecce++;
    }
    
    #if 0
        for (int i = 0; i < N; i++)
            printf("%d ", soluzione[i]);
        printf("\n");
    #endif
    
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
    soluzione.resize(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &p[i]);
        soluzione[i] = -1;
    }

#if 0
    for (int i = 0; i < N; i++)
        printf("%d ", p[i]);
    printf("\n");
#endif
    
    printf("%d\n", baloni());
    return 0;
}