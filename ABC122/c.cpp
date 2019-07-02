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
    string s;
    cin >> s;
    int len = s.length();
    int cnt[len] = {};
    for(int i=1;i<len;++i)
    {
        if(s[i-1] == 'A' && s[i] == 'C')
        {
            cnt[i] = cnt[i-1] + 1; 
        }
        else
        {
            cnt[i] = cnt[i-1];
        }
    }

    for(int i=0;i<q;++i)
    {
        int l, r;
        cin >> l >> r;
        cout << cnt[r-1] - cnt[l-1] << endl;
    }
}