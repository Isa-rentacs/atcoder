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
    int max_pairs = (n-2) * (n-1) / 2; 
    if(k > max_pairs){
        cout << -1 << endl;
        return 0;
    }
    cout << (n-1) + max_pairs - k << endl;
    for(int i=0;i<n-1;++i)
    {
        cout << "1 " << i+2 << endl;
    }

    int src = 2;
    int dst = 3;
    for(int i=0;i<(max_pairs - k); ++i)
    {
        cout << src << " " << dst << endl;
        if(dst == n)
        {
            src++;
            dst = src + 1;
        }
        else
        {
            dst++;
        }
    }
}