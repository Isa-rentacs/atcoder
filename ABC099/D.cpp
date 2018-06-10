#include <iostream>

using namespace std;

const int N = 501;
const int C = 31;

int initialColor[N][N];
int cost[C][C];
int sum_cost[3][C];

int main()
{
    int n, c;
    cin >> n >> c;
    
    for(int i=0;i<c;++i)
    {
        for(int j=0;j<c;++j)
        {
            cin >> cost[i][j];
        }
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin >> initialColor[i][j];
        }
    }



    int ans = 1 << 30;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int ind=0;ind<c;++ind)
            {
                sum_cost[(i+j)%3][ind] += cost[initialColor[i][j] - 1][ind];
            }
        }
    }

    for(int i=0;i<c;++i)
    {
        for(int j=0;j<c;++j)
        {
            for(int k=0;k<c;++k)
            {
                if(i == j || j == k || i == k) continue;

                ans = min(ans, sum_cost[0][i] + sum_cost[1][j] + sum_cost[2][k]);
            }
        }        
    }
    cout << ans << endl;
}