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

int get_match_id(int a, int b, int n){
    if(a>b)
    {
        swap(a, b);
    }
    int base = 0;
    if(a>1) {
        base = (n + (n-a+2)) * (a-1) / 2;
    }
    return base + b;
}

int dp[1000001];
int check_depth(map<int,vector<int>> &edges, int src, int n, set<int> &hist) {
    int max_depth = 0;
    if(dp[src] != 0) return dp[src];
    for(int next: edges[src]) {
        //dump(next)
        if(hist.find(next) != hist.end()) return 1 << 30;
        hist.insert(next);
        max_depth = max(max_depth, check_depth(edges, next, n, hist) + 1);
        hist.erase(next);
    }
    //dump(max_depth)
    dp[src] = max_depth;
    return max_depth;
}

int main(){
    std::ios::sync_with_stdio(false);
    map<int,vector<int>> edges;

    int n, tmp;
    cin >> n;
    vector<vector<int>> matches(n);
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<(n-1);++j)
        {
            cin >> tmp;
            matches[i-1].push_back(get_match_id(i, tmp, n));
        }
    }

    for(int i=0;i<n;++i)
    {
        int sz = matches[i].size();
        for(int j=0;j<sz-1;++j)
        {
            edges[matches[i][j]].push_back(matches[i][j+1]);
        }
    }
    int max_depth = 0;

    for(int i=1;i<=n;++i) {
        for(int j=i+1;j<=n;++j){
            int start_node = get_match_id(i,j,n);
            set<int> hist;
            hist.insert(start_node);
            int depth = check_depth(edges, start_node, n, hist);
            if(depth >= (1 << 30)){
                cout << -1 << endl;
                return 0;                
            }
            max_depth = max(max_depth, depth);
        }
    }

    cout << max_depth + 1 << endl;
}