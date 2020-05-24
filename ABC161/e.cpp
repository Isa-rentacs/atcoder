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
    int n, k, c;
    string s;
    cin >> n >> k >> c;
    cin >> s;

    int earliest[k] = {};
    int latest[k] = {};

    int tmp = 0;
    for(int i=0;i<n;++i)
    {
        if(s[i] == 'o')
        {
            earliest[tmp] = i;
            tmp++;
            i += c;
            if(tmp == k) break;
        }
    }

    tmp = k-1;
    for(int i=n-1;i>=0;--i)
    {
        if(s[i] == 'o')
        {
            latest[tmp] = i;
            tmp--;
            i -= c;
            if(tmp == -1) break;
        }
    }
    
    for(int i=0;i<k;++i)
    {
        if(earliest[i] == latest[i]) cout << earliest[i] + 1 << endl;
    }
}