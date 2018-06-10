#include <iostream>
#include <cmath>
using namespace std;

const int MAX_N = 100001;
int dp[MAX_N];
int main()
{
    int n;
    cin >> n;
    dp[0] = 0;
    for(int i=1;i<MAX_N;++i) dp[i] = 1 << 30; 
    
    for(int i=0;i<MAX_N;++i)
    {
        int tmp = 1;
        int pow6 = 0;
        int pow9 = 0;
        do
        {
            pow6 = pow(6, tmp);
            pow9 = pow(9, tmp);

            if(i + pow6 < MAX_N)
            {
                dp[i + pow6] = min(dp[i + pow6], dp[i] + 1);
            }

            if(i + pow9 < MAX_N)
            {
                dp[i + pow9] = min(dp[i + pow9], dp[i] + 1);
            }
            tmp++;
        }while(i + pow6 < MAX_N);
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }

    cout << dp[n] << endl;
}