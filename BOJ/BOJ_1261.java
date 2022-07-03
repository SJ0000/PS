import java.io.*;
import java.util.*;

public class BOJ_1261 {	
	static int[] dx = {0,0,1,-1};
	static int[] dy = {1,-1,0,0};
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] board = new int[m][n];
		int[][] d = new int[m][n];
		for(int[] i : d) {
			Arrays.fill(i, -1);
		}
		for(int i = 0;i<m;i++) {
			char[] c = br.readLine().toCharArray();
			for(int j=0;j<n;j++) {
				board[i][j] = c[j]-'0';
			}			
		}
		Queue<Pos> nowQ = new LinkedList<Pos>();
		Queue<Pos> nextQ = new LinkedList<Pos>();
		nowQ.add(new Pos(0,0));
		d[0][0] = 0;
		while(!nowQ.isEmpty()) {
			Pos now = nowQ.poll();
			int nowX = now.x , nowY = now.y;
			for(int i=0;i<4;i++) {
				int ax = nowX+dx[i];
				int ay = nowY+dy[i];
				if(0<=ax && ax<m && 0<=ay && ay<n) {
					if(d[ax][ay]==-1) {
						if(board[ax][ay]==0) {
							d[ax][ay] = d[nowX][nowY];
							nowQ.add(new Pos(ax,ay));
						}else {
							d[ax][ay] = d[nowX][nowY]+1;
							nextQ.add(new Pos(ax,ay));
						}
					}
				}			
			}
			if(nowQ.isEmpty()) {
				while(!nextQ.isEmpty()) {
					nowQ.add(nextQ.poll());
				}	
			}
		}
		System.out.println(d[m-1][n-1]);		
	}
}
class Pos {
	int x,y;
	Pos(int a,int b){
		x=a;y=b;
	}
}