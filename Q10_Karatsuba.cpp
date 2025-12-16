#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int digits(ll x)
{
    if (x == 0)
        return 1;
    int c = 0;
    while (x)
    {
        x /= 10;
        ++c;
    }
    return c;
}

ll pow10_int(int k)
{
    ll r = 1;
    while (k--)
        r *= 10;
    return r;
}

ll karatsuba(ll x, ll y)
{
    if (x < 10 || y < 10)
        return x * y;
    int dx = digits(x);
    int dy = digits(y);
    int m = max(dx, dy);
    int m2 = m / 2;
    ll p = pow10_int(m2);

    ll a = x / p;
    ll b = x % p;
    ll c = y / p;
    ll d = y % p;

    ll ac = karatsuba(a, c);
    ll bd = karatsuba(b, d);
    ll abcd = karatsuba(a + b, c + d);
    ll mid = abcd - ac - bd;

    return ac * pow10_int(2 * m2) + mid * p + bd;
}

int main()
{
    ll x, y;
    if (!(cin >> x >> y))
        return 0;
    bool neg = (x < 0) ^ (y < 0);
    ll ax = llabs(x), ay = llabs(y);
    ll prod = karatsuba(ax, ay);
    if (neg && prod != 0)
        cout << '-';
    cout << prod << '\n';
    return 0;
}