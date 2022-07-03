import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_11402 {	
	public static void main(String[] args) throws Exception {
		//·òÄ«ÀÇ Á¤¸®
		
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] s = br.readLine().split(" ");
		long n = Long.parseLong(s[0]);
		long k = Long.parseLong(s[1]);
		int m = Integer.parseInt(s[2]);
		
		int[][] d = new int[m+1][m+1];
		for(int i=0;i<=m;i++) {
			d[i][0] = d[i][i] = 1;
			for(int j=1;j<=i-1;j++) {
				d[i][j] = d[i-1][j-1]+d[i-1][j];
				d[i][j]%=m;
			}
		}
		ArrayList<Integer> a = new ArrayList<Integer>();
		ArrayList<Integer> b = new ArrayList<Integer>();
		while(n>0 || k>0) {
			a.add((int) (n%m));
			b.add((int) (k%m));
			n/=m; k/=m;
		}
		long ans = 1;
		int sz = a.size();
		for(int i=0;i<sz;i++) {
			ans *=d[a.get(i)][b.get(i)];
			ans%=m;
		}
		System.out.println(ans);		
	}
}