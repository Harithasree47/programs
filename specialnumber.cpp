// specialnumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void specialnumber(long long n) {
	int i,j,k,length=0;
	long long tmp = n;
	unordered_map<long long,int>m;
	vector<int>v1;
	while (n > 0) {
		length++;
		k = n % 10;
		v1.push_back(k);
		n = n / 10;
	}
	reverse(v1.begin(), v1.end());
	vector<vector<long long>> v(length, vector<long long>(length, 0));
	for (k = 0; k < length; k++) {
		i = 0;
		j = k;
		while (i < length && j < length) {
			if (i == j) {
				v[i][j] = v1[j] * 1;
			}
			else {
				v[i][j] = v[i][j - 1] * v1[j];
			}
			if (m[v[i][j]]) {
				for (i = 0; i < length; i++) {
					for (j = 0; j < length; j++) {
						cout << v[i][j] << " ";
					}
					cout << endl;
				}
				cout << "not a special number";
				return;
			}
			else {
				m[v[i][j]] = 1;
			}
			i++;
			j++;
		}

	}
	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Special number";
	return;
}
int main() {
	long long n;
	cin >> n;
	specialnumber(n);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
