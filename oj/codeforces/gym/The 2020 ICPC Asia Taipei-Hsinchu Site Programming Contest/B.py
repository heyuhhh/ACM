val=list(map(int, input().split()))
vis=[False,False,False,False]
ok=set()
def dfs(d, equ, z):
	if d==4:
		ans = eval(equ)
		if ans>=0 and z:
			ok.add(ans)
		return
	for i in range(4):
		if vis[i]!=True:
			vis[i]=True
			if d<3:
				dfs(d+1, equ+str(val[i])+'+', True)
				dfs(d+1, equ+str(val[i])+'-', True)
				dfs(d+1, equ+str(val[i])+'*', True)
			dfs(d+1, equ+str(val[i]), z)
			vis[i]=False

dfs(0,"",False)
print(len(ok))
