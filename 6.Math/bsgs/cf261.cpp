#include <bits/stdc++.h>
using namespace std;
#define ll  long long
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll powmod(ll a, ll b, ll p) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % p;
    a = a * a % p, b >>= 1;
  }
  return res;
}
// Finds the primitive root modulo p
ll generator(ll p) {
  vector<ll> fact;
  ll phi = p - 1, n = phi;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      fact.push_back(i);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) fact.push_back(n);
  for (ll res = 2; res <= p; ++res) {
    bool ok = true;
    for (ll factor : fact) {
      if (powmod(res, phi / factor, p) == 1) {
        ok = false;
        break;
      }
    }
    if (ok) return res;
  }
  return -1;
}
ll BSGS(ll a, ll b, ll p)
{
	ll m = (ll)sqrt(p + 0.5);
	ll v = powmod(powmod(a, m, p), p-2, p);
	map<ll, ll> x;
	x[1] = 0;
	for(ll i = 1, e = 1; i < m; ++i)
	{
		e = e * a % p;
		if(!x.count(e)) x[e] = i;
	}
	for(ll i = 0; i < m; ++i)
	{
		if(x.count(b)) return i * m + x[b];
		b = b * v % p;
	}
	return -1;
}
// This program finds all numbers x such that x^k=a (mod n)
int main() {
  ll n, k, a;
  scanf("%lld %lld %lld", &n, &k, &a);
  if (a == 0) return puts("1\n0"), 0;
  ll g = generator(n);
  // Baby-step giant-step discrete logarithm algorithm
  ll any_ans = BSGS(powmod(g, k, n), a, n);

  if (any_ans == -1) return puts("0"), 0;
  // Prll all possible answers
  ll delta = (n - 1) / gcd(k, n - 1);
  vector<ll> ans;
  for (ll cur = any_ans % delta; cur < n - 1; cur += delta)
    ans.push_back(powmod(g, cur, n));
  sort(ans.begin(), ans.end());
  ll siz = ans.size();
  printf("%lld\n", siz);
  for (ll answer : ans) printf("%lld ", answer);
  return 0;
}
