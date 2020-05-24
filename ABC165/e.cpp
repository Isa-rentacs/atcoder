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
    int n, m;
    cin >> n >> m;
    if(n%2 == 1)
    {
        int s = 1;
        int e = n;
        for(int i=0;i<m;++i)
        {
            cout << s << " " << e << endl;
            s++;
            e--;
        }
    }else
    {
        int s = 1;
        int e = n;
        for(int i=0;i<m;++i)
        {
            if(i == (m - 1))
            {
                cout << s << " " << e - 1 << endl;
            }
            else
            {
                cout << s << " " <<  e << endl;
            }
            s++;
            e--;
        }
    }
}