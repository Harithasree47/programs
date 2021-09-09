//Find the element that appears once 
/*Given a sorted array A[] of N positive integers having all the numbers occurring exactly twice,
 except for one number which will occur only once. Find the number occurring only once.*/
 #include<iostream>
using namespace std;
class Solution{
	public:
		int search(int A[],int N){
			//xor operation is commutative in nature a^b=b^a
			//xor on same elemnts gives 0 as result a^a=0
			//an element xor with 0 gives same element as result a^0=a
			int index,result=A[0];
			for(index=1;index<N;index++){
				result=result^A[index];
			}
			return result;
		}
};
int main(){
	int len,index;
	cin>>len;
	int arr[len];
	for(index=0;index<len;index++){
		cin>>arr[index];
	}
	Solution ob;
	cout<<ob.search(arr,len);
	return 0;
}