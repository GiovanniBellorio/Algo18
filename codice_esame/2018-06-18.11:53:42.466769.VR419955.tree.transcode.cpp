/**
* user:  VR419955
* fname: BELLORIO
* lname: GIOVANNI
* task:  tree_transcode
* score: 100.0
* date:  2018-06-18 11:53:42.466769
*/
#include <cassert>
#include <cstdio>
#include <vector>

std::vector<int> figli[1000000];
int num_nodi = 1;
int prossimo_nodo = 0;

void leggi_albero(){
    int nodo = prossimo_nodo;
    prossimo_nodo++;

    int num_figli;
    scanf("%d", &num_figli);

    num_nodi += num_figli;
    figli[nodo].resize(num_figli);

    for(int i = 0; i < figli[nodo].size(); i++){
        figli[nodo][i] = prossimo_nodo;
        leggi_albero();    
    }
}

void stampa(int radice, int discendenti[]){
    if (figli[radice].size() == 0)
        discendenti[radice] = 1;
    else{
        discendenti[radice] = 0;
        for(int i = 0; i < figli[radice].size(); i++){
            stampa(figli[radice][i], discendenti); 
            int buff = figli[radice][i];
            discendenti[radice] += discendenti[buff]; 
        }
        discendenti[radice]++;
    }
}


int main(){
#ifdef EVAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

    int formato;
    scanf("%d", &formato);

    if (formato == 1){
        leggi_albero();
    
        int discendenti[num_nodi];
        stampa(0, discendenti);

        printf("2 ");
        for (int i = 0; i < num_nodi; i++)
            printf("%d ", discendenti[i]);
    }
    else{
        int num_nodi;
        scanf("%d", &num_nodi);
        
        int discendenti[num_nodi]; 
        discendenti[0] = num_nodi;

        for (int i = 1; i < num_nodi; i++)
            scanf("%d", &discendenti[i]);
        
        int figli[num_nodi];
        for (int i = num_nodi - 1; i >= 0; i--){
            if (discendenti[i] == 1)
                figli[i] = 0;
            else{
                int num_discendenti = discendenti[i]-1;
                int num_figli = 0;
                int tmp = i + 1;
                while (num_discendenti > 0){
                    if (discendenti[tmp] < 0){
                        tmp++;
                        continue;                    
                    }
                    num_discendenti -= discendenti[tmp];
                    discendenti[tmp] = -1;
                    tmp++;
                    num_figli++;
                }
                figli[i] = num_figli;
            }        
        }
        printf("1 ");
        for (int i = 0; i < num_nodi; i++)
            printf("%d ", figli[i]);
    }
    
    printf("\n");
    return 0;
}
