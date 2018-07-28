import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_2228 {		

	static int[][] dp;
	static boolean[][] check;
	static int[] arr;
	static int[] sum;
	static int min = -32789*101;
	public static void main(String[] args) throws Exception {		
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String[] s = br.readLine().split(" ");
		int n = Integer.parseInt(s[0]);
		int m = Integer.parseInt(s[1]);
				
		dp = new int[n+1][m+1];
		check = new boolean[n+1][m+1];
		arr = new int[n+1];
		sum = new int[n+1];
		for(int i=1;i<=n;i++) {			
			arr[i] = Integer.parseInt(br.readLine());
			sum[i] = sum[i-1]+arr[i];
		}

		System.out.println(go(n,m));			
	}
	static int go(int n, int m) {
		
		if(m==0) return 0; // m개의 구간이 모두 있는 경우
		if(n<=0) return min; // 더 이상 사용할 수가 존재하지 않음
		if(check[n][m]) return dp[n][m];
		check[n][m] = true;
		// n번째 수를 포함하지 않는 경우
		// 점화식 : d[i][j] = d[i-1][j]
		int ret = go(n-1,m);
		//n번째 수를 포함하는 경우
		// 점화식 : d[i][j] = d[k-2][j-1] + arr[k]~arr[j]의 합	
		for(int i=1;i<=n;i++) {
			int tmp = go(i-2,m-1) + sum[n] -sum[i-1];
			ret = Math.max(ret, tmp);
		}
		return dp[n][m] = ret;		
	}
}