import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class BOJ_1865 {	
	//boj11657 타임머신 과 유사
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int t = Integer.parseInt(br.readLine());
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			ArrayList<Edge> li = new ArrayList<Edge>();
			boolean[] check = new boolean[n+1];
			for(int i=0;i<m;i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int z = Integer.parseInt(st.nextToken());
				//도로는 방향이 없다
				li.add(new Edge(x,y,z));
				li.add(new Edge(y,x,z));
			}
			for(int i=0;i<w;i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int z = Integer.parseInt(st.nextToken());
				li.add(new Edge(x,y,-z));
			}			
			int[] dist = new int[n+1];
			Arrays.fill(dist,Integer.MAX_VALUE);
			dist[1]=0;
			boolean hasNCycle=false;
			//벨만 포드로 최단거리를 찾는다
			//다익스트라 말고 벨만포드 쓰는 이유 : cost가 음수이기 때문에
			for(int i=1;i<=n;i++) {
				for(Edge e : li) {
					int x = e.st; int y = e.ed; int z = e.cost;
					if(dist[x]!= Integer.MAX_VALUE && dist[y] > dist[x]+z) {
						dist[y] = dist[x]+z;
						if(i==n) {
							hasNCycle = true;
						}
					}
				}
			}		
			if(hasNCycle) {
				bw.write("YES\n");
			}else {
				bw.write("NO\n");
			}
		}			
		bw.flush();
		br.close();
		bw.close();
	}
}
class Edge{
	public int st;
	public int ed;
	public int cost;
	public Edge() {
		this(0,0,0);
	}
	public Edge(int a,int b,int c ) {
		st = a;
		ed = b;
		cost = c;
	}
}