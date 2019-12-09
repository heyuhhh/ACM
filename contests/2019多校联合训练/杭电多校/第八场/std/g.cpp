#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>
#define MAXN 300010
#define MAXLIM 500

#define array frgehvfd

using namespace std;

int t , n , m , lim , a[ MAXN ] , dep[ MAXN ] , use[ MAXN ] , size[ MAXN ] , have[ MAXLIM ] , maxdep , rec;
vector < int > linker[ MAXN ];

struct vec
{
    vector<int> v;
	
	void assign( int c )
	{
        v.reserve(c + 1);
	}
	
	void set( int c )
	{
        v.assign(c + 1, 0);
	}
	
	void push_back( int x )
	{
		v.push_back(x);
	}
	
	void clear()
	{
		v.clear();
	}
	
	int size()
	{
		return v.size();
	}
	
	int & operator[] ( int i )
	{
		return v[i];
	}
	
} array;

#define block_l( t ) ( t * block_size )
#define block_r( t ) ( ( t + 1 ) * block_size - 1 )

struct Block
{
	int size , block_size;
	vec a , b , array;
	
	int belong( int x )
	{
		return x / block_size;
	}
	
	void clear()
	{
		size = 0;
		a.clear();
		b.clear();
		array.clear();
	}
	
	void build()
	{
		if( size )
		{
			block_size = sqrt( size );
			a.set( belong( size - 1 ) );
			b.set( size );
			array.assign( size );
		}
	}
	
	void modify1( int l , int r , int x )
	{
		l = lower_bound( array.v.begin() , array.v.end() , l ) - array.v.begin();
        r = upper_bound( array.v.begin() , array.v.end() , r ) - array.v.begin() - 1;
		if( l > r ) return;
		if( belong( l ) == belong( r ) )
			for( int i = l ; i <= r ; i++ )
				b[i] += x;
		else
		{
			int t = belong( l );
			for( int i = l ; i <= block_r( t ) ; i++ )
				b[i] += x;
				t = belong( r );
			for( int i = block_l( t ) ; i <= r ; i++ )
				b[i] += x;
			for( int i = belong( l ) + 1 ; i < t ; i++ )
				a[i] += x;
		}
	}
	
	int find1( int x )
	{
		return b[x] + a[ belong( x ) ];
	}
	
	void modify2( int x , int y )
	{
		a[ belong( x ) ] += y;
		b[x] += y;
	}
	
	void modify2( int l , int r , int x )
	{
		if( l - 1 >= 0 ) modify2( l - 1 , -x );
		modify2( r , x );
	}
	
	int find2( int x )
	{
		int t = min( size - 1 , block_r( belong( x ) ) ) , ans = 0;
		for( int i = x ; i <= t ; i++ )
			ans += b[i];
		for( int i = belong( x ) + 1 ; i <= belong( size - 1 ) ; i++ )
			ans += a[i];
		return ans;
	}
	
} block[ MAXN ];

struct operation
{
	int opt , a , x , y , z;
} q[ MAXN ];

int l[ MAXN ] , r[ MAXN ] , tot;

#define cur linker[x][i]

void dfs( int x )
{
	l[x] = ++tot , a[ tot ] = x;
	for( int i = 0 ; i < linker[x].size() ; i++ )
		dep[ cur ] = dep[x] + 1 , dfs( cur );
	r[x] = tot; 
}

bool cmp( const int & a , const int & b )
{
	return l[a] < l[b];
}

void addedge( int x , int y )
{
	linker[x].push_back( y );
}

struct HLD
{
	vector < int > linker[ MAXN ];
	int size[ MAXN ] , dep[ MAXN ] , fa[ MAXN ] , son[ MAXN ] , top[ MAXN ] , a[ MAXN ] , l[ MAXN ] , r[ MAXN ] , tot;
	
	void clear()
	{
		for( int i = 1 ; i <= n + 1 ; i++ ) linker[i].clear();
		memset( son , 0 , sizeof( son ) );
		tot = 0;
	}
	
	void dfs1( int x )
	{
		size[x] = 1;
		for( int i = 0 ; i < linker[x].size() ; i++ )
		{
			dep[ cur ] = dep[x] + 1 , fa[ cur ] = x;
			dfs1( cur ) , size[x] += size[ cur ];
			if( size[ cur ] > size[ son[x] ] ) son[x] = cur;
		}
	}
	
	void dfs2( int x , int t )
	{
		l[x] = ++tot , a[ tot ] = x , top[x] = t;
		if( son[x] ) dfs2( son[x] , t );
		for( int i = 0 ; i < linker[x].size() ; i++ )
			if( cur != son[x] )
				dfs2( cur , cur );
		r[x] = tot;
	}
	
	void addedge( int x , int y )
	{
		linker[ fa[y] = x ].push_back( y );
	}
	
	void build()
	{
		dfs1( n + 1 );
		dfs2( n + 1 , n + 1 );
	}
	
	void LA( int now , int dist , int step , int v[] , int & cnt )
	{
		cnt = 0;
		while( now )
		{
			int x = dep[ now ] - dep[ top[ now ] ] + 1 , i;
			for( i = dist ; i < x ; i += step )
				v[ cnt++ ] = a[ l[ now ] - i ];
			i -= step;
			dist = step - ( x - i );
			now = fa[ top[ now ] ];
		}
		if( cnt && v[ cnt - 1 ] == n + 1 )
			cnt--;
	}
	
} HLD1 , HLD2;

int L[ MAXN / MAXLIM ] , R[ MAXN / MAXLIM ] , cnt1 , cnt2;

vector < int > dep_array[ MAXN ];

inline int read() {
    int x; scanf("%d", &x);
    return x;
}

inline void print(int x, int delim = '\n') {
    printf("%d%c", x, delim);
}

#define contain( x , y ) ( l[x] <= l[y] && l[y] <= r[x] )

int main()
{
	t = read();
	while( t-- )
	{
		n = read() , m = read();
		maxdep = tot = 0;
		HLD1.clear();
		HLD2.clear();
		array.clear();
		memset( have , 0 , sizeof( have ) );
		for( int i = 0 ; i < MAXN ; i++ )
			block[i].clear();
		memset( size , 0 , sizeof( size ) );
		memset( use , 0 , sizeof( use ) );
		for( int i = 1 ; i <= n + 1 ; i++ )
		{
			dep_array[i].clear();
			linker[i].clear();
		}
		for( int i = 2 ; i <= n ; i++ )
			addedge( read() , i );
		dfs( dep[1] = 1 );
		for( int i = 1 ; i <= n ; i++ )
		{
			maxdep = max( dep[i] , maxdep );
			size[ dep[i] ]++;
			dep_array[ dep[ a[i] ] ].push_back( i );
		}
		lim = sqrt( maxdep ) * 0.75;
		for( int i = 1 ; i <= m ; i++ )
		{
			q[i].opt = read() , q[i].a = read();
			if( q[i].opt == 1 )
			{
				q[i].x = read() , q[i].y = ( read() + dep[ q[i].a ] ) % q[i].x , q[i].z = read();
				if( q[i].x <= lim )
					have[ q[i].x ] = 1;
			}
			else
				use[ q[i].a ] = 1 , q[i].x = 0;
		}
		tot = 0;
		for( int i = 1 ; i <= n ; i++ )
			tot += use[i];
		array.assign( tot );
		for( int i = 1 ; i <= n ; i++ )
			if( use[i] )
				array.push_back( i );
		sort( array.v.begin() , array.v.end() , cmp );
		for( int i = 1 ; i <= lim ; i++ )
			if( have[i] )
			{
				for( int j = 1 , now = 1 % i ; j <= maxdep ; j++ )
				{
					block[ now ].size += size[j];
					if( ++now == i ) now = 0;
				}
				for( int j = 0 ; j < i ; j++ )
					block[j].build();
				for( int j = 0 ; j < array.size() ; j++ )
				{
					int x = array[j] , d = dep[x] % i;
					use[x] = block[d].array.size();
					block[d].array.push_back( l[x] );
				}
				for( int j = 1 ; j <= n ; j++ )
					if( q[j].opt == 2 )
						q[j].x += block[ dep[ q[j].a ] % i ].find1( use[ q[j].a ] );
					else if( q[j].x == i )
						block[ q[j].y ].modify1( l[ q[j].a ] , r[ q[j].a ] , q[j].z );
				for( int j = 0 ; j < i ; j++ )
					block[j].clear();
			}
		for( int i = 1 ; i <= n ; i++ )
			block[ dep[i] ].size++;
		for( int i = 1 ; i <= maxdep ; i++ )
			block[i].build();
		for( int i = 1 ; i <= n ; i++ )
		{
			use[ a[i] ] = block[ dep[ a[i] ] ].array.size();
			block[ dep[ a[i] ] ].array.push_back( i );
		}
		for( int i = 1 ; i <= n ; i++ )
		{
			vector < int > & now = dep_array[ dep[i] + 1 ];
			vector < int > :: iterator x = lower_bound( now.begin() , now.end() , l[i] ) , y = upper_bound( now.begin() , now.end() , r[i] );
			if( x == now.end() )
				HLD1.addedge( n + 1 , i );
			else
				HLD1.addedge( a[ * x ] , i );
			if( y == now.begin() || ( * ( y - 1 ) > r[i] ) )
				HLD2.addedge( n + 1 , i );
			else
				HLD2.addedge( a[ * ( y - 1 ) ] , i );
		}
		HLD1.build();
		HLD2.build();
		for( int i = 1 ; i <= m ; i++ )
		{
			if( q[i].opt == 2 )
				q[i].x += block[ dep[ q[i].a ] ].find2( use[ q[i].a ] );
			else if( q[i].x > lim )
			{
				int dep_diff = ( q[i].y - dep[ q[i].a ] % q[i].x + q[i].x ) % q[i].x , v = q[i].z;
				HLD1.LA( q[i].a , dep_diff , q[i].x , L , cnt1 );
				HLD2.LA( q[i].a , dep_diff , q[i].x , R , cnt2 );
				for( int j = 0 ; j < cnt1 ; j++ )
					if( contain( q[i].a , L[j] ) && contain( q[i].a , R[j] ) )
						block[ dep[ L[j] ] ].modify2( use[ L[j] ] , use[ R[j] ] , v );
					else
						break;
			}
		}
		for( int i = 1 ; i <= m ; i++ )
			if( q[i].opt == 2 )
				print( q[i].x , 10 );
	}
	return 0;
}
