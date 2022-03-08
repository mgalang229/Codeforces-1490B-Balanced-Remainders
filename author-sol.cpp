#include <bits/stdc++.h>
using namespace std;

void test_case() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> counter(3, 0);
	for(int x = 0; x <= 2; x++) {
		for(int i = 0; i < n; i++) {
			if(a[i] % 3 == x) {
				counter[x]++; // frequency of the remainders of 3
			}
		}
	}
	auto get_min = [](vector<int> vec) {
		return *min_element(vec.begin(), vec.end()); // find minimum value
	};
	int res = 0;
	while(get_min(counter) != n / 3) {
		for(int i = 0; i < 3; i++) {
			if(counter[i] > n / 3) { // choose the frequency where it is > n / 3
				res++;
				counter[i]--; // decrease the frequency
				counter[(i+1)%3]++; // increase the frequency of the next remainder
			}
		}
	}
	// note: by doing this, we are effectively distributing the excess value to the others
	cout << res << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		test_case();
	}
}

