
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;// 6/30/12 11:56 AM
// by Abrackadabra

public class Sol {
    public static void main(String[] args) throws IOException {
        //if (args.length > 0 && args[0].equals("Abra")||true ) debugMode = true;
        new Sol().run();
        /*new Thread(null, new Runnable() {
            public void run() {
                try {
                    new H().run();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }, "1", 1 << 24).start();*/
    }

    int IOMode = 0; //0 - consoleIO, 1 - <taskName>.in/out, 2 - input.txt/output.txt, 3 - test case generator
    String taskName = "";
    boolean testBasedProblem = false;

    public class Pair<F,S> implements Comparable<Pair<F,S>> {

        public F first;
        public S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        @Override
        @SuppressWarnings(value = "unchecked")
        public int compareTo(Pair<F, S> other) {
            int res = ((Comparable<F>)first).compareTo(other.first);
            if(res != 0)
                return res;
            return ((Comparable<S>)second).compareTo(other.second);
        }
    }

    int n, k;
    int dp[][];
    int pred[][];
    String s;
    int color[];
    int INF=1000000000;
    void solve() throws IOException {
        n=nextInt();
        k=nextInt();
        s=nextString();
        dp=new int [n][k];
        char ans[]=new char[n];
        for (int i=0; i<n; ++i)
            for (int j=0; j<k; ++j)
                dp[i][j]=INF;
        pred=new int [n][k];
        color=new int[n];
        for (int i=0; i<n; ++i)
            color[i]=s.charAt(i)-'A';
        if (k<=2){
            for (int i=0; i<k; ++i){
                if (i==color[0])
                    dp[0][i]=0;
                else
                    dp[0][i]=1;
                pred[0][i]=-1;
            }
            for (int i=1; i<n; ++i)
                for (int col=0; col < k; ++col){
                    for (int last=0; last<k; ++last)
                        if (last != col){
                            if (dp[i-1][last] + ((color[i]==col)?0:1) < dp[i][col]){
                                dp[i][col]=dp[i-1][last] + ((color[i]==col)?0:1);
                                pred[i][col]=last;
                            }
                        }
                }
            int mn=INF;
            for (int i=0; i<k; ++i)
                mn=Math.min(mn, dp[n-1][i]);
            out.println(mn);
            for (int i=0; i<k; ++i)
                if (dp[n-1][i]==mn){
                    int cur=i;
                    for (int pos=n-1; pos>=0; --pos){
                        ans[pos]=(char)('A'+cur);
                        cur=pred[pos][cur];
                    }
                    out.println(ans);
                    break;
                }
        }
        else{
            ans[0]=s.charAt(0);
            int cnt=0;
            for (int i=1; i<n; ++i)
                if (s.charAt(i)==ans[i-1]){
                    for (char c='A'; c<(char)('A'+k); ++c)
                        if (c!=ans[i-1] && (i==n-1 || c!=s.charAt(i+1))){
                            ans[i]=c;
                            ++cnt;
                            break;
                        }
                }
                else
                    ans[i]=s.charAt(i);
            out.println(cnt);
            for (int i=0; i<n; ++i)
                out.print(ans[i]);
        }
    }

    long startTime = System.nanoTime(), tempTime = startTime, finishTime = startTime;
    long startMem = Runtime.getRuntime().totalMemory(), finishMem = startMem;
    int testIndex;

    void run() throws IOException {
        init();
        if (debugMode) {
            con.println("Start");
            con.println("Console:");
        }

        int tests = testBasedProblem ? nextInt() : 1;
        for (testIndex = 1; testIndex <= tests; testIndex++)
            solve();

        finishTime = System.nanoTime();
        finishMem = Runtime.getRuntime().totalMemory();
        out.flush();
        if (debugMode) {
            int maxSymbols = 1000;
            BufferedReader tbr = new BufferedReader(new FileReader("input.txt"));
            char[] a = new char[maxSymbols];
            tbr.read(a);
            if (a[0] != 0) {
                con.println("File input:");
                con.println(a);
                if (a[maxSymbols - 1] != 0) con.println("...");
            }
            tbr = new BufferedReader(new FileReader("output.txt"));
            a = new char[maxSymbols];
            tbr.read(a);
            if (a[0] != 0) {
                con.println("File output:");
                con.println(a);
                if (a[maxSymbols - 1] != 0) con.println("...");
            }
            con.println("Execution time: " + (finishTime - startTime) / 1000000000.0 + " sec");
            con.println("Used memory:    " + (finishMem - startMem) + " bytes");
            con.println("Total memory:   " + Runtime.getRuntime().totalMemory() + " bytes");
        }
    }

    boolean tick(double x) {
        if (System.nanoTime() - tempTime > x * 1e9) {
            tempTime = System.nanoTime();
            con.println("Tick at " + (tempTime - startTime) / 1000000000 + " sec");
            con.print("   ");
            return true;
        }
        return false;
    }

    static boolean debugMode = false;
    PrintStream con = System.out;

    void init() throws IOException {
        if (debugMode && IOMode != 3) {
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter(new FileWriter("output.txt"));
        } else
            switch (IOMode) {
                case 0:
                    br = new BufferedReader(new InputStreamReader(System.in));
                    out = new PrintWriter(System.out);
                    break;
                case 1:
                    br = new BufferedReader(new FileReader(taskName + ".in"));
                    out = new PrintWriter(new FileWriter(taskName + ".out"));
                    break;
                case 2:
                    br = new BufferedReader(new FileReader("input.txt"));
                    out = new PrintWriter(new FileWriter("output.txt"));
                    break;
                case 3:
                    out = new PrintWriter(new FileWriter("input.txt"));
                    break;
            }
        if (!debugMode)
            con = new PrintStream(new OutputStream() {
                public void write(int b) throws IOException {
                } // to /dev/null
            });
        if ((IOMode == 1 && taskName.length() == 0) || (IOMode != 1 && taskName.length() != 0)) {
            System.err.println("Leha, check IO settings");
            System.err.flush();
            System.exit(0);
        }
    }

    BufferedReader br;
    PrintWriter out;
    StringTokenizer in;

    boolean hasMoreTokens() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return false;
            in = new StringTokenizer(line);
        }
        return true;
    }

    String nextString() throws IOException {
        return hasMoreTokens() ? in.nextToken() : null;
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextString());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextString());
    }
}