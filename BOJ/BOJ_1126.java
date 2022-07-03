import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class  BOJ_1126 {	
	//어렵다
	// 다시 봐야할듯 나중에
	static int[][] dp;
	static int[] block;
	static int n;
	static final int ninf = Integer.MIN_VALUE;
	public static void main(String[] args) throws Exception {		

		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		dp = new int[50][250001];
		for(int[] d : dp) {
			Arrays.fill(d,-1);
		}
		n = Integer.parseInt(br.readLine());
		block = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			block[i] = Integer.parseInt(st.nextToken());
		}
		int ans = go(0,0);
		
		System.out.println(ans>0 ? ans : -1);

	}
	static int go(int k, int diff) {
		if(diff>250000) {
			return ninf;
		}
		if(k==n) {
			if(diff==0) {
				return 0;
			}else {
				return ninf;
			}
		}
		int ans = dp[k][diff];
		if(ans!=-1) {
			return ans;
		}
		//조각을 사용하지 않는 경우
		ans = go(k+1,diff);
		//높은탑에 조각을 놓는 경우
		ans = Math.max(ans,go(k+1,diff+block[k]));
		//낮은 탑에 조각을 놓는 경우
		if(block[k]>diff) {
			ans = Math.max(ans, diff+go(k+1,block[k]-diff));
		}else {
			ans = Math.max(ans, block[k]+go(k+1,diff-block[k]));
		}		
		return dp[k][diff] = ans;
	}
}