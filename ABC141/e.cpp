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
#define hash_type pair<long long, long long>
#define int_type long long
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

struct RollingHash {

    int_type base1;
    int_type base2;
    int_type mod1;
    int_type mod2;
    vector<int_type> hash1;
    vector<int_type> hash2;
    vector<int_type> pow1;
    vector<int_type> pow2;

    RollingHash() : base1(1009), base2(1007), mod1(1000000007), mod2(1000000009) {}

    void init(const string &s) {
        int n = s.size();

        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        pow1.assign(n+1,1);
        pow2.assign(n+1,1);

        for(int i=0;i<n;i++) {
            hash1[i+1] = (hash1[i]+s[i]) * base1 % mod1;
            hash2[i+1] = (hash2[i]+s[i]) * base2 % mod2;
            pow1[i+1] = pow1[i] * base1 % mod1;
            pow2[i+1] = pow2[i] * base2 % mod2;
        }
    }

    hash_type get(int l,int r) {
        int_type t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
        int_type t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
        return make_pair(t1, t2);
    }

    hash_type concat(hash_type h1, hash_type h2, int h2_len) {
        return make_pair((h1.first*pow1[h2_len]+h2.first)%mod1, (h1.second*pow2[h2_len]+h2.second)%mod2);
    }

};

vector<int> zalgo(string& s)
{
    int len = s.length();
    vector<int> ret(len);
    ret[0] = len;
    int start = 1;
    int length = 0;
    while(start < len)
    {
        while(start + length < len && s[length] == s[start+length]) ++length;
        ret[start] = length;
        if(length == 0) 
        {
            ++start;
            continue;
        }

        int offset = 1;
        while(start + offset < len && offset + ret[offset] < length)
        {
            ret[start + offset] = ret[offset];
            ++offset;
        }
        start += offset;
        length -= offset;
    }

    return ret;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    int ret = 0;
    for(int i=0;i<n;++i)
    {
        string query = s.substr(i);
        vector<int> zarray = zalgo(query);

        for(int j=0;j<zarray.size();++j)
        {
            if(zarray[j] <= j)
            {
                ret = max(ret, zarray[j]);
            }
        }
    }
    cout << ret << endl;
}