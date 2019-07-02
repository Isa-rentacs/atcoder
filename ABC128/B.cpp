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

class Restaurant{
 public:
    string name;
    int score;
    int index;
    bool operator<(const Restaurant& rhs) const
    {
        int comparison = this->name.compare(rhs.name);
        if(comparison == 0)
        {
            return this->score > rhs.score;
        }
        else
        {
            return comparison < 0 ? true : false;
        }
    }
};



int main(){
    std::ios::sync_with_stdio(false);
    int n, p;
    string s;
    cin >> n;
    vector<Restaurant> vr;
    for(int i=0;i<n;++i)
    {
        Restaurant r;
        cin >> s >> p;

        r.name = s;
        r.score = p;
        r.index = i + 1;
        vr.push_back(r);
    }

    sort(vr.begin(), vr.end());

    for(int i=0;i<n;++i)
    {
        cout << vr[i].index << endl;
    }
}