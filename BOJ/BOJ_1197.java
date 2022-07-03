import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_1197 {	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] p = new int[n+1];
		for(int i=0;i<=n;i++) {
			p[i] = i;
		}
		ArrayList<Edge> li = new ArrayList<Edge>();
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			li.add(new Edge(x,y,z));
		}
		Collections.sort(li, new Compare());
		int ans = 0;
		for(Edge e : li) {
			int x = find(p,e.st);
			int y = find(p,e.ed);
			if(x!=y) {
				disjoint_union(p, e.st,e.ed);
				ans+=e.cost;
			}
		}
		System.out.println(ans);
	}
	static class Compare implements Comparator<Edge>{
		public int compare(Edge one, Edge two) {
			return Integer.compare(one.cost, two.cost);
		}
	}
	//유니온파인드. p[] = parent[i] = i의 루트노드
	public static void disjoint_union(int[] p, int x, int y) {
		x = find(p,x);
		y = find(p,y);
		p[x]=y;
	}
	public static int find(int[] p,int x) {
		//루트가 자기 자신이면 자기자신 호출
		//아닐경우 자기 루트를 찾아가서 루트 호출
		if(x==p[x]) {
			return x;
		}else {
			return (p[x] = find(p,p[x]));
		}
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