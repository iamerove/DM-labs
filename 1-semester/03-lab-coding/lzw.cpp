#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <stack>
#include <climits>


using namespace std;

typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(228);

const double EPS = 1e-7;
const double PI = acos(-1);
const int oo = INT_MAX;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp(a, b) make_pair(a, b)
#define size(a) (int)a.size()
#define f first
#define s second

void solve();

int main() {
	#ifdef HOME
		freopen("home.in", "r", stdin);
		freopen("home.out", "w", stdout);
	#else
		// freopen("censored.in", "r", stdin);
		// freopen("censored.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	#ifdef HOME
		clock_t start = clock();
	#endif

	solve();

	#ifdef HOME
		cout <<  "\n\n\nTIME: " << float(clock() - start) / CLOCKS_PER_SEC << endl;
		// system("pause");
	#endif

	exit(0);
}

void solve() {
	string s;
	cin >> s;

	map<string, int> dictionary;
	string tmp = "#";
	for (char c = 'a'; c <= 'z'; c++) {
		tmp[0] = c;
		dictionary[tmp] = c - 'a';
	}

	string buffer = "#";
	buffer[0] = s[0];
	for (int i = 1; i < size(s); i++) {
		buffer += "#";
		buffer.back() = s[i];
		if (!dictionary.count(buffer)) {
			cout << dictionary[buffer.substr(0, size(buffer) - 1)] << ' ';
			dictionary[buffer] = size(dictionary);
			buffer = "#";
			buffer[0] = s[i];
		}
	}

	cout << dictionary[buffer];
}
