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

void countRolls(int end) {

}

void countLoad(int end) {
    //float mediumC = end;
    //cout << "\nYour current max medium roll load: " << mediumC;
}

int main(){
    int end;
    float eq;
    cout << "Input your current endurance: ";
    cin >> end;
    if (end < 1 || end > 99)
    {
        cout << "Error, impossible endurance\n";
        return 0;
    }
    else if (end == 99) {
        cout << "bruh\n";
        return 0;
    }
    cout << "\nInput the total load you want to wear: ";
    cin >> eq;
    //countLoad(end);
    system("pause");
    return 0;
}