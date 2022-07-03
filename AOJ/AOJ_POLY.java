import java.io.*;
import java.util.*;

public class AOJ_POLY {
	static int dp[][];
	static final int mod = 10000000;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(br.readLine());
		dp = new int[101][101];
		for(int[] d : dp) {
			Arrays.fill(d,-1);
		}
		while(t-->0) {
			int x = Integer.parseInt(br.readLine());
			int ans = 0;
			for(int i=1;i<=x;i++) {
				ans += poly(x,i);
				ans%=mod;
			}
			System.out.println(ans);
		}		
	}
	static int poly(int n,int first) {
		//±âÀú»ç·Ê
		if(n==first) {
			return 1;
		}
		//memoization
		if(dp[n][first]!=-1) {
			return dp[n][first];
		}
		int ret = 0;
		for(int second=1;second<=n-first;second++) {
			int add = first+second-1;
			add *= poly(n-first,second);
			add%=mod; ret+=add; ret%=mod;
		}		
		return dp[n][first] = ret;
	}
}