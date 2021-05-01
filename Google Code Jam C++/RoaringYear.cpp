#include "headerVonAllem.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


//#include <bits/stdc++.h>
using namespace std;

/*
int pow10(int inp) {
	int count = 0;
	while (inp > 0) {
		inp /= 10;
		count++;
	}
	return count;
}


int roaringYear() {
    // faster inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    for (int t = 1; t <= test; t++) {

		int inp;
		cin >> inp;
		int ret = 100000000;
		for (int y = 1; y <= 1000; y++) {
			int k = 0;

			int r = y;
			int curr = 0;
			while (curr <= 1 || k <= inp) {

				k = k * pow(10, pow10(r)) + r;
				r++;
				curr++;
			}
			ret = min(ret, k);
		}
		



        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}

*/


int roaringYear() {
	// faster inputs
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;

	vector<int> all;
	
	int num = 0;
	for (int i = 1; i <= 999; i++) {
		num = i;
		for(int b = i+1; b <=1000; b++){

			if (b < 10) num = num * 10 + b;
			else if (b < 100) num = num * 100 + b;
			else if (b < 1000) num = num * 1000 + b;
			else num = num * 10000 + b;
			if (num > 1234567) {
				//cout << num << endl;
				break;
			}
			
			
			all.push_back(num);
			
		}

	
	
	}
	
	cout << all.size() << endl;
	sort(all.begin(), all.end());
	
	

	sort(all.begin(), all.end());
	//cout << *(all.end()-1);
	for (int i = 0; i < all.size(); i++) {
		cout << all[i] << endl;
	}

	for (int t = 1; t <= test; t++) {
		int current;
		cin >> current;
		
		int ind = 0;
		while (all[ind] <= current) {
			ind++;
		}
		

		cout << "Case #" << t << ": " << all[ind] << endl;
	}

	return 0;

}