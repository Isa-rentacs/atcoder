#include <iostream>

using namespace std;

int main(){
    int n;
    int ans = 0;
    cin >> n;

    while(n > 0)
    {
        ans += n % 10;
        n /= 10;
    }

    if(ans == 1)
    {
        cout << 10 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}