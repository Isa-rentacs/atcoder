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
    ll a, b;
    cin >> a >> b;
    // f(A, B) = f(1, B) xor f(1, A-1)
    ll ret = 0;
    ll bit_a = 0;
    ll bit_b = 0;
    for(int i=0;i<40;++i)
    {
        
        if(i==0)
        {
            bit_a = ((a-1)%4 == 1 || (a-1)%4 == 2) ? 1 : 0;
            bit_b = (b%4 == 1 || b%4 == 2) ? 1 : 0;
        }
        else
        {
            ll base = 1ll << (i + 1);
            //cerr << base << endl;
            ll remain = (a-1) % base;
            if(remain >= base / 2 && (remain % 2) == 0)
            {
                bit_a |= 1ll << i;
            }

            remain = b % base;
            if(remain >= base / 2 && (remain % 2) == 0)
            {
                bit_b |= 1ll << i;
            }            
        }
        //cerr << bit_a << ' ' << bit_b << endl;
    }

    cout << (bit_a ^ bit_b) << endl;

}