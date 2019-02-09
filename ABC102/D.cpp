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

ll diff(ll a, ll b, ll c, ll d)
{
    ll mini = min(min(min(a,b),c), d);
    ll maxi = max(max(max(a,b), c), d);
    return abs(mini - maxi);
}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    vector<ll> partition;
    cin >> n;
    ll arr[n];
    ll sum = 0;
    for(int i=0;i<n;++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    dump(sum);
    double ideal = (double)sum / 4;
    int coeff = std::ceil((double)(n - 1) / 3);
    vector<int> partitions;
    vector<ll> sums;
    for(int i=1;i<=3;++i)
    {
        partitions.push_back(coeff * i - 1);
        sums.push_back(0);
        dump(partitions[i-1]);
    }
    sums.push_back(0);
    int counter = 0;
    for(int i=0;i<n;++i)
    {
        sums[counter] += arr[i];
        if(partitions[counter] == i)
        {
            counter++;
        }
    }
    //for(int i=0;i<sums.size();++i) dump(sums[i]);
    while(true)
    {
        for(int i=0;i<sums.size();++i)
        {
            dump(sums[i]);
        }
        cout << "=====" << endl;
        bool cont = false;
        for(int i=0;i<3;++i)
        {
            ll current_diff_abs = diff(sums[0], sums[1], sums[2], sums[3]);
            dump(current_diff_abs);
            // moving forward
            if(partitions[i] != 0)
            {
                sums[i] -= arr[partitions[i]];
                sums[i+1] += arr[partitions[i]];
                ll next_diff_abs = diff(sums[0], sums[1], sums[2], sums[3]);
                dump(next_diff_abs);
                if(current_diff_abs < next_diff_abs)
                {
                    sums[i] += arr[partitions[i]];
                    sums[i+1] -= arr[partitions[i]];
                }
                else
                {
                    partitions[i]--;
                    cont = true;
                }
            }

            current_diff_abs = diff(sums[0], sums[1], sums[2], sums[3]);
            if(partitions[i] != (n - 2))
            {
                sums[i] += arr[partitions[i] + 1];
                sums[i+1] -= arr[partitions[i] + 1];
                ll next_diff_abs = diff(sums[0], sums[1], sums[2], sums[3]);
                if(current_diff_abs < next_diff_abs)
                {
                    sums[i] -= arr[partitions[i] + 1];
                    sums[i+1] += arr[partitions[i] + 1];
                }
                else
                {
                    partitions[i]++;
                    cont = true;
                }
            }
        }

        if(!cont) break;
    }

    cout << diff(sums[0], sums[1], sums[2], sums[3]) << endl;
}