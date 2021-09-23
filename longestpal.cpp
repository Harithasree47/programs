// longestpal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<vector>
using namespace std;
int longestpal(string s) {
	int i,j,k,max_length=1,n = s.size();
	vector<vector<int>> v(n, vector<int>(n, 0));
	for (k = 0; k < n; k++) {
		i = 0;
		j = k;
		while (i < n && j < n) {
			if (s[i] == s[j]) {
				//all diagnoal elements are palindromes of legth 2
				if (i == j) {
					v[i][j] = 1;
				}
				//all palindromes of length 2
				if (i + 1 == j) {
					v[i][j] = 2;
				}
				//allpalindromes of length more than 2 which takes previous values to calculate
				if (i != j && v[i + 1][j - 1] != 0) {
					v[i][j] = 2 + v[i + 1][j - 1];
					if (v[i][j] > max_length) {
						max_length = v[i][j];
					}
				}
			}
			i++;
			j++;
		}
	}
	
		for (i = 0; i < n;i++) {
			for (j = 0; j < n;j++) {
				cout << v[i][j]<< " ";
				}
			cout << endl;
			}
	return max_length;
}
int main() {
	string s;
	cin >> s;
	cout << longestpal(s);
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
