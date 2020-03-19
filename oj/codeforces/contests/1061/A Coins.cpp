#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	int a,s;
	cin>>a>>s;
	cout<<s/a+(s%a!=0);
	return 0;
}
