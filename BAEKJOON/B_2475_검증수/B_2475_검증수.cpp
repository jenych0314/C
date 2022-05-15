#include <iostream>
using namespace std;

int solve(int n) {
    n %= 10;
    return (n * n) % 10;
}

int main() {
    int n, sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> n;
        sum += solve(n);
    }
    cout << sum % 10 << endl;
}