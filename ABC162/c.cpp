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

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }

    return gcd(b, a%b);
}

int gcd(int a, int b, int c)
{
    return gcd(gcd(a,b), c);
}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll acc = 0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int k=1;k<=n;++k)
            {
                acc += gcd(i,j,k);
            }
        }
    }
    cout << acc << endl;
}