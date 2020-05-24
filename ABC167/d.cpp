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
    ll n, k, orig_k;
    cin >> n >> k;
    orig_k = k;
    int dst[n] = {};
    int hist[n] = {};
    for(int i=0;i<n;++i)
    {
        cin >> dst[i];
        dst[i]--;
        hist[i] = -1;
    }   
    int current = 0;
    int step = 0;
    while(true)
    {
        if(k == 0)
        {
            cout << (current + 1) << endl;
            break;
        }
        hist[current] = step;
        int next = dst[current];
        if(hist[next] != -1)
        {
            // loop detected
            int cycle_len = (step + 1) - hist[next];
            orig_k -= hist[next];
            orig_k = orig_k % cycle_len;
            current = next;
            while(orig_k > 0)
            {
                current = dst[current];
                orig_k--;
            }
            cout << (current + 1) << endl;
            break;
        }

        current = next;
        ++step;
        --k;
    }    
}