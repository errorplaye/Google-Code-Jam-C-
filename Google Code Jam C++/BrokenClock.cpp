#include "headerVonAllem.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

//#include <bits/stdc++.h>
using namespace std;


#define shift(x) #x << " = " << x
#define shift2(x, y) shift(x) << ", " << shift(y)
#define shift3(x, y, z) shift2(x, y) << ", " << shift(z)
#define shift4(w, x, y, z) shift3(w, x, y) << ", " << shift(z)


constexpr long long e = 1000000000;
constexpr long long full = 360 * 12 * 10000000000;
constexpr long long ho = full / 12;

long long norm(long long x) {
	return ((x % full) + full) % full;
}

int brokenClock() {
	// faster inputs
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int test;
	cin >> test;


	for (int t = 1; t <= test; t++) {
		
		vector<long long> vec(3);
		for (int i = 0; i < 3; i++) cin >> vec[i];
		sort(begin(vec), end(vec));

		do {
			long long A = vec[0];
			long long B = vec[1];
			long long C = vec[2];

			bool ok = false;
			//fora(da, 2) {
				//if (ok) break;
			for(int rev = 0; rev < 12*60; rev++) {
				//ll z = da * full;
				long long y = rev * (full);
				long long x = full * (rev / 60);
				//long long x = ho * (((rev * ho) / 60) / ho);
				if ((B + x - A) % 11 != 0) continue;
				long long n = (B + x - A) / 11;
				//if (n < 0 || n > full) continue;
				n = norm(n);
				long long k = A - n;
				//long long minutes = n / (e * 60);
				/*if (rev == 30) {
					cout << shift2(n, k) << endl;
					cout << shift2(minutes, rev) << endl;
					cout << shift4(A, B, C, (B + x - A) % 11) << endl;
					cout << shift2(B + x, 12 * n + k) << endl;
					cout << shift2(C + y, 720 * n + k) << endl;
				}*/
				//if (minutes != rev) continue;
				if (norm(B + x) != norm(12 * n + k)) continue;
				if (norm(C + y) != norm(720 * n + k)) continue;
				//cout << shift4(x, y, n, k) << endl;
				cout << "Case #" << t << ": " <<
					(n / (e * 60 * 60)) << " " <<
					((n / (e * 60)) % 60) << " " <<
					((n / e) % 60) << " " <<
					n % e << endl;
				ok = true;
				break;
				//}
			}
			if (ok) break;
		} while (next_permutation(begin(vec), end(vec)));



		//cout << "Case #" << t << ": " << ret << endl;
	}

	return 0;

}