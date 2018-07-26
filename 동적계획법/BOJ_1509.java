import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_1509 {		
	static boolean[][] check;
	static int[] a,d;
	static int n;
	public static void main(String[] args) throws Exception {		
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		n = s.length();
		a = new int[n+1];
		d = new int[n+1];
		check = new boolean[n+1][n+1];
		char[] ch = s.toCharArray();
		for(int i=1;i<=n;i++) {
			a[i] = ch[i-1]-'A';
		}

		for(int i=1;i<=n;i++) {
			check[i][i] = true;
		}
		for(int i=1;i<n;i++) {
			if(a[i]==a[i+1]) {
				check[i][i+1] = true;
			}
		}
		for(int k=2;k<n;k++) {
			for(int i=1;i<=n-k;i++) {
				int j = i+k;
				check[i][j] = a[i]==a[j] && check[i+1][j-1];
			}
		}
		
		for(int i=1;i<=n;i++) {
			d[i] = -1;
			for(int j=1;j<=i;j++) {
				if(check[j][i]) {
					if(d[i]==-1 || d[i]>d[j-1]+1) {
						d[i] = d[j-1]+1;
					}
				}
			}
		}
		System.out.println(d[n]);		
	}	
}