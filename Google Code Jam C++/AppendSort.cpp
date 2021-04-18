#include "headerVonAllem.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cassert>



//#include <bits/stdc++.h>
using namespace std;

int appendSort() {
    // faster inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int test;
    cin >> test;

    for (int t = 1; t <= test; t++) {

		int N;
		cin >> N;
		
		int ret = 0;


		vector<string> A(N); for (auto& a : A) cin >> a;
		string str1 = A[0];


		for (int i = 1; i < N; i++) {
			// increment str1, because strictly increasing
			for (int x = int(str1.size()) - 1; true; x--) {
				if (x < 0) {
					str1.insert(str1.begin(), '1');
					break;
				}
				else if (str1[x] == '9') {
					str1[x] = '0';
					continue;
				}
				else {
					str1[x]++;
					break;
				}
			}


			string str2 = A[i];
			if (str2.size() > str1.size()) {
				// do nothing
				str1 = str2;
				continue;
			}
			else {
				// try to match it in size
				assert(str1.size() >= str2.size());
				for (int a = 0; true; a++) {
					if (a == int(str2.size())) {
						// the prefixes match
						ret += int(str1.size() - str2.size());
						str2 = str1;
						break;
					}
					else if (str2[a] < str1[a]) {
						// it's bad
						ret += int(str1.size() - str2.size() + 1);
						str2.insert(str2.end(), str1.size() - str2.size() + 1, '0');
						break;
					}
					else if (str2[a] > str1[a]) {
						// it's fine, we can just insert 0's
						ret += int(str1.size() - str2.size());
						str2.insert(str2.end(), str1.size() - str2.size(), '0');
						break;
					}
					else {
						continue;
					}
				}
				str1 = str2;
			}
		}







    cout << "Case #" << t << ": " << ret << endl;
}

return 0;

}