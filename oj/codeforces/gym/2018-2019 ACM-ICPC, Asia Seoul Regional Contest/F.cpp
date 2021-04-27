#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

stack<char> s;
inline char get() {
	char t;
	while((t=getchar())!=EOF && t<=' ');
	return t;
	
}
int flag = 1;
int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	char c;
	while((c=get())!=EOF) {
		s.push(c);
		if(s.top() == ')') { 
			s.pop();
			int tmp = 0, cnt = 0;
			while(!s.empty() && s.top() != '(') {
				if(tmp == 0 && (s.top() < 'a' || s.top() > 'z'))flag = 3;
				if(tmp == 1 && s.top() >= 'a' && s.top() <= 'z') flag = 3;
				tmp ^= 1;
				cnt++;
				s.pop();
			}
			if(s.empty() || tmp == 0) flag = 3;
			if(tmp == 1 && cnt != 3) flag = max(flag, 2);
			if(!s.empty()) s.pop();
			if(cnt) s.push('a');
		}
	}
	
	int tmp = 0;
	if(s.size() != 3)  flag = max(flag, 2);
	while(!s.empty()) {
		if(tmp == 0 && (s.top() < 'a' || s.top() > 'z'))flag = 3;
		if(tmp == 1 && s.top() >= 'a' && s.top() <= 'z') flag = 3;
		tmp ^= 1;
		s.pop();
	}
	if(flag == 1) puts("proper");
	else if(flag == 2) puts("improper");
	else puts("error");
	
}
