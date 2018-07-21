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

bool predication(const pair<int,int> &a, const pair<int,int> &b){
    return a.second < b.second;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n, m;
    vector<pair<int,int> > pairs;
    cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin >> a >> b;
        pairs.push_back(make_pair(a,b-1));
    }

    sort(pairs.begin(), pairs.end(), predication);

    int ans = 0;
    int cur_end = 0;
    for(int i=0;i<pairs.size();++i)
    {
        if(pairs[i].first <= cur_end)
        {
            continue;
        }
        else
        {
            ans++;
            cur_end = pairs[i].second;
        }
    }
    cout << ans << endl;
}