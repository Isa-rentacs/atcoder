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

int prev_place[200001] = {};
int edges[200001] = {};
int ret[200001] = {};
int main(){
    std::ios::sync_with_stdio(false);
    int n, tmp;
    cin >> n;

    fill(prev_place, prev_place + 200001, -1);
    fill(edges, edges + 200001, -1);
    for(int i=0;i<n;++i)
    {
        cin >> tmp;
        if(prev_place[tmp] != -1)
        {
            if(i - prev_place[tmp] >= 2)
            {
                edges[i] = prev_place[tmp];
            }
        }
        prev_place[tmp] = i;        
    }
    
    ret[0] = 1;

    for(int i=1;i<n;++i)
    {
        ret[i] = ret[i-1];
        if(edges[i] != -1)
        {
            ret[i] += ret[edges[i]];
        }
        ret[i] %= 1000000007;
    }
    cout << ret[n-1] << endl;
}