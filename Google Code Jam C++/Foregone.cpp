#include "headerVonAllem.h"
#include <iostream>
#include <math.h>

using namespace std;


int foregone() {
    // faster inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    for (int t = 1; t <= test; t++) {
       
        int num;
        cin >> num;

        int a = 0;
        int b = 0;
        int power = 0;

        while (num > 0) {
           
            if (num % 10 == 4) {
                a += 2 * pow(10, power);
                b += 2 * pow(10, power);
            }
            else {
                a += (num%10) * pow(10, power);
            }

            power++;
            num /= 10;
        }



        cout << "Case #" << t << ": " << a << " " << b << endl;

    }
    return 0;
}