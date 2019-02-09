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

#define  dump(x)  cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

int main(){
    std::ios::sync_with_stdio(false);
    int n, m, src, dst;
    cin >> n >> m;
    vector<vector<int> > vvi;
    vector<set<int> > parents;
    vvi.resize(n+1);
    parents.resize(n+1);
    int parent[n+1] = {0};
    bool isRoot[n+1] = {0};
    int visited[n+1] = {0};
    for(int i=0;i<=n;++i)
    {
        parent[i] = -1;
        isRoot[i] = true;
    } 

    for(int i=0;i<(n+m-1);++i)
    {
        cin >> src >> dst;
        // dump(src);
        // dump(dst);
        isRoot[dst] = false;
        vvi[src].push_back(dst);
        parents[dst].insert(src);
    }

    // find root
    int root = 0;
    for(int i=1;i<=n;++i)
    {
        if(isRoot[i])
        {
            root = i;
        }
    }
    // cerr << "root is " << root << endl;

    // BFS from root
    deque<int> q;
    q.push_back(root);

    while(!q.empty())
    {
        int node = q.front();
        q.pop_front();
        // dump(node);
        for(auto &node_dst : vvi[node])
        {
            visited[node_dst] += 1;

            if(parents[node_dst].size() == visited[node_dst] && !vvi[node_dst].empty())
            {
                q.push_back(node_dst);
            }
            parent[node_dst] = node;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(parent[i] == -1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << parent[i] << endl;
        }
        
    }
}
