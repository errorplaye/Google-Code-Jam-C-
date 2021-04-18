#include "headerVonAllem.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>


//#include <bits/stdc++.h>
using namespace std;
vector<int> reverse(vector<int> vec, int indexAn, int indexXS) {
    int temp;

    while (indexXS >indexAn) { 
        temp = vec[indexAn];
        vec[indexAn] = vec[indexXS];
        vec[indexXS] = temp;
        indexAn++;
        --indexXS;
    }

    return vec;
}

int updateXS(vector<int> vec, int indexAn) {
    int indexXs = vec.size() - 1;
    for (int a = indexAn + 1; a < vec.size(); a++) {
        if (vec[indexXs] > vec[a]) {
            indexXs = a;
        }
    }
    return indexXs;
}

int quali3() {
    // faster inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int test;
    cin >> test;
    

  

    for (int t = 1; t <= test; t++) {
        int N;
        int cost = 0;
        int indexXS = 0;;
        vector<int> vec;
        cin >> N;
        for (int a = 0; a < N; a++) {
            int inp;
            cin >> inp;
            vec.push_back(inp);
            if (inp < vec[indexXS]) {
                indexXS = a;
            }
        }

        for (int indexAn = 0; indexAn < N - 1; indexAn++) {
            vec = reverse(vec, indexAn, indexXS);
            cost += indexXS - indexAn + 1;
            indexXS = updateXS(vec, indexAn);
        
        }

        





    

        cout << "Case #" << t << ": " << cost << endl;
    }
 
    return 0;

}