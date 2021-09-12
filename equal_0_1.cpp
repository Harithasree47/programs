#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
	int maxLen(int arr[], int N) {
		int i, max_length = 0, sum = 0;
		map<int, int>m;
		m[0] = -1;
		for (i = 0; i < N; i++) {
			if (arr[i] == 0) {
				arr[i] = -1;
			}
			sum += arr[i];
			auto it = m.find(sum);
			if (it != m.end()) {
				max_length = max(max_length, i - m[sum]);
			}
			else {
				m[sum] = i;
			}
			cout << max_length << " ";
		}
		return max_length;
	}
};
int main() {
	int i, size, tmp;
	Solution s;
	int* arr;
	cin >> size;
	arr = (int*)malloc(sizeof(int) * size);
	for (i = 0; i < size; i++) {
		cin >> arr[i];
	}
	cout << s.maxLen(arr, size);

}
