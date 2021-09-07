#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n, index, water_stored = 0, max;
    vector<int>a;
    vector<int>left_max;
    vector<int>right_max;
    //cout << "enter no of hills: ";
    cin >> n;
    for (index = 0; index < n; index++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
   
    right_max.resize(n);
    left_max.resize(n);
    left_max[0] = a[0];
    right_max[n - 1] = a[n - 1];
    max = a[0];

    for (index = 1; index < n; index++) {
        if (a[index] > max) {
            max = a[index];
            left_max[index] = max;
        }
        else {
            left_max[index] = max;
        }
    }
    //	cout<<" Compute Values for the right max array";
    max = a[n - 1];
    for (index = n - 2; index >= 0; index--) {
        if (a[index] > max) {
            max = a[index];
            right_max[index] = max;
        }
        else {
            right_max[index] = max;
        }
    }
    for (index = 1; index < n - 1; index++) {
        if (left_max[index] > right_max[index]) {
            water_stored+= right_max[index] - a[index];
        }
        else {
            water_stored += left_max[index] - a[index];
        }
    }
    cout << water_stored;

    return 0;
}
