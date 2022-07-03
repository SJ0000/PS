import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_5557 {		
	static int[] v;
	static long [][] dp;
	static int n;
	static final int m = 20;
	public static void main(String[] args) throws Exception {		
		//dp[n][s] = n번째에서 숫자 s가 가능한지 check		
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n =Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		v = new int[n+1];
		dp = new long[n+1][m+1];
		for(int i=0;i<n;i++) {
			v[i] = Integer.parseInt(st.nextToken());
		}
		// +-를 붙이기 전인 0번째에서는 v[0]만 가능하다
		dp[0][v[0]] = 1;		
		for(int i=1;i<=n-2;i++) {
			for(int j=0;j<=m;j++) {
				if(dp[i-1][j]>0) {					
					if(j-v[i] >=0 && j-v[i]<=m) {
						dp[i][j-v[i]] += dp[i-1][j];
					}
					if(j+v[i]<=m && j+v[i]>=0) {
						dp[i][j+v[i]] += dp[i-1][j];
					}
				}
			}
		}		
/*		for(long[] d : dp) {
			System.out.println(Arrays.toString(d));
		}*/
		System.out.println(dp[n-2][v[n-1]]);
	}
}