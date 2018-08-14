import java.io.*;
import java.util.*;

public class BOJ_14502 {
	static int[][] origin,temp,copy;
	static int virus = 0;
	static int m,n;
	static int[] dx = {0,0,1,-1};
	static int[] dy = {1,-1,0,0};
	static int max = -1;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		m = sc.nextInt();
		n = sc.nextInt();
		origin = new int[m][n];
		temp = new int[m][n];
		copy = new int[m][n];
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				origin[i][j] = sc.nextInt();
			}
		}
		temp = copy(origin);
		for (int i = 0; i < n * m; i++) {
	        int c = (int) (i / (n * 1.0));
	        int r = i % n;	 
	        if (temp[c][r] == 0) {
	            temp[c][r] = 1;
	            dfs(i, 1);
	            temp[c][r] = 0;
	        }
	    }
	    System.out.println(max);	
	}	
	//3개고르는함수
	static void dfs(int v,int count) {
		int c = (int)(v/(n*1.0));
		int r = v%n;
		
		if(count==3) {
			copy = copy(temp);
			int safe = spread(copy);
			max = Math.max(safe, max);			
		}else {
			for(int i=v+1;i<n*m;i++) {
				int cc = (int)(i/(n*1.0));
				int rr = i%n;
				if(temp[cc][rr]==0) {
					temp[cc][rr]=1;
					dfs(i,count+1);
				}
			}
		}
		//백트래킹
		temp[c][r]=0;
		--count;
	}
	static int spread(int[][] arr) {
		int ret = 0;
		Queue<Integer> q = new LinkedList<Integer>();
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<arr[0].length;j++) {
				if(arr[i][j]==2) {
					q.add(i*10+j);
				}
			}
		}
		while(!q.isEmpty()) {
			int pos = q.poll();
			int x = pos/10;
			int y = pos%10;
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(0<=nx&&nx<m&&0<=ny&&ny<n) {
					if(arr[nx][ny]==0) {
						arr[nx][ny]=2;
						q.add(nx*10+ny);
					}
				}
			}			
		}
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(arr[i][j]==0) {
					ret++;
				}
			}
		}
		return ret;
	}
	
	static int[][] copy(int[][] org){
		int[][] temp = new int[m][n];
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				temp[i][j] = org[i][j];
			}
		}
		return temp;
	}
}