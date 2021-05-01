#include "headerVonAllem.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


//#include <bits/stdc++.h>
using namespace std;


int closestPick() {
    // faster inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    for (int t = 1; t <= test; t++) {
		
		int n, k;
		cin >> n >> k;
		int vec[30];

		for (int i = 0; i < n; i++)
			cin >> vec[i];
		sort(vec, vec + n);

		int maxi = max(vec[0] - 1, k - vec[n - 1]);

		int x = vec[0] - 1;
		int y = k - vec[n - 1];
		if (x < y)
			swap(x, y);

		for (int i = 0; i < n - 1; i++) {
			maxi = max(maxi, vec[i + 1] - vec[i] - 1);

			int temp = ((vec[i + 1] - vec[i] - 1) + 1) / 2;
			if (temp > y)
				y = temp;
			if (x < y)
				swap(x, y);
		}
		double ret = 1.0 * max((x + y), maxi) / k;

        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}

