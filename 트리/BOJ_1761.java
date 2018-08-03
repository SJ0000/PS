import java.io.*;
import java.util.*;

class Edge{
	int to, cost;
	Edge(int x,int y){
		to = x; cost = y;
	}
}
public class BOJ_1761 {	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		ArrayList<Edge>[] li = new ArrayList[n+1];
		for(int i=0;i<=n;i++) {
			li[i] = new ArrayList<Edge>();
		}
		String[] str;
		boolean[] check = new boolean[n+1];
		for(int i=0;i<n-1;i++) {
			str = br.readLine().split(" ");
			int x = Integer.parseInt(str[0]);
			int y = Integer.parseInt(str[1]);
			int cost = Integer.parseInt(str[2]);
			li[x].add(new Edge(y,cost)); li[y].add(new Edge(x,cost));
		}
		int m = Integer.parseInt(br.readLine());
		int[] ansList = new int[m*2];
		for(int i=0;i<m*2;i+=2) {
			str = br.readLine().split(" ");
			ansList[i] = Integer.parseInt(str[0]);
			ansList[i+1] = Integer.parseInt(str[1]);
		}
		int[] parent = new int[n+1];
		int[] level = new int[n+1];
		Queue<Integer> q = new LinkedList<Integer>();

		//1을 root로 설정하고 parent와 level을 BFS탐색으로 구한다
		int[] dist = new int[n+1]; // dist : parent까지 올라가는 거리
		q.add(1); parent[1] = 1; level[1] = 1;
		check[1] = true;
		while(!q.isEmpty()) {
			int sz = q.size();
			for(int i=0;i<sz;i++) {
				int p = q.poll();
				for(Edge e : li[p]) {
					int x = e.to;
					if(!check[x]) {
						parent[x] = p;
						level[x] = level[p]+1;
						dist[x] = e.cost;
						q.add(x);
						check[x]=true;
					}
				}				
			}			
		}
		for(int i=0;i<m*2;i+=2) {
			int length = 0;
			int xp = ansList[i];
			int yp = ansList[i+1];
			int xl = level[xp], yl = level[yp];
			//레벨이 다르면 같아질 때 까지 레벨이 큰 것을 한칸씩 올린다
			while(xl!=yl) {
				if(xl>yl) {
					length+=dist[xp];
					xp = parent[xp];
					xl--;
				}else {
					length+=dist[yp];
					yp = parent[yp];
					yl--;
				}
			}
			//레벨이 같아지면 같은노드가 될 때까지 한칸씩 위로 올린다.
			while(xp!=yp) {
				length+=dist[xp];
				length+=dist[yp];
				xp = parent[xp];
				yp = parent[yp];
			}
			System.out.println(length);			
		}	
	}
}