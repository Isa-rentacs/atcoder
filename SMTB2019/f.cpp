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

bool are_same_sign(ll a, ll b) {
    return (a / abs(a)) * (b / abs(b)) > 0;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll t[2] = {};
    ll a[2] = {};
    ll b[2] = {};
    cin >> t[0] >> t[1];
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    ll first_part_diff = t[0] * (b[0] - a[0]);
    ll second_part_diff = t[1] * (b[1] - a[1]);
    // dump(first_part_diff)
    // dump(second_part_diff)
    if(!are_same_sign(first_part_diff, second_part_diff)) {
        ll cycle_diff = first_part_diff + second_part_diff;
        dump(cycle_diff)
        if(cycle_diff == 0) {
            cout << "infinity" << endl;
        } else {
            if(are_same_sign(cycle_diff, first_part_diff)) {
                cout << 0 << endl;
            } else {
                if(first_part_diff % cycle_diff == 0)
                {
                    cout << first_part_diff / cycle_diff * -1 * 2 << endl;
                } else {
                    cout << first_part_diff / cycle_diff * -1 * 2  + 1 << endl;
                }
            }
        }
        
    } else {
        cout << 0 << endl;
    }
}