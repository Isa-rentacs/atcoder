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
    ll n;
    cin >> n;
    for(ll i=1;i * (i-1) / 2 <= 100000; ++i)
    {
        if((n * 2) % i == 0 && (n * 2) / i == (i - 1))
        {
            cout << "Yes" << endl;
            ll numsets = i;
            // i = # of sets
            vector<pair<int,int>> pairs;
            for(int j=0;j<numsets;++j)
            {
                for(int k=j+1;k<numsets;++k)
                {
                    pairs.push_back(MP(j,k));
                }
            }
            cout << numsets << endl;
            vector<int> sets[numsets];
            for(int k=0;k<numsets;++k)
            {
                for(int j=0;j<pairs.size();++j)
                {
                    if(pairs[j].first == k || pairs[j].second == k)
                    {
                        sets[k].push_back(j+1);
                    }
                }
                cout <<  sets[k].size() << " ";
                for(int j=0;j<sets[k].size();++j)
                {
                    cout << sets[k][j] << " \n"[j == (sets[k].size() - 1)];
                }
            }

            
            return 0;
        }
    }
    cout << "No" << endl;
}