#include "headerVonAllem.h"
#include <iostream>
#include <string>


//#include <bits/stdc++.h>
using namespace std;


int quali2() {
    // faster inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    for (int t = 1; t <= test; t++) {
        int x, y;
        string todo;
        cin >> x;
        cin >> y;
        cin >> todo;

        
        int mincost = 0;



            //anfang und ende '?' löschen
            int a = 0;
            while (todo[a] == '?' && a < todo.length()-1) {
                a++;
            }
            //cout << "check1";
            if (a != todo.length() - 1) {


                todo.erase(todo.begin(), todo.begin() + a);
                a = todo.length() - 1;
                while (todo[a] == '?') {
                    a--;
                }
                todo.erase(todo.begin() + a + 1, todo.end());
                //cout << todo;

                for (int i = 0; i < todo.length() - 1; i++) {

                    //cout << i << endl;


                    if (todo[i] == 'J' && todo[i + 1] == 'C') {
                        //cout << "check1";
                        mincost += y; // bei fragezeichen gegen vorne und hinten kosten berechnen           

                    }
                    else if (todo[i] == 'C' && todo[i + 1] == 'J') {
                        //cout << "check2 " << i;
                        mincost += x; // bei fragezeichen gegen vorne und hinten kosten berechnen

                    }

                    else if (todo[i] == '?') { // annahme alle fragezeichen mehr als 1 werden gleich dem buchstabe j+1
                        /*
                        int costc = 0;
                        int costj = 0;
                        int j = i; // j zeigt auf ? mit 1. buchstabe; i ist erstes ?
                        while (todo[j] == '?') {
                            j++;
                        }
                        
                        if (todo[i - 1] == 'J') {
                            costc += y;
                        }
                        else{
                            cout << "check3.1 " << i;
                            costj += x;
                        }
                        if (todo[j + 1] == 'C') {
                            costj += y;
                        }
                        else {
                            cout << "check3.2 " << i;
                            costc += x;
                        }



                        if (costc < costj) {
                            //cout << costc << "costC";
                            mincost += costc;
                        }
                        else {
                            //cout << costj <<"costJ";
                            mincost += costj;
                        }
                        //cout <<i << j;
                         if (todo[i - 1] != todo[j]) {
                             if (x < y) {
                                 mincost += x;
                             }
                             else {
                                 mincost += y;
                             }
                         }

                        i = j;*/


                        int j = i; // j zeigt auf ? mit 1. buchstabe; i ist erstes ?
                        while (todo[j] == '?') {
                            j++;
                        }
                       // cout << todo[i]<<todo[j];
                        if (todo[i-1] == 'J' && todo[j] == 'C') {
                            //cout << "check1";
                            mincost += y; // bei fragezeichen gegen vorne und hinten kosten berechnen           

                        }
                        else if (todo[i-1] == 'C' && todo[j] == 'J') {
                            //cout << "check2 " << i;
                            mincost += x; // bei fragezeichen gegen vorne und hinten kosten berechnen

                        }
                        i = j-1;
                    }



                }


            }
        cout << "Case #" << t << ": " << mincost << endl;


    }
    return 0;

}