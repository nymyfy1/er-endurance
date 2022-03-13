#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

float chkNbr(int endo) {
    if (endo <= 8) return 0;

    int a[] = { 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 20, 22, 23, 24, 25 }; // 1.6
    int b[] = { 13, 21, 46, 49, 50, 52, 53, 55, 56, 57, 58, 59, 60 }; // 1.5
    int c[] = { 37, 39, 40, 41, 42, 43, 44, 45, 47, 48, 51, 54 }; // 1.4
    int d[] = { 31, 32, 33, 34, 35, 36, 38 }; // 1.3
    int e[] = { 29, 30 }; // 1.2
    int f[] = { 27, 28, 62, 66, 70, 74, 78, 82, 86, 90, 95, 98 }; // 1.1

    bool ex = find(begin(a), end(a), endo) != end(a);
    if (ex) return 1.6;
    ex = find(begin(b), end(b), endo) != end(b);
    if (ex) return 1.5;
    ex = find(begin(c), end(c), endo) != end(c);
    if (ex) return 1.4;
    ex = find(begin(d), end(d), endo) != end(d);
    if (ex) return 1.3;
    ex = find(begin(e), end(e), endo) != end(e);
    if (ex) return 1.2;
    ex = find(begin(f), end(f), endo) != end(f);
    if (ex) return 1.1;
    return 1.0;
}

float countRoll(int endo, bool rolltype) {
    int endurance = 1;
    float weight = 45;
    float rollweight;
    for (int i = 1; i < endo; i++) {
        weight += chkNbr(++endurance);
    }
    if (!rolltype) {
        rollweight = weight * 0.30;
    }
    else {
        rollweight = weight * 0.70;
    }
    //cout << "weight = " << weight << endl;
    return rollweight;
}

void countLoad(int endo) {
    //float mediumC = endo;
    //cout << "\nYour current max medium roll load: " << mediumC;
}

int main(){
    int endo, choice, lv;
    float eq, roll;
    cout << "Input your current endurance: ";
    cin >> endo;
    if (endo < 1 || endo > 99)
    {
        cout << "Error, impossible endurance\n";
        return 0;
    }
    else if (endo == 99) {
        cout << "bruh\n";
        return 0;
    }
    cout << "\nInput the total load you want to wear: ";
    cin >> eq;
    cout << "\nWhat kind of roll do you need?\n[1] light\n[2] medium\n[Other] Exit\ninput: ";
    cin >> choice;
    switch (choice) {
    case 1:
        roll = countRoll(endo, 0);
        break;
    case 2:
        roll = countRoll(endo, 1);
        break;
    default:
        return 0;
    }
    cout << "Your current allowed load: " << roll << endl;
    for (lv = 0; eq > roll; lv++) {
        switch (choice) {
        case 1:
            roll = countRoll(endo + lv, 0);
            break;
        case 2:
            roll = countRoll(endo + lv, 1);
            break;
        default:
            break;
        }
    }
    cout << "You need " << lv << " points in endurance\n";
    system("pause");
    return 0;
}