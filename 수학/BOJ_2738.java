import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_2738 {	
	public static void main(String[] args) throws Exception {			
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] A = new int[n][m];
		int[][] B = new int[n][m];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
			}			
		}
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				B[i][j] = Integer.parseInt(st.nextToken());
			}			
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				A[i][j] += B[i][j];
				System.out.print(A[i][j] + " ");
			}			
			System.out.println();
		}
	}
}