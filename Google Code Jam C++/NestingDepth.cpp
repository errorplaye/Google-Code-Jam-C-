#include "headerVonAllem.h"
#include <iostream>

using namespace std;

int nestingDepth() {
    // faster inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    for (int t = 1; t <= test; t++) {
        string inp;
        string res;
        cin >> inp;
        inp = "0" + inp;

        inp.append("0");
        for (unsigned int i = 0; i < (inp.length())-1; ++i) {
            res.append(1, inp.at(i));
            int dies = int(inp.at(i));
            int nachst = int(inp.at(i + 1));

            if (dies > nachst) {
                res.append(dies - nachst, ')');
            }
            else if (dies < nachst) {
                res.append(nachst - dies, '(');
            }
                
        }
        res.erase(0, 1);
        cout << "Case #" << t << ": " << res << endl;

    }



	return 0;
}
