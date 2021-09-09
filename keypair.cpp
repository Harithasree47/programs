/*Given an array Arr of N positive integers and another number X. 
Determine whether or not there exist two elements in Arr whose sum is exactly X.*/
#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
	bool hasArrayTwoCandidates(vector<int>arr, int n, int x) {
		unordered_map<int,int> s;
		int i, temp;
		
		for (i = 0; i < n; i++) {
			temp = x - arr[i];
			//if (s.find(temp)==s.end()) {
			if(!s[temp]){
				s[arr[i]]= 1;
			}
			else {
				return true;
			}
		}
		return false;
	}
};
int main() {
	int len, index, sum;
	cin >> len;
	cin >> sum;
	vector<int>arr(len,0);
	for (index = 0; index < len; index++) {
		cin >> arr[index];
	}
	Solution ob;
	cout << ob.hasArrayTwoCandidates(arr, len, sum);
	return 0;
}
