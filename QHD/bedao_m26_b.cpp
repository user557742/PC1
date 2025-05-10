// cho day a co n phan tu dem so luong gia tri khac nhau cua cac tap con lien tiep
// sub1 : n<=5000 brute O(n^2)
// sub2 :
#include <iostream>
#include <set>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b ;i++) 
const int maxn = 1e6+1;
int n;
int a[maxn];
void inp(){
	cin>>n;
	rei(i,1,n) cin>>a[i];
}
void sub1(){
	set<int> s;
	rei(i,1,n) s.insert(a[i]);
	rei(l,1,n){
		int val=a[l];
		rei(r,l+1,n){
			val|=a[r];
			s.insert(val);
		}
	}
	cout<<s.size();
}void sub2(){
	// y tuong : xet lan luot cac vi tri  i ta luu 3 set 
	// cur : la tat cac cac gia tri xor ma ket thuc tai i-1
	// tmp : la tat ca cac gia tri xor kt tai i
	// ds : luu het
	set<int> cur;
	//set<int> tmp;
	set<int> ds;
	ds.insert(a[1]);
	cur.insert(a[1]);
	rei(i,2,n){
		set<int>tmp;
		for(int x:cur){
			tmp.insert()
		}
	}
}
int main(){
	inp();
	sub1();
}
