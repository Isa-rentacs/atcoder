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
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }
    vector<int> heads;
    heads.push_back(-1); //guard
    for(int i=n-1;i>=0;--i)
    {
        auto iter = upper_bound(heads.begin(), heads.end(), a[i]);
        if(iter == heads.end())
        {
            heads.push_back(a[i]);
        }
        else
        {
            *(iter) = a[i];
        }
    }
    cout << (heads.size() - 1) << endl;;
}