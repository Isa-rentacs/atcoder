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
    int n, q;
    cin >> n >> q;
    ll cnt[n] = {};
    ll ret[n] = {};
    bool visited[n] = {};
    map<int, vector<int>> m;
    int tmpa, tmpb;
    for(int i=0;i<n-1;++i)
    {
        cin >> tmpa >> tmpb;
        tmpa--;
        tmpb--;

        m[tmpa].push_back(tmpb);
        m[tmpb].push_back(tmpa);
    }

    for(int i=0;i<q;++i)
    {
        cin >> tmpa >> tmpb;
        tmpa--;
        cnt[tmpa] += tmpb;
    }

    // traverse
    stack<pair<ll,ll>> st;
    st.push(MP(0, cnt[0]));
    while(!st.empty())
    {
        pair<ll,ll> node = st.top();
        st.pop();
        ret[node.first] = node.second;
        visited[node.first] = true;
        cerr << "visit" << node.first << endl;
        int foo;
        cin >> foo;
        for(int ind : m[node.first])
        {
            if(!visited[ind])
            {
                st.push(MP(ind, node.second + cnt[ind]));
            }

        }
    }

    for(int i=0;i<n;++i)
    {
        cout << ret[i];
        if(i != n-1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
}