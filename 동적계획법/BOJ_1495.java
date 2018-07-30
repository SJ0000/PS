import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_1495 {		
	static int[] v;
	static boolean [][] dp;
	static int n,s,m;
	public static void main(String[] args) throws Exception {
		//전체 탐색을 하면 O(2^n)이라 안됨
		//dp[n][s] = n번째에서 볼륨 s가 가능한지 check		
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] str = br.readLine().split(" ");
		n =Integer.parseInt(str[0]);
		s = Integer.parseInt(str[1]);
		m = Integer.parseInt(str[2]);
		StringTokenizer st = new StringTokenizer(br.readLine());
		v = new int[n+1];
		dp = new boolean[n+1][m+1];
		for(int i=1;i<=n;i++) {
			v[i] = Integer.parseInt(st.nextToken());
		}
		dp[0][s] = true;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<=m;j++) {
				if(dp[i-1][j]) {					
					if(j-v[i] >=0) {
						dp[i][j-v[i]] = true;
					}
					if(j+v[i]<=m) {
						dp[i][j+v[i]] = true;
					}
				}
			}
		}
		int ans = -1;
		for(int i=m;i>=0;i--) {
			if(dp[n][i]) {
				ans = i;
				break;
			}
		}		
		System.out.println(ans);
	}
}