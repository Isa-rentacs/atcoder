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

bool isExponential[1001];
int main(){
    std::ios::sync_with_stdio(false);
    
    isExponential[1] = true;
    for(int i=2;i<=1000;++i)
    {
        int exp = 2;
        int tmp = pow(i, exp);

        while(tmp <= 1000)
        {
            isExponential[tmp] = true;
            exp++;
            tmp = pow(i, exp);
        }
    }

    int x;
    cin >> x;
    for(int i=x; i>=0;--i)
    {
        if(isExponential[i])
        {
            cout << i << endl;
            break;
        }
    }
}