/* 
 * File:   main.cpp
 * Author: olya
 *
 * Created on September 10, 2015, 1:47 PM
 */

#include <cstdlib>
#include "Header.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int variant;
    
    while (true){
        
        cout<<"Choose a variant"<<endl;
        cout<<"1. exponentiation\n"
            <<"2. finding the greatest common divisor\n"
            <<"3. calculation of Fibonacci number\n"
            <<"4. tower of Hanoi\n"
            <<"5. exit\n";
        cin>>variant;
        
        switch(variant){
            case 1:
                unsigned int power;
                float number;
                cout<<"Enter a valid non-zero number ";
                cin>>number;
                cout<<"Enter a positive integral number ";
                cin>>power;
                cout<<number<<"^"<<power<<"="<<exponentiation(power, number)<<endl;
                break;
            case 2:
                int m, n;
                cout<<"Enter two numbers ";
                cin>>n>>m;
                try {
                cout<<"The greatest common divisor of "<<n<<" and "<<m<<" is "<<gcd(m,n)<<endl;
                }
                catch (const invalid_argument& e) {
                    cout<<"Bad input."<<endl;
                }
                break;
            case 3:
                unsigned int i;
                cout<<"Enter the index of Fibonacci number ";
                cin>>i;
                cout<<"Algorithm that saves computed values: "<<endl;
                cout<<"F"<<i<<"="<<fibonacci(i)<<endl;
                cout<<"Algorithm that computes values every time: "<<endl;
                cout<<"F"<<i<<"="<<F(i)<<endl;
                break;
            case 4:
                int unsigned rings, initial, auxiliary, final;
                cout<<"Enter the number of rings ";
                cin>>rings;
                cout<<"Enter the number of initial column ";
                cin>>initial;
                cout<<"Enter the number of final column ";
                cin>>final;
                cout<<"Enter the number of auxiliary column ";
                cin>>auxiliary;
                TowerOfHanoi(rings, initial, auxiliary, final);
                break;
            case 5:
                cout<<"Exiting..."<<endl;
                exit(EXIT_SUCCESS);
                break;
            default:
                cerr<<"You've chosen the wrong variant";
                exit(EXIT_FAILURE);
        }
                   
    }
    return 0;
}

