import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_2240 {		

	static int[][] dp;	
	static int[] a;
	static int n,m;
	public static void main(String[] args) throws Exception {		
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String[] s = br.readLine().split(" ");
		n = Integer.parseInt(s[0]);
		m = Integer.parseInt(s[1]);
		dp = new int[n+1][m+1];
		a = new int[n+1];
		for(int[] d : dp) {
			Arrays.fill(d,-1);
		}
		for(int i=1;i<=n;i++) {
			a[i] = Integer.parseInt(br.readLine());
		}
		
		System.out.println(Math.max(go(1,0), go(1,1)));
					
	}
	static int go(int sec, int turn) {		
		if(sec ==n+1 && turn <=m) return 0;
		if(turn >m) return 0;
		if(dp[sec][turn] != -1) return dp[sec][turn];
		
		int ret = 0;
		int position = turn%2 +1; 
		ret = Math.max(go(sec+1,turn), go(sec+1,turn+1)) + (position == a[sec] ? 1 : 0);
		
		return dp[sec][turn] = ret;
	}
}