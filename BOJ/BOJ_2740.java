import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_2740 {	
	public static void main(String[] args) throws Exception {			
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] A = new int[n][m];

		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
			}			
		}
		st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[][] B = new int[m][k];
		int[][] C = new int[n][k];
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<k;j++) {
				B[i][j] = Integer.parseInt(st.nextToken());
			}			
		}
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<k;j++) {				
				for(int x=0;x<m;x++) {
					C[i][j] += A[i][x]*B[x][j];
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<k;j++) {
				System.out.print(C[i][j]+ " ");
			}
			System.out.println();
		}
	}
}