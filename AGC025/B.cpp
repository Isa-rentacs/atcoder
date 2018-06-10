#include <iostream>

using namespace std;

const int MAX_K = 300001;
bool fact_initialized = false;
long long fact[MAX_K], fact_inv[MAX_K], inv[MAX_K];

void combination_init(int mod)
{
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;

    for(int i = 2; i < MAX_K; ++i)
    {
        fact[i] = fact[i-1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fact_inv[i] = fact_inv[i-1] * inv[i] % mod;
    }
}

long long combination_mod(long long n, long long k, int mod)
{
    if (n < k || n < 0 || k < 0) return 0;
    if(!fact_initialized)
    {
        combination_init(mod);
        fact_initialized = true;
    } 
    return fact[n] * (fact_inv[k] * fact_inv[n-k] % mod) % mod;
}

int main()
{
    long long n, a, b;
    long long k;
    long long mod = 998244353;
    long long ret = 0;
    cin >> n >> a >> b >> k;
    
    if (k == 0)
    {
        ret = 1;
    }
    else
    {
        for(long long i=0; i <= n; ++i)
        {
            if (((k - i * a) % b) == 0) // ax + by = n
            {
                ret = (ret + combination_mod(n, i, mod) * combination_mod(n, (k - i * a) / b, mod) % mod) % mod;
            }
        }
    }
    cout << ret % mod << endl;
}