/*
 * Source: https://codeforces.com/blog/entry/68809
 */
#ifndef DEBUG_HPP
#define DEBUG_HPP
#include <bits/stdc++.h>

#define UNUSED [[maybe_unused]]

using namespace std;

UNUSED static void __print(int x) { cerr << x; }
UNUSED static void __print(long x) { cerr << x; }
UNUSED static void __print(long long x) { cerr << x; }
UNUSED static void __print(unsigned x) { cerr << x; }
UNUSED static void __print(unsigned long x) { cerr << x; }
UNUSED static void __print(unsigned long long x) { cerr << x; }
UNUSED static void __print(float x) { cerr << x; }
UNUSED static void __print(double x) { cerr << x; }
UNUSED static void __print(long double x) { cerr << x; }
UNUSED static void __print(char x) { cerr << '\'' << x << '\''; }
UNUSED static void __print(const char *x) { cerr << '\"' << x << '\"'; }
UNUSED static void __print(const string &x) { cerr << '\"' << x << '\"'; }
UNUSED static void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
UNUSED static void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(...)                                                             \
  cerr << "[" << #__VA_ARGS__ << "] = [";                                      \
  _print(__VA_ARGS__)
#else
#define debug(...)
#endif
#endif // DEBUG_HPP
