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

// xxxx
//   yyyy
int max_overlap(string x, string y)
{
    int x_len = x.length();
    int y_len = y.length();
    int len = min(x.length(), y.length());

    int ret = 0;
    bool same = true;
    for(int i=1;i<=len;++i)
    {
        // suffix of x
        string suf_x = x.substr(x_len - i, i);
        string pre_y = y.substr(0, i);
        bool same = true;
        for(int j=0;j<i;++j)
        {
            if(suf_x[j] == '?' || pre_y[j] == '?') continue;
            if(suf_x[j] != pre_y[j]) 
            {
                same = false;
                break;
            }
        }

        if(same)
        {
            ret = i;
        }
    }
    return ret;
}

int main(){
    std::ios::sync_with_stdio(false);

    string a, b, c;
    cin >> a >> b >> c;
    int ab, ac, ba, bc, ca, cb;
    
    ab = max_overlap(a, b);
    ac = max_overlap(a, c);
    ba = max_overlap(b, a);
    bc = max_overlap(b, c);
    ca = max_overlap(c, a);
    cb = max_overlap(c, b);

    int ret = a.length() + b.length() + c.length();

    vector<int> cand;
    int abc, acb, bac, bca, cab, cba;
    abc = ab + bc;
    if(abc > b.length())
    {
        abc = b.length() + min(ac, (int)b.length());
    }

    acb = ac + cb;
    dump(ac)
    dump(cb)
    if(acb > c.length())
    {
        acb = c.length() + min(ab, (int)c.length());
    }

    bac = ba + ac;
    if(bac > a.length())
    {
        bac = a.length() + min(bc, (int)a.length());
    }

    bca = bc + ca;
    if(bca > c.length())
    {
        bca = c.length() + min(ba, (int)c.length());
    }

    cab = ca + ab;
    if(cab > a.length())
    {
        cab = a.length() + min(cb, (int)a.length());
    }

    cba = cb + ba;
    if(cba > b.length())
    {
        cba = b.length() + min(ca, (int)b.length());
    }

    cand.push_back(ret - abc);
    cand.push_back(ret - acb);
    cand.push_back(ret - bac);
    cand.push_back(ret - bca);
    cand.push_back(ret - cab);
    cand.push_back(ret - cba);
    dump(abc)
    dump(acb)
    dump(bac)
    dump(bca)
    dump(cab)
    dump(cba)
    sort(cand.begin(), cand.end());
    cout << cand[0] << endl;
}