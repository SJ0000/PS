import java.io.*;
import java.util.*;

class Robot{
	int r,c,d;
	Robot(int r ,int c ,int d){
		this.r= r; this.c=c; this.d=d;
	}	
}
public class BOJ_14503 {
	static int[][] map;
	static boolean[][] clear;
	static int m,n;
	static int count=0;
	//0123 合 悼 巢 辑
	static int[] dx = {0, 1, 0, -1};
	static int[] dy = {-1 ,0 , 1, 0};
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		map = new int[50][50];
		clear = new boolean[50][50];
		st = new StringTokenizer(br.readLine());
		int s = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		Robot start = new Robot(s,e,d);
		Queue<Robot> q = new LinkedList<Robot>();
		clear[s][e] = true; count++;
		q.add(start);
		
		while(!q.isEmpty()) {
			Robot pos = q.poll();
			int y = pos.r;
			int x = pos.c;
			int d1 = pos.d;
			int nDir = d1;
			int nx = 0; int ny = 0;
			boolean flag = false;

			//哭率 没家救茄备开 沤祸
			for(int i=0;i<4;i++) {
				nDir = setLeft(nDir);
				nx = x+dx[nDir];
				ny = y+dy[nDir];
				if(0 <= nx && nx < n && 0 <= ny && ny < m) {
					if(map[ny][nx]==0 && !clear[ny][nx]) {
						clear[ny][nx] = true;
						count++;
						q.add(new Robot(ny,nx,nDir));
						flag = true;
						break;
					}					
				}
			}
			if(!flag) {
				nDir = setBack(d1);
				nx = x+dx[nDir];
				ny = y+dy[nDir];
				if(0 <= nx && nx < n && 0 <= ny && ny < m) {
					if(map[ny][nx]==0) {
						q.add(new Robot(ny,nx,d1));
					}
				}
			}			
		}		
		System.out.println(count);
	}
	static int setLeft(int dir) {
		if(dir==0) {
			return 3;
		}else if(dir==1) {
			return 0;
		}else if(dir==2) {
			return 1;
		}else {
			return 2;
		}	
	}
	static int setBack(int dir) {
		if(dir==0) {
			return 2;
		}else if(dir==1) {
			return 3;
		}else if(dir==2) {
			return 0;
		}else {
			return 1;
		}	
	}
}