#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}


#define FILL(ptr, value) FILL_((ptr), sizeof(ptr)/sizeof(value), (value))
 
template <typename T>
void FILL_(void * ptr, size_t size, T value){
  std::fill((T*)ptr, (T*)ptr+size, value);
}
 

ll dp[101][100001];

int main(){
    std::ios::sync_with_stdio(false);
    int n, w;
    cin >> n >> w;
    ll weight[n] = {};
    int value[n] = {};

    for(int i=0;i<n;++i)
    {
        cin >> weight[i] >> value[i];
    }
    FILL(dp, 1ll << 62);
    dp[0][0] = 0;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=100000;++j)
        {
            if(dp[i][j] + weight[i] <= w)
            {
                dp[i+1][j + value[i]] = min(dp[i+1][j + value[i]], dp[i][j] + weight[i]);
            }
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        }
    }
    
    for(int i=100000;i>0;--i)
    {
        if(dp[n][i] != (1ll << 62))
        {
            cout << i << endl;
            break;
        }
    }
}