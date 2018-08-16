import java.io.*;
import java.util.*;
public class BOJ_14501 {
	static int[] t,p;
	static int n;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		n = Integer.parseInt(br.readLine());
		t = new int[n];
		p = new int[n];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			t[i] = Integer.parseInt(st.nextToken());
			p[i] = Integer.parseInt(st.nextToken());
		}
		int x = go(0,true);
		int y = go(0,false);
		System.out.println(Math.max(x, y));
	}
	static int go(int i,boolean choice) {
		int ret = 0;
		if(i>=n) {
			return 0;
		}
		if(choice) {
			if(i+t[i]<=n) {
				ret+=p[i];
			}
			ret += Math.max(go(i+t[i],true), go(i+t[i],false));
		}else {
			ret += Math.max(go(i+1,true), go(i+1,false));
		}
		return ret;
	}
}