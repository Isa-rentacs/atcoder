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
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    int orig_hapiness = 0;
    int r_clusters = 0;
    int l_clusters = 0;

    char c = str[0];
    for(int i=1;i<n;++i)
    {
        if(str[i] == c)
        {
            orig_hapiness++;
        }
        else
        {
            if(c == 'R')
            {
                r_clusters++;
            }
            else
            {
                l_clusters++;
            }
            c = str[i];
        }
    }
    if(c == 'R')
    {
        r_clusters++;
    }
    else
    {
        l_clusters++;
    }
    // cerr << orig_hapiness << endl;
    // cerr << r_clusters << endl;
    // cerr << l_clusters << endl;

    if (r_clusters == 0 || l_clusters == 0)
    {
        cout << orig_hapiness << endl;
    }
    else if(r_clusters == 1 || l_clusters == 1)
    {
        cout << n - 1 << endl;
    }
    else
    {
        cout << min(n-1, orig_hapiness + 2 * k) << endl;
    }
    
}