#include "headerVonAllem.h"
#include <iostream>
#include <string>


using namespace std;


int ownWay() {
    // faster inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    for (int t = 1; t <= test; t++) {

        int num;
        string ly;
        string res;
        cin >> num;
        cin >> ly;

        for (int i = 0; i < ly.length(); i++) {

            if (ly.at(i) == 'E') {
                res.append("S");
            }
            else {
                res.append("E");

            }



        }



        cout << "Case #" << t << ": " << res << endl;


    }
    return 0;
	
}