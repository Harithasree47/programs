#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
	vector<int>arr;
	int i,n;
    stack<int>st;
    cin>>n;
    for(i=0;i<n;i++){
    	int t;
    	cin>>t;
    	arr.push_back(t);
	}
   /*int* oup = new int(n);
    memset(oup, -1, sizeof(oup));*/
    vector<long long>oup(n, -1);
    st.push(0);
    for (i = 1; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
                oup[st.top()] = arr[i];    
                st.pop();
        }
        st.push(i);
    }
     for(i=0;i<n;i++){
     	cout<<oup[i]<<" ";
     }

    return 0;
}