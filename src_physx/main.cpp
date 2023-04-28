#include <iostream>

using namespace std;

int sum(int a) {
    return a + a;
}

int main() {
    int a;
    cin >> a;
    cout << sum(a) << endl;
    return 0;
}