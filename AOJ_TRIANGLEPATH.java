import java.util.*;

public class Main {	
	static int[][] tri;
	static int[][] dp;
	static int n;
	public static void main(String[] args) {		
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int T = 0;
		while(t-->0) {
			n = sc.nextInt();
			tri = new int[n][n];
			dp = new int[n][n];
			for(int i=0;i<n;i++) {
				for(int j=0;j<=i;j++) {
					tri[i][j] = sc.nextInt();
				}
			}
			dp[0][0] = tri[0][0];
			for(int i=0;i<n-1;i++) {
				for(int j=0;j<=i;j++) {
					dp[i+1][j] = Math.max(dp[i+1][j], dp[i][j]+tri[i+1][j]);
					dp[i+1][j+1] = Math.max(dp[i+1][j+1], dp[i][j]+tri[i+1][j+1]);
				}
			}			
			Arrays.sort(dp[n-1]);
			System.out.println(dp[n-1][n-1]);
		}
	}
}