import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_11049 {		

	static int[][] dp;
	static int[] matrix;
	public static void main(String[] args) throws Exception {		
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		matrix = new int[n];
		dp = new int[n][n];
		for(int i=0;i<n;i++) {
			String[] s = br.readLine().split(" ");
			matrix[i] = Integer.parseInt(s[0])*1000 + Integer.parseInt(s[1]);
		}
		for(int[] d : dp) {
			Arrays.fill(d, -1);
		}
		System.out.println(go(0,n-1));			
	}
	static int go(int a, int b) {
		if(a==b) return dp[a][b] = 0;
		if(dp[a][b]!=-1) return dp[a][b];		
		int ret = -1;
		for(int k=a;k<=b-1;k++) {
			//x,y,z는 각각 앞행렬 (n,m) 뒤행렬 (m,k)의 n,m,k이다.
			int matX = matrix[a]/1000;
			int matY = matrix[k]%1000;
			int matZ = matrix[b]%1000;
			int tmp = go(a,k) + go (k+1,b) + (matX*matY*matZ);
			if(ret == -1 || ret > tmp) {
				ret = tmp;
			}
		}
		return dp[a][b] = ret;
	}
}