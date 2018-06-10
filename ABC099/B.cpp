#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    long long ans = (long long)((b - a) + 1) * (b - a) / 2 - b;
    cout << ans << endl;
}