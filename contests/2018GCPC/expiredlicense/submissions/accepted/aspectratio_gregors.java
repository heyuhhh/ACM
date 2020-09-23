import java.util.Scanner;

public class aspectratio_gregors {
	
	final static int MAX_P = 10000001;
	final static int FAC = 100000;
	final static int MAX_N = 100000;
	static boolean s[] = new boolean[MAX_P];
	static int a[] = new int[MAX_N];
	static int b[] = new int[MAX_N];

	static int gcd(int x, int y)
	{
		while (y != 0)
		{
			x %= y;
			int tmp = x;
			x = y;
			y = tmp;
		}
		return x;
	}

	static void eraSieve(int n)
	{
		s[1] = true;
		for (int i = 2; i <= Math.sqrt(n); ++i)
			if (!s[i])
				for (int j = i*i; j <= n; j += i)
					s[j] = true;
	}	

	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int maxAB = -1;
		for (int i = 0; i < n; ++i)
		{
			double x = sc.nextDouble();
			double y = sc.nextDouble();
			a[i] = (int) Math.round(x * FAC);
			b[i] = (int) Math.round(y * FAC);
			int g = gcd(a[i],b[i]);
			a[i] /= g;
			b[i] /= g;
			maxAB = Math.max(maxAB, Math.max(a[i],b[i]));
		}
		sc.close();
		eraSieve(maxAB);
		for (int i = 0; i < n; ++i)
		{
			if (a[i] == 1 && b[i] == 1)
				System.out.println("2 2");
			else if (!s[a[i]] && !s[b[i]])
				System.out.println(a[i] + " " + b[i]);
			else
				System.out.println("impossible");
		}
	}
}
