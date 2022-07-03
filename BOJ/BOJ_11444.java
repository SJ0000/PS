import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_11444 {	
	static final long mod = 1000000007;
	public static void main(String[] args) throws Exception {
		/* 피보나치 수 행렬 원리
		 * (Fn+1 Fn) =  (1 1)^n
		 * (Fn Fn-1)    (1 0)
		 */
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long n = Long.parseLong(br.readLine());
		long[][] A = {{1,1},{1,0}};		
		long[][] ans = getAns(A,n);
		
		System.out.println(ans[1][0]);
	}
	
	//분할정복
	static long[][] getAns(long[][] arr , long num){
		if(num==1) {
			return arr;
		}		
		if(num%2==0) {
			long[][] tmp = getAns(arr,num/2);
			return mul(tmp,tmp);
		}else {
			return mul(getAns(arr,num-1),arr);
		}
	}	
	//a랑 b를 곱하는 함수
	static long[][] mul(long[][] a,long[][] b){
		int n = a.length;
		int r = a[0].length;
		int m = b[0].length;
		long[][] C = new long[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {				
				for(int x=0;x<r;x++) {
					C[i][j] += (a[i][x]%mod)*(b[x][j]%mod)%mod;
				}
				C[i][j]%=mod;
			}
		}
		return C;
	}
}