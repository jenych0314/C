#include <iostream>
using namespace std;
// ���ڸ� ���� ����ϱ�
int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int C, n;
        cin >> C;

        int result = 1;
        for (int j = 0; j < C; j++) {
            cin >> n;
            n %= 10;

            result = (result * n) % 10;
        }

        cout << result << endl;
    }

    return 0;
}