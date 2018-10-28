#include <bits/stdc++.h>

using namespace std;
int m,n;
unsigned long long int TS=1,MS=1,M;

unsigned long long int gcd(unsigned long long int a,unsigned long long int b) {
    return b == 0 ? a : gcd(b, a % b);
}

string convert1(unsigned long long int a){
	stringstream ss;
	ss<<a;
	string s=ss.str();
	return s;
}
unsigned long long int convert2(string s){ 
    stringstream temp(s); 
    unsigned long long int x = 0; 
    temp >> x;
    return x;
}
void Balance(string &a,string &b){
	if (a.size()>b.size())
		b= string(a.size()-b.size(),'0')+b;
	a = string(b.size()-a.size(),'0')+a;
}

string Sum(string a, string b){
	Balance(a,b);
	int temp=0;
	for (int i=a.size()-1;i>=0;i--){
		a[i]=a[i]+b[i]+temp-48;
		temp=0;
		if (a[i]>'9'){
			temp=1;
			a[i]=a[i]-10;
		}
	}
	if (temp!=0)
		a="1"+a;
	return a;
}

string MulChar(string a,char b){
    if(b=='0') return "0";
    if(b=='1') return a;
	int f=0;
	for (int i=a.size()-1;i>=0;i--){
		a[i]=(a[i]-48)*(b-48)+f;
		f=0;
		if (a[i]>9){
			f=(a[i])/10;
			a[i]=(a[i])%10+48;
		}
		else a[i]+=48;
	}
	if (f>0){
		a=char(f+48)+a;
	}
	return a;
}

string Multi(string a,string b){
    string c="0";
    for (int i=0;i<a.size();i++){
        if (i!=a.size()-1)
            c=Sum(MulChar(b,a[i]),c)+"0";
        else
            c=Sum(MulChar(b,a[i]),c);
    }
    return c;
}
int main(){
	cin>>m>>n>>M;
	vector <unsigned long long int> ts(m);
	vector <unsigned long long int> ms(n);
	for (long int i=0;i<m;i++)
			cin>>ts[i];
	for (long int i=0;i<n;i++){
			cin>>ms[i];
		if (i<m){
			unsigned long long int temp=gcd(ts[i],ms[i]);
			ts[i]=ts[i]/temp;
			ms[i]=ms[i]/temp;
		}
	}
	for (long int i=0;i<m;i++){
		for (long int j=0;j<n;j++){
			if (ts[i]!=1&&ms[j]!=1){
				unsigned long long int temp=gcd(ts[i],ms[j]);
				ts[i]=ts[i]/temp;
				ms[j]=ms[j]/temp;
			}
			else if (ts[i]==1)
				break;
		}
	}
	for (long int i=0;i<max(m,n);i++){
		if (i<m){
			TS=(convert2(Multi(convert1(TS),convert1(ts[i]%M))))%M;
		}
		if (i<n){
			MS=(convert2(Multi(convert1(MS),convert1(ms[i]%M))))%M;
		}
	}
	cout<<TS<<endl<<MS;
	return 0;
}
