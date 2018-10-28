#include <bits/stdc++.h>

using namespace std;
unsigned int n;
unsigned int long long Sum=0;
int main(){
	if (n<=0){
		
	}
	cin>>n;
	set <unsigned int long long> a;
	set <unsigned int long long> ::iterator it;
	map<unsigned int long long,unsigned int long long> b;
	for (unsigned int long long i=0;i<n;i++){
		unsigned int long long c;
		cin>>c;
		Sum+=c;
		a.insert(c);
		b[c]++;
	}
	vector <unsigned int long long> Sum1;
	for (it=a.begin();it!=a.end();it++){
		Sum1.push_back(*it*b[*it]);
	}
	unsigned long long int Min= *min_element(Sum1.begin(), Sum1.end());
	cout<<Sum-Min<<endl;
	return 0;
}
