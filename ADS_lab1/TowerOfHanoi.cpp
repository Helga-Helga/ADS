#include "Header.h"

void TowerOfHanoi(int n, int initial, int auxiliary, int final){
    if (n == 0) cout<<"Nothing to do"<<endl;
    else if (n == 1) cout<<initial<<" -> "<<final;
    else if (n == 2){
        cout<<initial<<" -> "<<auxiliary<<endl;
        cout<<initial<<" -> "<<final<<endl;
        cout<<auxiliary<<" -> "<<final<<endl;
    }
    else if (n > 2){
        TowerOfHanoi(n-1, initial, final, auxiliary);
        cout<<initial<<" -> "<<final<<endl;
        TowerOfHanoi(n-1, auxiliary, initial, final);
    }
}
