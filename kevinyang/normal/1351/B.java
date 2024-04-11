import java.util.*;
import java.io.*;
public class B1351 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t  = readInt();
		while(t--!=0) {
			int a = readInt(); int b = readInt();
			int c = readInt(); int d = readInt();
			if(a==c&b+d==c){
				pr.println("YES");
			}
			else if(a==d&b+c==a) {
				pr.println("YES");
			}
			else if(b==c&a+d==b) {
				pr.println("YES");
			}
			else if(b==d&a+c==d) {
				pr.println("YES");
			}
			else {
				pr.println("NO");
			}
		}
		pr.close();
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}