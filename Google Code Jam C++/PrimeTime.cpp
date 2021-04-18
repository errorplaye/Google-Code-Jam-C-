#include "headerVonAllem.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cassert>
#include <algorithm>



//#include <bits/stdc++.h>
using namespace std;

class two {
public:
	int first;
	int second;
	
	two() {
		first = 0;
		second = 0;
	}

};

int primeTime() {
	// faster inputs
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int test;
	cin >> test;

	for (int t = 1; t <= test; t++) {

		int N;
		cin >> N;
		//cout << "N: " << N << endl;

		vector<two> A(N);

		for (int a = 0; a < N; a++) {
			int first, second;
			cin >> first >> second;
			//cout << "first: " << first << "second: " << second << endl;
			A[a].first = first;
			A[a].second = second;
		}

		//cout << "check 1" << endl;
		int maxSum = 0;
		for (auto& a : A) maxSum += a.first * a.second;

		vector<pair<int, int>> solutions;
		vector<pair<int, int>> products;
		for (auto& a : A) {
			vector<pair<int, int>> newP;
			for (auto& p : products) {
				int product = p.first;
				int sum = p.second;
				for (int i = 0; i < a.second; i++) {
					product = product * a.first;
					sum = sum + a.first;

					if (product > maxSum - sum) break;
					if (product == maxSum - sum) solutions.push_back({ product, sum });
					newP.push_back({ product, sum });
				}
			}

			int selfProduct = 1;
			int selfSum = 0;
			for (int i = 0; i < a.second; i++) {
				selfProduct = selfProduct * a.first;
				selfSum = selfSum + a.first;


				if (selfProduct > maxSum - selfSum) break;
				if (selfProduct == maxSum - selfSum) solutions.push_back({ selfProduct, selfSum });
				newP.push_back({ selfProduct, selfSum });
			}
			for (auto& p : newP) products.push_back(p);
		}

		sort(solutions.rbegin(), solutions.rend());
		if (solutions.size()) {
			cout << "Case #" << t << ": " << solutions[0].first << endl;
		}
		else {
			cout << "Case #" << t << ": 0" << endl;
		}









		//cout << "Case #" << t << ": " << ret << endl;
	}

	return 0;

}