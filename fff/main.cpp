//
//  main.cpp
//  fff
//
//  Created by Ксения Венедиктова on 17.10.2018.
//  Copyright © 2018 Ксения Венедиктова. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a;
int min (vector <int> b){
    int minimum = b[0];
    for (int i = 0; i< b.size(); i++){
        if (b[i] < minimum){
            minimum = b[i];
        }
    }
    return minimum;
}
int all(vector<int>b){
    static int c = 0;
    int minimum = min(b);
    if (minimum < b.size())
    {
        c+=minimum;
        vector <int> d;
        for (int i = 0; i<b.size(); i++){
            if (b[i] > minimum){
                d.push_back(b[i] - minimum);
                if(i+1 < b.size()){
                    if(b[i+1] == minimum){
                        all(d);
                        d.clear();
                    }
                    
                }
                else
                {
                    all(d);
                }
            }
        }
    }
    else
    {
        c+=b.size();
    }
    return c;
    
}




int main(int argc, const char * argv[]) {
    cout << "Введите количество досок" << endl;
    cin >> a;
    vector <int> vect;
    for (int i = 0; i < a; i++) {
        int c;
        cout << "Введите высоту" << i+1 << "доски" << endl;
        cin >> c;
        vect.push_back(c);
        }
    int ans = all(vect);
    cout << ans;
    
    return 0;
}
