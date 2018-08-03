import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class BOJ_1916 {	
	//���ͽ�Ʈ�� 
	static final int inf = 1000000000;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		ArrayList<Edge>[] li = new ArrayList[n+1];
		for(int i=1;i<=n;i++) {
			li[i] = new ArrayList<Edge>();
		}
		boolean[] check = new boolean[n+1];

		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			li[x].add(new Edge(y,z));
		}
		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());
		int[] dist = new int[n+1];
		Arrays.fill(dist,inf);
		dist[start]=0;
		for(int k=0;k<n-1;k++) {
			m = inf+1;
			int x = -1;
			//check[i]==false �̸鼭 dist[i]�� ���� ���� ���� ����
			for(int i=1;i<=n;i++) {
				if(!check[i] && m>dist[i]) {
					m = dist[i];
					x=i;
				}
			}
			check[x] = true;
			//x�� ����� ������ ������� dist ���� �����Ѵ�
			for(Edge edge : li[x]) {
				int y = edge.to;
				if(dist[y]>dist[x] + edge.cost) {
					dist[y] = dist[x] + edge.cost;
				}				
			}			
		}
		System.out.println(dist[end]);
	}
}
class Edge{
	int to,cost;
	public Edge(int a, int b ) {
		to = a;
		cost = b;
	}
}