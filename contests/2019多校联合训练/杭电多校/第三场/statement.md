1001	Azshara's deep sea  Time Limit: 1000MS Memory Limit: 64MB

1002	Blow up the city    Time Limit: 5000MS Memory Limit: 128MB

1003	Yukikaze and Demons  Time Limit: 10000MS Memory Limit: 128MB

1004	Distribution of books   Time Limit: 8000MS Memory Limit: 64MB

1005	Easy Math Problem   Time Limit: 10000MS Memory Limit: 128MB

1006	Fansblog    Time Limit: 2000MS Memory Limit: 64MB 

1007	Find the answer Time Limit: 4000MS Memory Limit: 64MB

1008	Game    Time Limit: 10000MS Memory Limit: 64MB

1009	K Subsequence   Time Limit: 2000MS Memory Limit: 64MB 

1010	Sindar's Art Exhibition Time Limit: 3000MS Memory Limit: 64MB

1011	Squrirrel   Time Limit: 4000MS Memory Limit: 64MB


## Azshara's deep sea

### Description

As a little Gnome Rogue, WW is a loyal player in World of Warcraft. Although the daily tasks of version 8.2 are so boring, he insists on going online every day.

Since the stealth skill of the Rogue can prevent him from being seen by the enemy, he always plays PVP in the wild. One night, on the way finding an elite monster on the map, he saw a shivering priest who is chased by the Rogue and a Demon Hunter. Then he decided to help the poor priest. Sure enough, with the helping of the most powerful specialization in the current version, the priest TT survived.

WW made friends with TT. In the conversation, WW found that the guild that TT takes part is preparing to raid the epic mode of the Dungeon ‘Eternal Palace’. As a core member of the union team, TT is worried with the last BOSS of the Dungeon.

According to Dungeon’s Guide, the last BOSS Azshara will enter a hidden phase when her HP drops to 0%. At this time, the previous battlefield will be destroyed and all players will sink into a deep sea. The BOSS will strengthen to become the Azshara’s soul.

Players need to fight within the range of the lights. The lights are tied to the wooden sticks. Therefore, we can assume that the player is fighting in a convex polygon made by wooden sticks.(The wooden sticks are distributed over the entire polygon.) Of course, players can not only stand on the wooden sticks, but also move freely within this area.

Azshara’s souls has a skill to deliver stingers to the crowd in the battlefield. Each stinger would make a circle whose radius is R. Another skill of Azshara’s soul is to choose two players randomly (Two players are a pair, and any two pairs do not contain the same person) and link them with an ice ray. If the ice ray passes through the circle formed by the stinger ( Including the case where the ray is tangent to the circle ) , all of the players will die. So we can’t let the rays pass through these circles. There are some other requirements for the ice ray technique: 1. Two ice rays cannot intersect. (Ray intersection does not include the coincidence of endpoints of two different segments) 2. The two choosen players cannot be too close.

Eventually, the leader comes up with such a way to help players win this boss faster:

First, in order to influence other players that are not selected as small as possible, the selected players should stand at the outermost side of the battlefield.

Second, in order to find the position more accurately, the player needs to run to the outermost wooden sticks, that is, the coordinates (x,y) of the wooden sticks are the coordinates (x,y) of the player (a wooden stick can withstand multiple players).

Third, players in the same pair cannot stand on adjacent wooden sticks. In other words, if we number the outermost wooden sticks, the players in the same pair cannot have one person in the position of i and the other person in the position of i+1.

The leader now knows the position of the wooden sticks and the position of the center of the circle. What is the maximum number of the pairs he can arrange in the battlefield?

### Standard Input

The input includes several cases. The first line of input is a single line of integer T (1≤T≤10), the number of test cases.

For each case, the first line contains three space-separated integers: N(0<=N<=400), G(0 <= G <= 100) , and R (0<=R<=100)

Next there will be N lines. Each line contains two space-separated integers x,y that are the position of wooden sticks.

Next there will be G lines. Each line contains two space-separated integers x,y that are the position of stingers inside battlefield.

0<=x,y<=1e6

### Standard Output

Only one line includes a number indicating how many pairs of players can be arranged in the battlefield.

### Sample Input

1

5 3 1

6 10

10 7

9 1

2 0

0 3

2 2

5 6

8 3

### Sample Output

1

## Blow up the city

### Description

Country A and B are at war. Country A needs to organize transport teams to deliver supplies toward some command center cities.

In order to ensure the delivery works efficiently, all the roads in country A work only one direction. Therefore, map of country A can be regarded as DAG( Directed Acyclic Graph ).  Command center cities only received supplies and not send out supplies.

Intelligence agency of country B is credibly informed that there will be two cities carrying out a critical transporting task in country A. 

As long as **any** one of the two cities can not reach a command center city, the mission fails and country B will hold an enormous advantage. Therefore, country B plans to destroy one of the $n$ cities in country A and all the roads directly connected. (If a city carrying out the task is also a command center city, it is possible to destroy the city to make the mission fail)

Now country B has made $q$ hypotheses about the two cities carrying out the critical task.
Calculate the number of plan that makes the mission of country A fail.

### Standard Input

The first line contains a integer $T$ $(1 \leq T \leq 10)$, denoting the number of test cases.

In each test case, the first line are two integers $n, m$, denoting the number of cities and roads$(1\leq n\leq 100,000, 1\leq m\leq 200,000)$.
Then $m$ lines follow, each with two integers $u$ and $v$, which means there is a directed road from city $u$ to $v$ $(1\leq u, v\leq n, u \neq v)$.

The next line is a integer q, denoting the number of queries $(1\leq q\leq 100,000)$
And then $q$ lines follow, each with two integers $a$ and $b$, which means the two cities carrying out the critical task are $a$ and $b$ $(1\leq a, b\leq n, a \neq b)$.

A city is a command center if and only if there is no road from it (its out degree is zero).

### Standard Output

For each query output a line with one integer, means the number of plan that makes the mission of country A fail.

### Sample Input

8 8 

1 2 

3 4 

3 5 

4 6 

4 7 

5 7 

6 8

7 8

2 

1 3 

6 7 

3 2 

3 1 

3 2 

2 

1 2 

3 1

### Sample Output

4

3

2

2


## Yukikaze and Demons

### Description
Yukikaze is facing a huge crisis!

Under the attack of a kind of demons, dragon eaters, the dragon forest is endanger. As a member of the Biscotti Knights Secret Squad, she must do something to save the dragon forest.

The road in the dragon forest forms an undirected tree. Every vertex is occupied by a demon with a type denoted by a decimal digit.

In one of her strike, she can sweep out all the enemy on the path if and only if the decimal number formed by concatenating the types of enemy on the path sequentially is divisible by a special number $k$.

The demons are destroying the forest! Time is limited, she needs to know how many path in the dragon forest can be cleared in a single strike of hers.

In this problem, a single vertex is considered as a path too!
### Standard Input

The input includes several test cases. 

The first line of the input contains one integer $T(1 \leq T \leq 20)$, denoting the number of test cases.

For each test case, the first line contains two space-separated integers $N(1 \leq N \leq 50000)$, $k(1 \leq k \leq 100000)$, and a digit string $S(|S|=N)$. Denoting the number of vertex and the special number, and the decimal digits on every vertex. The decimal digit on the i-th vertex is the i-th character of $S$.

For each of the next $N-1$ lines, there are two space-separated integer $u,v$, denoting a road connecting two vertex in the dragon forest.
### Standard Output

For each test case, print the answer in a line.
### Sample Input

2

4 3 0123

1 2

1 4

3 1

2 10 50

1 2

### Sample Output
6

2

[hint]
In the first example, there are 6 path can be cleared in a single strike:

$1,1-4,2-1-3,3-1-2,4,4-1$
[/hint]

## Distribution of books

### Description
zz6d likes reading very much, so he bought a lot of books. One day, zz6d brought n books to a classroom in school. The books of zz6d is so popular that K students in the classroom want to borrow his books to read. Every book of zz6d has a number i (1<=i<=n). Every student in the classroom wants to get a continuous number books. Every book has a pleasure value, which can be 0 or even negative (causing discomfort). Now zz6d needs to distribute these books to K students. The pleasure value of each student is defined as the sum of the pleasure values of all the books he obtains.Zz6d didn't want his classmates to be too happy, so he wanted to minimize the maximum pleasure of the K classmates. zz6d can hide some last numbered books  and not distribute them,which means he can just split the first x books into k parts and ignore the rest books, every part is consecutive and no two parts intersect with each other.However,every classmate must get at least one book.Now he wonders how small can the maximum pleasure of the K classmates be.

1<=T<=10  

1<=n<=2*$10^5$  

1<=k<=n  

-$10^9$<=a_i<=$10^9$

### Standard Input
Input contains multiple test cases.  
The first line of the input is a single integer T which is the number of test cases. T test cases follow.  
For each test case, the first line contains two integer n,k: the number of books and the number of his classmates.  The second line contains n integers  $a_1 ,a_2$,&hellip;, $a_{n-1},a_n$. ($a_i$means the pleasure value  of book i.) $\sum_{}$n<=2*$10^5$.

### Standard Output
For each case, print the smallest maximum pleasure of the K classmates, and one line one case.

### Sample Input
2

4 2

3 -2  4 -2

5 4

-1 -1 -1 -1 6

### Sample Output

2

-1

[hint]In the first example,classmate 1 get book 1,2, classmate 2 get book 3,4.the maximum pleasure is max((3-2), (4-2))=2;

In the second example,he can ignore book 5 and spilt the first 4 books into 4 parts,give them to his classmates.[/hint]

## Easy Math Problem

### Description
One day, Touma Kazusa encountered a easy math problem. Given $n$ and $k$, she need to calculate the following sum modulo $1e9 + 7​$.

$\sum_{i=1}^{n}\sum_{j=1}^{n}gcd(i,j)^klcm(i, j)[gcd(i,j)\in prime]\% (1e9 + 7)$

However, as a poor student, Kazusa obviously did not, so Touma Kazusa went to ask Kitahara Haruki. But Kitahara Haruki is too busy, in order to prove that he is a skilled man, so he threw this problem to you. Can you answer this easy math problem quickly?

### Standard Input

There are multiple test cases. The first line of the input contains an integer $T$, indicating the number of test cases. For each test case:

There are only two positive integers $n$ and $k$ which are separated by spaces.


$T = 5$

$1 \leq n \leq 1e10$

$1 \leq k \leq 100$

### Standard Output

An integer representing your answer.

### Sample Input
1
10 2
### Sample Output
2829

## Fansblog

### Description
Farmer John keeps a website called ‘FansBlog’ .Everyday , there are many people visited this blog.One day, he find the visits has reached P , which is a prime number.He thinks it is a interesting fact.And he remembers that the visits had reached another prime number.He try to find out the largest prime number Q ( Q < P ) ,and get the answer of Q! Module P.But he is too busy to find out the answer. So he ask you for help. ( Q! is the product of all positive integers less than or equal to n: n! = n * (n-1) * (n-2) * (n-3) *… * 3 * 2 * 1 . For example, 4! = 4 * 3 * 2 * 1 = 24 )

### Standard Input
First line contains an number T(1<=T<=10) indicating the number of testcases.
Then T line follows, each contains a positive prime number P (1e9≤p≤1e14)
### Standard Output
For each case output a line with one integer, means the factorial of Q modulo P for one line.
### Sample Input
1
1000000007
### Sample Output
328400734

## Find the answer

### Description
Given a sequence of n integers called W and an integer m. For each i (1 <= i <= n), you can choose some elements $W_k$ (1 <= k < i), and change them to zero to make $\sum_{j=1}^i$$W_j$<=m. So what's the minimum number of chosen elements to meet the requirements above?

### Standard Input
The first line contains an integer Q --- the number of test cases.  
For each test case:  
The first line contains two integers n and m --- n represents the number of elements in sequence W and m is as described above.  
The second line contains n integers, which means the sequence W.


1 <= Q <= 15  

1 <= n <= 2*$10^5$  

1 <= m <= $10^9$  

For each i, 1 <= $W_i$ <= m
### Standard Output
For each test case, you should output n integers in one line: i-th integer means the minimum number of chosen elements $W_k$ (1 <= k < i), and change them to zero to make $\sum_{j=1}^i$$W_j$<=m.
### Sample Input

2  

7 15  

1 2 3 4 5 6 7  

5 100  

80 40 40 40 60

### Sample Output

0 0 0 0 0 2 3  

0 1 1 2 3

## Game

### Description
Again Alice and Bob is playing a game with stones. There are N piles of stones labelled from $1$ to $N$, the $i$ th pile has $a_i$ stones. 

First Alice will choose piles of stones with consecutive labels, whose leftmost is labelled with $L$ and the rightmost one is $R$. After, Bob will choose another consecutive piles labelled from $l$ to $r$ $(L \leq{l}\leq{r}\leq R)$. Then they're going to play game within these piles.

Here's the rules of the game: Alice takes first and the two will take turn to make a move: choose one pile with nonegetive stones and take at least one stone and at most all away. One who cant make a move will lose.

Bob thinks this game is not so intersting because Alice always take first. So they add a new rule, which is that Bob can swap the number of two adjacent piles' stones whenever he want before a new round. That is to say, if the $i$ th and $i + 1$ pile have $a_i$ and $a_{i + 1}$ stones respectively, after this swapping there will be $a_{i + 1}$ and $a_i$.

Before today's game with Bob, Alice wants to know, if both they play game optimally when she choose the piles from L to R, there are how many pairs (l, r) chosed by Bob that will make Alice win.
### Standard Input
Input contains several test cases.

For each case:

The fisrt line contains $N$, $M$. $N$ is mentioned aboved and $M$ is the number of the sum of game rounds and the times of Bob's swapping.

The second line contains N integars $a_1, a_2, ... a_n$, indicating the number of each piles' stones.

The next M lines will have an integar $opt$ $(1 \leq opt \leq 2)$, indicating the type of operation.

If opt equals $1$, then $L$ and $R$ follow. Alice and Bob start a new round and Alice choose $L$ and $R$ as mentioned. 

If opt equals $2$, then $POS$ follows. Bob will swap the piles labelled $POS$ and $POS + 1$.


$0 \leq a_i \leq 1,000,000$

$1 \leq N, M \leq 100,000, \sum{N}, \sum{M} < 600,000$

$1 \leq L \leq R \leq N$

$1 \leq POS < N$
### Standard Output
For each case:

For each opt which equals $1$, you shall output one line with an integar indicating the number of pairs $(l, r)$ that will make Alice win the round.
### Sample Input
3 3

4 0 4

2 2

2 1

1 1 3
### Sample Output
3

## K Subsequence

### Description
Master QWsin is dating with Sindar. And now they are in a restaurant,  the restaurant has $n$ dishes in order. For each dish, it has a delicious value $ai$. However, they can only order $k$ times. QWsin and Sindar have a special ordering method, because they believe that by this way they can get maximum happiness value.

Specifically, for each order, they will choose a $subsequence$ of dishes and in this $subsequence$, when $i < j$, the subsequence must satisfies $ai \leq aj$. After a round, they will get the sum of the $subsequence$ and they can't choose these dishes again. 

Now, master QWsin wants to know the maximum happiness value they can get but he thinks it's too easy, so he gives the problem to you. Can you answer his question?


### Standard Input
There are multiple test cases. The first line of the input contains an integer $T$, indicating the number of test cases. For each test case:

First line contains two positive integers $n$ and $k$ which are separated by spaces.

Second line contains $n$ positive integer $a1$,$a2$,$a3$...$an$ represent the delicious value of each dish.


$1 \leq T \leq 5​$

$1 \leq n \leq 2000$

$1 \leq k \leq 10$

$1 \leq ai \leq 1e5$

### Standard Output
Only an integer represent the maximum happiness value they can get.
### Sample Input
1

9 2

5 3 2 1 4 2 1 4 6
### Sample Output
22

## Sindar's Art Exhibition

### Description
Sindar is an excellent artist and she has many works. One day she decides to hold an exhibition tour in her country. Her country is a tree, the nodes of which are the cities and the edges between the nodes are the roads between cities. 
The value of an exhibition are determined by the number of works on the exhibition and the citizens' favorability of art. Generally speaking, if there are $m$ works in the exhibition, and the citizens' favorability is $k$, then the value of the exhibition will be $m*k$. 
Her tour will begin at city $s$ and end in city $t$. She will begin the tour with $x$ works, but after she holds the exhibition in every city, she will choose $y_i$ suitable works and donate them to the local orphanage, which means that there will be only $x-y_i$ works when she holds the next exhibition, and $x-y_i-y_j$ works in the exhibition after the next, supposing that she will pass city $j$ after city $i$.
Now she has many tours and she wants to know every tour's value mod $10^9+7$. And sometimes she may change one city's favorability.
### Standard Input
There are multiple test cases. The first line of the input contains an integer $T$, indicating the number of test cases. For each test case:
The second line contains one interger $n$, indicating the number od cities. $(1\leq n \leq 10^5)$
It's guaranteed that $\Sigma n\leq 3*10^5$
The next line contains $n$ interger $f_i$, the $i-th$ interger indicates the citizens' favorability of art in city $i$.($0\leq f_i\leq 2*10^9)$
The next line contains $n$ interger $y_i$, the $i-th$ interger indicates the number of works Sindar will donate to the orphanage in city $i$.$(0\leq y_i\leq 10^4)$
Each of the following $n-1$ lines contains two intergers $u,v$ indicating that there is a road between city $u$ and city $v$. ($1\leq u,v \leq n$)
The next line contains two interger $q$,indicating the number of tours and the number of works Sindar will donate to the local orphanage.$(1\leq q \leq 10^5)$
Each of the next $q$ lines contains one instruction. And there are two kinds of instructions:
$1\ s\ t\ x$ indicates the start city ,the end city and the number of works Sindar owns at first. $(1\leq s,t\leq n , s\neq t,x\leq 2*10^9)$
$2\ c\ v$ indicates Sindar wants to change the favorability of city $c$ to $v$.$(1\leq c\leq n,0\leq v\leq 2*10^9)$
It is guaranteed that $x \geq dis(s,t)*y$. $dis(s,t)$ indicates the number of cities you must pass from $s$ to $t$.
### Standard Output
For each query, output one interger indicates the tour's value mod $10^9+7$
### Sample Input
1

6

1 2 1 4 5 6

1 1 1 2 2 2

1 2

2 4

2 5

5 6

1 3

2

2 3 3

1 6 3 10
### Sample Output
129

[hint]129=6*10+5*8+2*6+1*5+3*4[/hint]

## Squirrel

### Description

Master magician `eom` is searching for his naughty squirrel. The squirrel hides at a node of a tree, while its owner `eom` has no idea which node it hides at. As a magician, `eom` can choose a node and release many magical creatures to search his squirrel in all directions at the speed of 1. Besides, he can choose a pair of adjacent nodes on the tree and reduce the distance between them to 0 before releasing magical creatures. Please help him to find the start node to release magical creatures, so that `eom` can find his squirrel in the shortest time even in the worst condition. Note that `eom` is full of wisdom, so that he can optimally make decision to reduce the distance after the start node is determined. 

### Standard Input

The first line contains a integer T$(1\leq T\leq 20)$, indicating there are T test cases followed.

For each test case, the first line contains one integers $n$: the number of nodes of the tree$(1\leq n\leq 200,000)$.  

In the following $n-1$ lines, each line has three integers $u$,$v$ and $w$, indicating there exists a line between node $u$ and $v$, which length equals to $w$$(1\leq u,v\leq n,1\leq w\leq 200)$.

It is guaranteed that $(1\leq ∑n\leq 2, 000, 000)$.

$(1\leq T \leq 20)$

$(1\leq n\leq 200,000)$

$(1\leq u,v\leq n,1\leq w\leq 200)$

$(1\leq ∑n\leq 2000000)$

### Standard Output

Output two integers. The first one is the index of the start node you should choose and the second one is the least time required in the worst condition. If there are multiple possible ways to choose the start node to minimize the time, the index of start node chosen should be minimum.

### Sample Input

1

5

1 5 1

1 2 1

2 3 2

3 4 1

### Sample Output

1 2

