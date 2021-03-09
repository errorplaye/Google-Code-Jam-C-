//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector> 

#include "headerVonAllem.h"
using namespace std;

//int main()
//{
int vestigium(){
    //faster inputs
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/

    int test;
    cin >> test;

    for (int t = 1; t <= test; t++) {
        int n;
        cin >> n;

        vector<vector<int>> arr(n, vector<int>(n));

        int trace = 0;

        int frow = 0;

        for (int a = 0; a < n; a++) {

            map<int, int> hmap;
            bool check = false;
            for (int b = 0; b < n; b++) {
                cin >> arr[a][b];

                if (a == b) {
                    trace += arr[a][b];
                }
                //check row
                if (check == false && hmap.find(arr[a][b]) != hmap.end()) {
                    frow++;
                    check = true;
                }
                if (check == false) {
                    hmap[arr[a][b]]++;
                }
            }
        }

        // check col
        int fcol = 0;
        for (int a = 0; a < n; a++) {
            map<int, int> hmap;
            bool check = false;
            for (int b = 0; b < n; b++) {

                if (check == false && hmap.find(arr[b][a]) != hmap.end()) {
                    fcol++;
                    check = true;
                    break;
                }
                if (check == false)
                    hmap[arr[b][a]]++;
            }
        }
        cout << "Case #" << t << ": " << trace << " " << frow << " " << fcol << endl;
    }

    return 0;
    }
//}