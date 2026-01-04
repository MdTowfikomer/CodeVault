#include <iostream>
#include <string>
using namespace std;


int numSub(string s) {
    const int MOD = 1e9 + 7;

    int n = s.size();
    long long k = 0;
    long long count = 0;

    int i = n - 1;
    while (i >= 0) {
        if (s[i] == '1') {
            k++;
        } else {
            count = (count + (k * (k + 1)) / 2 % MOD) % MOD;
            k = 0;
        }
        i--;
    }
    if (k != 0) {
        count = (count + (k * (k + 1)) / 2 % MOD) % MOD;
    }
    return count;
}

int main() {
    // Test cases for numSub
    cout << "Test Case 1: s = \"0110111\"" << endl;
    cout << "Expected: 9" << endl;
    cout << "Result: " << numSub("0110111") << endl << endl;

    cout << "Test Case 2: s = \"101\"" << endl;
    cout << "Expected: 2" << endl;
    cout << "Result: " << numSub("101") << endl << endl;

    cout << "Test Case 3: s = \"111111\"" << endl;
    cout << "Expected: 21" << endl;
    cout << "Result: " << numSub("111111") << endl << endl;

    cout << "Test Case 4: s = \"000\"" << endl;
    cout << "Expected: 0" << endl;
    cout << "Result: " << numSub("000") << endl << endl;

    cout << "Test Case 5: s = \"1\"" << endl;
    cout << "Expected: 1" << endl;
    cout << "Result: " << numSub("1") << endl << endl;

    cout << "Test Case 6: s = \"0\"" << endl;
    cout << "Expected: 0" << endl;
    cout << "Result: " << numSub("0") << endl << endl;

    cout << "Test Case 7: s = \"1110111\"" << endl;
    cout << "Expected: 12" << endl;
    cout << "Result: " << numSub("1110111") << endl << endl;

    return 0;
}