#include <iostream>
using namespace std;

long long factorial(int n){
    if( n < 0){
        cout << "factorial does not exist \n";
        return -1;
    }

    if(n == 1 || n == 0){
        return 1;
    }
    long long fact = 1;

    for(int i = 2; i <= n; i++){
        fact *= i;
    }
    return fact;
}

long long factRecur(int n){
    if(n == 1 || n == 0){
        return 1;
    }

    if(n < 0){
        cout << "factorial does not exist for the negative number\n";
        return -1;
    }

    return (long long)n * factRecur(n-1);
}


int main(){
    int n = -3;

    cout << "factorial : " << factRecur(n) << endl;
    
    return 0;
}