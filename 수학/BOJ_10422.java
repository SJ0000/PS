import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_10422 {	
	static final long mod = 1000000007;
	public static void main(String[] args) throws Exception {
		//Ä«Å»¶õ ¼ö
		
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = sc.nextInt();
		long[] catalan = new long[5001];
		catalan[0] = 1;
		for(int i=1;i<=5000;i++) {
			for(int j=0;j<=i-1;j++) {
				catalan[i] += catalan[j]*catalan[i-j-1];
				catalan[i]%=mod;
			}
		}
		while(t-->0) {
			int n = sc.nextInt();
			if(n%2==1) {
				System.out.println(0);
			}else {
				System.out.println(catalan[n/2]);
			}
		}				
	}
}