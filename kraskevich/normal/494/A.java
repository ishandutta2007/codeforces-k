import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.io.InputStreamReader;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Igor Kraskevich
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        char[] s = in.next().toCharArray();
        int bal = 0;
        int n = s.length;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '(')
                bal++;
            else if (s[i] == ')')
                bal--;
            else
                cnt++;
        if (bal < cnt) {
            out.println(-1);
            return;
        }
        int sum = bal;
        int c = 0;
        bal = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                bal++;
            else if (s[i] == ')')
                bal--;
            else {
                if (c != cnt - 1)
                    bal--;
                else
                    bal -= sum - cnt + 1;
                c++;
            }
            if (bal < 0) {
                out.println(-1);
                return;
            }
        }
        if (bal != 0) {
            out.println(-1);
            return;
        }
        for (int i = 0; i < cnt - 1; i++)
            out.println(1);
        out.println(sum - cnt + 1);
    }
}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line = null;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                // ignore
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

}