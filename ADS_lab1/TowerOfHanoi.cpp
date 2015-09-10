#include "Header.h"

void TowerOfHanoi(unsigned int n, unsigned int initial, unsigned int auxiliary, unsigned int final){
    if (n == 0) 
        cout<<"Nothing to do"<<endl;
    else if (n == 1) 
        cout<<initial<<" -> "<<final<<endl;
    else if (n == 2){
        cout<<initial<<" -> "<<auxiliary<<"\n"
            <<initial<<" -> "<<final<<"\n"
            <<auxiliary<<" -> "<<final<<"\n";
    }
    else if (n > 2){
        TowerOfHanoi(n-1, initial, final, auxiliary);
        cout<<initial<<" -> "<<final<<endl;
        TowerOfHanoi(n-1, auxiliary, initial, final);
    }
}
