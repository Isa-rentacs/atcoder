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

#define FILL(ptr, value) FILL_((ptr), sizeof(ptr)/sizeof(value), (value))
 
template <typename T>
void FILL_(void * ptr, size_t size, T value){
  std::fill((T*)ptr, (T*)ptr+size, value);
}
 
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int happiness[n][3] = {};
    for(int i=0;i<n;++i)
    {
        cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];
    }
    int dp[n+1][3] = {};

    dp[0][0] = happiness[0][0];
    dp[0][1] = happiness[0][1];
    dp[0][2] = happiness[0][2];

    for(int i=1;i<n;++i)
    {
        for(int j=0;j<3;++j)
        {
            for(int k=0;k<3;++k)
            {
                if(j == k) continue;
                dp[i][k] = max(dp[i][k], dp[i-1][j] + happiness[i][k]);
            }
        }
    }
    int ret = 0;
    for(int i=0;i<3;++i)
    {
        ret = max(ret, dp[n-1][i]);
    }
    cout << ret << endl;
}