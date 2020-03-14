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

int main(){
    std::ios::sync_with_stdio(false);
    int n,a,b,tmp;
    cin >> n;
    set<int> edges[n];
    vector<pair<int,int>> num_edges;
    int c[n] = {};
    for(int i=0;i<n-1;++i)
    {
        cin >> a >> b;
        a--;
        b--;
        edges[a].insert(b);
        edges[b].insert(a);
    }

    for(int i=0;i<n;++i){
        cin >> c[i];
    }
    sort(c, c+n);
    int res_max = 0;
    int res[n] = {};
    for(int i=0;i<n-1;++i)
    {
        int score = c[i];
        //dump(score)
        int min_num_edges = 1 << 30;
        int id_node = -1;
        for(int j=0;j<n;++j)
        {
            if(edges[j].size() == 0) continue;
            if(edges[j].size() < min_num_edges)
            {
                min_num_edges = edges[j].size();
                id_node = j;
            }
        }

        res_max += score * min_num_edges;
        //dump(id_node);
        //dump(min_num_edges);
        res[id_node] = score;
        for(int dst: edges[id_node])
        {
            edges[dst].erase(id_node);
        }
        edges[id_node].clear();
    }
    cout << res_max << endl;
    for(int i=0;i<n;++i)
    {
        cout << (res[i] == 0 ? c[n-1] : res[i]) << (" \n")[i==(n-1)];
    }
}