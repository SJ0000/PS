import java.util.*;

public class Main {	
	static int[][] board;
	static int[][] check;
	static int n;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0) {
			n = sc.nextInt();
			board = new int[n][n];
			check = new int[n][n];
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					board[i][j] = sc.nextInt();
				}
			}
			go(0,0);
			if(check[n-1][n-1]==0) {
				System.out.println("NO");
			}else {
				System.out.println("YES");
			}
		}
	}
	static void go(int x, int y){
		if(check[x][y]==1) return;
		check[x][y] = 1;		
		int g = board[x][y];		
		if(x+g<n) {
			go(x+g,y);
		}
		if(y+g<n) {
			go(x,y+g);
		}		
	}
}