import java.io.*;
import java.util.*;

class Tetris{
	int[] dx = new int[4];
	int[] dy = new int[4];	
	Tetris(int x1,int y1,int x2,int y2, int x3,int y3,int x4,int y4) {
		dx[0] = x1;dx[1] = x2;dx[2] = x3;dx[3] = x4;
		dy[0] = y1;dy[1] = y2;dy[2] = y3;dy[3] = y4; 
	}	
}
public class BOJ_14500 {	
	static int m,n;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt(); m = sc.nextInt();
		int[][] board = new int[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				board[i][j] = sc.nextInt();
			}
		}		
		ArrayList<Tetris> li = new ArrayList<Tetris>();

		li.add(new Tetris(0,0,0,1,0,2,0,3));
		li.add(new Tetris(0,0,1,0,2,0,3,0));
		li.add(new Tetris(0,0,0,1,1,0,1,1));
		li.add(new Tetris(0,0,1,0,2,0,2,1));
		li.add(new Tetris(0,0,1,0,1,-1,1,-2));

		li.add(new Tetris(0,0,0,1,1,1,2,1));
		li.add(new Tetris(0,0,0,1,0,2,1,0));
		li.add(new Tetris(0,0,1,0,2,0,2,-1));
		li.add(new Tetris(0,0,0,1,0,2,1,2));
		li.add(new Tetris(0,0,0,1,1,0,2,0));

		li.add(new Tetris(0,0,1,0,1,1,1,2));
		li.add(new Tetris(0,0,1,0,1,1,1,-1));
		li.add(new Tetris(0,0,1,0,1,1,2,0));
		li.add(new Tetris(0,0,0,1,0,2,1,1));
		li.add(new Tetris(0,0,1,0,2,0,1,-1));

		li.add(new Tetris(0,0,1,0,1,1,2,1));
		li.add(new Tetris(0,0,0,1,1,-1,1,0));
		li.add(new Tetris(0,0,1,0,1,-1,2,-1));
		li.add(new Tetris(0,0,0,1,1,1,1,2));

		int tmp = 0, max=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				int num = 1;
				for(Tetris t : li) {
					tmp = 0;
					if(!check(i,j,t)) {
						continue;
					}							
					for(int x=0;x<4;x++) {
						int ax = i+t.dx[x];
						int ay = j+t.dy[x];
						tmp += board[ax][ay];
					}
					max = Math.max(tmp, max);
				}
				
			}
		}	
		System.out.println(max);
	}
	static boolean check(int i, int j, Tetris t) {
		int ax,ay;
		for(int x=0;x<4;x++) {
			ax = i + t.dx[x];
			ay = j + t.dy[x];
			if(!(0<=ax&&ax<n&&0<=ay&&ay<m)) {
				return false;
			}
		}		
		return true;
	}
}