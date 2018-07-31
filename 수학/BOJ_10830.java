import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_10830 {	
	static int n;
	public static void main(String[] args) throws Exception {			
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		long b = Long.parseLong(st.nextToken());
		int[][] A = new int[n][n];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
			}			
		}		
		int[][] ans = getAns(A,b);

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				System.out.print(ans[i][j]%1000+" ");
			}
			System.out.println();
		}
	}
	//분할정복
	static int[][] getAns(int[][] arr , long num){
		if(num==1) {
			return arr;
		}		
		if(num%2==0) {
			int[][] tmp = getAns(arr,num/2);
			return mul(tmp,tmp);
		}else {
			return mul(getAns(arr,num-1),arr);
		}
	}	
	//a랑 b를 곱하는 함수
	static int[][] mul(int[][] a,int[][] b){
		int[][] C = new int[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {				
				for(int x=0;x<n;x++) {
					C[i][j] += (a[i][x]%1000)*(b[x][j]%1000)%1000;
				}
				C[i][j]%=1000;
			}
		}
		return C;
	}
}