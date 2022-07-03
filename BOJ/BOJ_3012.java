import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_3012 {	
	
/* d[i][j] = i번문자~j번문자 에서 만들 수 있는 괄호의 개수
 * i.....k....j 의 문자가 있을 때 i~k가 괄호 성립한다면
 * d[i+1][k-1]과 d[k+1][j] 또한 괄호가 성립해야한다.
 * 이 작은문제 경우를 곱하면 d[i][j]가 된다.	
*/	
	static char[] open = { '{' , '(' , '[' };
	static char[] close = { '}' , ')' , ']'};
	static long[][] dp;
	static char[] s;
	static int mod = 100000;
	static boolean over;
	public static void main(String[] args) throws Exception {		

		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		s = br.readLine().toCharArray();
		dp = new long[201][201];
		for(long[] l : dp) {
			Arrays.fill(l,-1);
		}
		long ans  = go(0,n-1);

		if(ans==0) {
			System.out.println(ans);
		}else if(over) {
			System.out.printf("%05d\n",ans);
		}else {
			System.out.println(ans);
		}
	}

	static long go(int i,int j) {
		if(i>j) {
			return 1;
		}
		long ans = dp[i][j];
		if(ans!= -1) {
			return ans;
		}
		ans = 0;
		for(int k = i+1;k<=j;k+=2) {
			for(int l = 0 ; l<3;l++) {
				if(s[i]==open[l] || s[i]== '?') {
					if(s[k]==close[l] || s[k]== '?') {
						long temp = go(i+1,k-1)*go(k+1,j);
						if(ans + temp > mod) {
							over = true;
						}
						ans += temp;
						ans%=mod;						
					}					
				}				
			}			
		}	
		return dp[i][j] = ans;
	}
}