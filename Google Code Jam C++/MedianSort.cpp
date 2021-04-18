#include "headerVonAllem.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <cassert>


//#include <bits/stdc++.h>
using namespace std;



int quali1() {


        // faster inputs
        //ios_base::sync_with_stdio(false);
        //cin.tie(NULL);
        //cout.tie(NULL);


        int test, N, Q;
        cin >> test >> N >> Q;
        //cin >> N;
        //cin >> Q;
        //cout << "check1";
        for (int t = 1; t <= test; t++) {
            vector<int> res;

            res.push_back(1);
            res.push_back(2);

            for (int a = 3; a <= N; a++) {

                int i = 0;
                while (i < res.size() - 1) {
                    fflush(stdout);
                    cout << res[i] << " " << res[i + 1] << " " << a << "\n";

                    int answer;
                    cin >> answer;

                    if (answer == -1) {
                        return 0;
                    }
                    else if (answer == a) {
                        res.insert(res.begin() + i + 1, a);
                        break;
                    }
                    else if (answer == res[0]) {
                        res.insert(res.begin(), a);
                        break;
                    }
                    else if (i == res.size() - 2) {
                        res.push_back(a);
                        break;
                    }

                    i++;
                }





            }

            string ret = "";

            for (int i = 0; i < N - 1; i++) {
                ret.append(to_string(res[i]));
                ret.append(" ");
            }
            ret.append(to_string(res[N - 1]));

            ret += "\n";
            cout << ret;
            int CORRECT;
            cin >> CORRECT;
            assert(CORRECT != -1);

            //cout << "Case #" << t << ": " << ret << endl;


        }
        return 0;

    

}