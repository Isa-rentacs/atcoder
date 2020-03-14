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

class BIT{
public:
    int *p;
    int num;
    BIT(int arg){
        p = new int[arg+1];
        for(int i=0;i<arg+1;i++) p[i] = 0;
        num = arg;
    }
    
    //return sum of p[1] ... p[arg]
    int sum(int arg){
        int ret=0;
        while(arg > 0){
            ret += p[arg];
            arg -= arg & -arg;
        }
        return ret;
    }

    //add value to index-th node
    void add(int index, int value){
        while(index <= num){
            p[index] += value;
            index += index & -index;
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    BIT *bit[26];
    int n, q, t;
    char l, r;
    string s;
    cin >> n >> s >> q;
    for(int i=0;i<26;++i)
    {
        bit[i] = new BIT(n);
    }

    for(int i=0;i<s.length();++i)
    {
        char c = s[i] - 'a';
        bit[c]->add(i+1, 1);
    }

    for(int i=0;i<q;++i)
    {
        cin >> t;
        if(t == 1)
        {
            int ind;
            char c, before, after;
            cin >> ind >> c;
            if(s[ind-1] == c) continue;
            bit[s[ind-1] - 'a']->add(ind, -1);
            bit[c - 'a']->add(ind, 1);            
            s[ind-1] = c;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int count = 0;
            for(int i=0;i<26;++i)
            {
                if(bit[i]->sum(r) - bit[i]->sum(l-1) > 0)
                {

                    count++;
                }
            }
            cout << count << endl;
        }
        
    }
}