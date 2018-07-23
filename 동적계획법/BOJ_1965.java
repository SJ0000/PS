// lis ¹®Á¦
import java.util.*;

public class Main {		
	public static void main(String[] args) {		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ans = 0;
		int[] arr = new int[n+1];
		int[] dp = new int[n+1];
		dp[0] = 1;
		for(int i=1;i<=n;i++) {
			arr[i] = sc.nextInt();
			dp[i] = 1;
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<i;j++) {
				if(arr[j]<arr[i]) {
					dp[i] = Math.max(dp[j]+1, dp[i]);
				}				
			}
			ans = Math.max(ans, dp[i]);
		}
		System.out.println(ans);
	}
}