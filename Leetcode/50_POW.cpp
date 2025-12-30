#include <iostream>

using namespace std;

double myPow(double x, int n) {
    long long m = n;
    if(m < 0) m = -m;

    double ans = 1;
    while(m > 0){
    if(m%2 == 1){
        ans *= x;
        m--;
    } else{
        m = m/2;
        x *= x;
    }
    }

    if(n < 0) return 1.0/ans;
    return ans;
}

int main() {
    cout << "2.0^10 = " << myPow(2.0, 10) << endl;
    cout << "2.1^3 = " << myPow(2.1, 3) << endl;
    cout << "2.0^-2 = " << myPow(2.0, -2) << endl;
    return 0;
}
