/**
* user:  VR419955
* fname: BELLORIO
* lname: GIOVANNI
* task:  pushed_rightwards
* score: 0.0
* date:  2018-06-18 12:12:07.852290
*/
#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>


int max3(int result[], int K, int N){
    int max = 0;
    for (int i = K; i<=N; i++)
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

    for(int i = 1; i<=N; i++)
        scanf("%d", &gemme[i]);    

    for(int i = 1; i<=N; i++)
        scanf("%d", &troll[i]);    


    int result[N+1];

    int gemme_ft = 0;

    for (int i = N; i>=1; i--){
        gemme_ft = max3(result,troll[i]+i+1,N);
        result[i] = gemme[i]+gemme_ft;
    }

    printf("%d\n", result[1]);

    return 0;
}
