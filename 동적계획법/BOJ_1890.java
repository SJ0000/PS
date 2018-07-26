import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_1890 {		
	
	static int n;
	static int[][] board;
	static long[][] dp;
	public static void main(String[] args) throws Exception {		
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		StringTokenizer st;
		board = new int[n][n];
		dp = new long[n][n];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				}
		}
		dp[0][0] = 1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(i==0 && j==0) continue;
				// (i,k+board[i][k]) -> (i,j)
				for(int k=0;k<j;k++) {
					if(k+board[i][k]==j) {
						dp[i][j]+= dp[i][k];
					}
				}
				//(k+a[k][j],j) -> (i,j)
				for(int k=0;k<i;k++) {
					if(k+board[k][j]==i) {
						dp[i][j]+= dp[k][j];
					}
				}
			}
		}
		System.out.println(dp[n-1][n-1]);
	}
}