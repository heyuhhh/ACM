set msg=%2
if not defined msg (set msg=%~n1%~x1)

git add %1
git commit -m %msg%
git push origin master
