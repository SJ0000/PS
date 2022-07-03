import java.io.*;
import java.util.*;

public class AOJ_TILING2 {
	static final int mod = 1000000007;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(br.readLine());
		int[] dp = new int[101];
		dp[1] = 1;dp[2]=2;
		for(int i=3;i<=100;i++) {
			dp[i] = dp[i-1]%mod+dp[i-2]%mod;
			dp[i]%=mod;
		}		
		while(t-->0) {
			System.out.println(dp[Integer.parseInt(br.readLine())]);
		}		
	}
}