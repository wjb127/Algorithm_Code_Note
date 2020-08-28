#include <iostream>
#include <algorithm>
using namespace std;
int n, d, a[9], s, mx;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	do {
		s = 0;
		for (int i = 1; i < n; i++) 
			s += abs(a[i] - a[i - 1]);
		mx = max(mx, s);
	} while (next_permutation(a, a + n));
	cout << mx << '\n';
	return 0;
}
