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
long long a[200001];

void binary_dump(long long x)
{
    while(x > 1)
    {
        cout << (x % 2);
        x /= 2;
    }
    cout << x;
    cout << endl;
}

int main(){
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
        // cout << i << (i < 10 ? " " : "") <<" : ";
        // binary_dump(a[i]);
    }

    long long xor_value = 0;
    long long sum = 0;
    long long continuous_length = 0;
    long long ans = 0;
    long long l = 0;
    for(long long i=0;i<n;++i)
    {
        if((xor_value ^ a[i]) != (sum + a[i]))
        {
            // cout << "(" << l << ", " << (i - 1) << ")" << endl;
            // dump(continuous_length);
            //ans += (continuous_length + 1) * (continuous_length) / 2 - continuous_length;
            while((xor_value ^ a[i]) != (sum + a[i]))
            {
                xor_value = xor_value ^ a[l];
                sum -= a[l];
                ++l;
            }
            ans += (continuous_length + 1) * (continuous_length) / 2 - ((i - l) * (i - l - 1) / 2) - continuous_length;
            xor_value = xor_value ^ a[i];
            sum += a[i];
            continuous_length = i - l + 1;
            // dump(i);
            // dump(l);
        }
        else
        {
            // binary_dump(a[i]);
            continuous_length++;
            xor_value = xor_value ^ a[i];
            sum += a[i];
        }
    }

    ans += (continuous_length + 1) * (continuous_length) / 2 - continuous_length;

    cout << ans + n << endl;
}