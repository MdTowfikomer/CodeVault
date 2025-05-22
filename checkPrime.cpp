#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if( n <= 1){
        cout << "Not prime\n";
        return false;
    }

    if(n == 2){
    cout << n << " is a prime\n";
    return true;
    }

    for(int i = 3; i*i <= n; i++){
        if(n%i == 0){
            cout << "Not prime\n";
            return false;
        }
    }
    cout << n << " is a prime\n";
    return true;
}

int main(){
    int n = 13;
    isPrime(n);

    return 0;
}