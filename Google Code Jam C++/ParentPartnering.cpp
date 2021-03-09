#include "headerVonAllem.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class job {
public:
    int start;
    int end;
    int index;
    string who;
    job() {
        index = 0;
        start = 0;
        end = 0;
        who = "";
    }

};

bool mycomp1(job a, job b)
{
    if (a.start < b.start)
        return true;
    else if (a.start > b.start)
        return false;
    else
        return false;
}
bool mycomp2(job a, job b)
{
    if (a.index < b.index)
        return true;
    else if (a.index > b.index)
        return false;
    else
        return false;
}


int parentPartnering() {
    // faster inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    for (int t = 1; t <= test; t++) {
        int num;
        cin >> num;

        vector<job> todo(num);
        
/*
        for (int i = 0; i < num; i++) {
            cin >> todo[i][i];
            cin >> todo[i][i+1];
        }
        sort(todo.begin(), todo.end());

        for (int i = 0; i < num; i++) {
            cout<< todo[i][i];
            cout<< todo[i][i + 1];
        }

        vector<vector<int>> cam(num, vector<int>(num+1));
        vector<vector<int>> jam(num, vector<int>(num+1));
        vector<string> retu(num);
        int cami = 0;
        int jami = 0;
        string res = "";
        bool flag = false;

        for (int i = 0; i < num; i++) {
            if (flag == false) {
                if (cami == 0) {
                    cam[cami][0] = todo[i][i];
                    cam[cami][1] = todo[i][i+1];
                    cami++;
                    //res = res + "C";
                    for (int a = 0; a < num; a++) {
                        if (todo[i][a] != 0) {
                            retu[a] = "C";
                            cout << a;
                            break;
                        }
                    }
                }
                else if (cam[cami-1][1] > todo[i][i]) {
                    //give to jam
                    if (jami == 0) {
                        jam[jami][0] = todo[i][i];
                        jam[jami][1] = todo[i][i+1];
                        jami++;
                        //res = res + "J";
                        for (int a = 0; a < num; a++) {
                            if (todo[i][a] != 0) {
                                retu[a] = "J";
                                cout << a;
                                break;
                            }
                        }
                    }
                    else if (jam[jami-1][1] <= todo[i][i]) {
                        jam[jami][0] = todo[i][i];
                        jam[jami][1] = todo[i][i+1];
                        jami++;
                        //res = res + "J";
                        for (int a = 0; a < num; a++) {
                            if (todo[i][a] != 0) {
                                retu[a] = "J";
                                cout << a;
                                break;
                            }
                        }
                    }
                    else {
                        flag = true;
                    }
                }
                else {
                    cam[cami][0] = todo[i][i];
                    cam[cami][1] = todo[i][i+1];
                    cami++;
                    //res = res + "C";
                    for (int a = 0; a < num; a++) {
                        if (todo[i][a] != 0) {
                            retu[a] = "C";
                            cout << a;
                            break;
                        }
                    }
                }
            }

        }

        for (int b = 0; b < num; b++) {
            res = res + retu[b];
        }

        */
/*
        int camEndInd = -1;
        int jamEndInd = -1;
        int smallestNextInd = 0;
        int biggestInd = 0;
        int biggestLast = -1;
        string res = "";
        bool flag = false;
        vector<string> retu(num);

        for (int i = 0; i < num; i++) {
            cin >> todo[i][0];
            cin >> todo[i][1];
        }

        for (int a = 0; a < num; a++) {
            if (todo[a][0] > todo[biggestInd][0]) {
                biggestInd = a; // ausgehen keine zwei gleichen startzeiten
            }

        }

        for (int i = 0; i < num; i++) {

            


            if (flag == false) {

                smallestNextInd = biggestInd;

                for (int a = 0; a < num; a++) {
                    if (todo[a][0] < todo[smallestNextInd][0] && todo[a][0] > biggestLast) {
                        smallestNextInd = a; // ausgehen keine zwei gleichen startzeiten
                    }

                }

                cout << todo[smallestNextInd][0] << " " << todo[smallestNextInd][1] << endl;

                if (camEndInd == -1) {
                    camEndInd = smallestNextInd;
                    retu[smallestNextInd] = "C";

                }
                else if (todo[camEndInd][1] > todo[smallestNextInd][0]) {
                    //give to jam
                    if (jamEndInd == -1) {
                        jamEndInd = smallestNextInd;
                        retu[smallestNextInd] = "J";
                        //res = res + "J";

                    }
                    else if (todo[jamEndInd][1] <= todo[smallestNextInd][0]) {
                        jamEndInd = smallestNextInd;
                        retu[smallestNextInd] = "J";
                        //res = res + "J";

                    }
                    else {
                        cout << i << endl;
                        flag = true;
                    }
                }
                else {
                    camEndInd = smallestNextInd;
                    retu[smallestNextInd] = "C";
                    //res = res + "C";
                }

                biggestLast = todo[smallestNextInd][0];
                
            }
            

        }
        
*/
        
        int camLast = -1;
        int jamLast = -1;
        string res = "";
        bool flag = false;
    

        for (int i = 0; i < num; i++) {
            cin >> (todo[i].start);
            cin >> (todo[i].end);
            todo[i].index = i;
        }
        sort(todo.begin(), todo.end(), mycomp1);

        for (int i = 0; i < num; i++) {
            if (flag == false) {
                if (camLast == -1) {
                    camLast = todo[i].end;
                    todo[i].who = "C";
                }
                else if (camLast > todo[i].start) {
                    //give to jam
                    if (jamLast == -1) {
                        jamLast = todo[i].end;
                        todo[i].who = "J";
                    }
                    else if (jamLast <= todo[i].start) {
                        jamLast = todo[i].end;
                        todo[i].who = "J";
                    }
                    else {
                        flag = true;
                    }
                }
                else {
                    camLast = todo[i].end;
                    todo[i].who = "C";
                }
            }
        }
        sort(todo.begin(), todo.end(), mycomp2);

        for (int b = 0; b < num; b++) {
            res = res + todo[b].who;
        }

        if (flag == false) {
            cout << "Case #" << t << ": " << res << endl;
        }
        else {
            cout << "Case #" << t << ": IMPOSSIBLE" <<  endl;
        }


    }
    return 0;
}