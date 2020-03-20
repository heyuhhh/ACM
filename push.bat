set msg=%2
if "%msg%"=="" (set msg="Initial Commit")

git add %1
git commit -m %msg%
git push origin master
