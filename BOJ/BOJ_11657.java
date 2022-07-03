import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class BOJ_11657{	
	//38�� �ٿ� dist[x] != Integer.MAX_VALUE �ϳ� �߰� ���ؼ� 1�ð����ȳ�
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		ArrayList<Edge> li = new ArrayList<Edge>();
		boolean[] check = new boolean[n+1];
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			li.add(new Edge(x,y,z));
		}
		int[] dist = new int[n+1];
		Arrays.fill(dist,Integer.MAX_VALUE);
		dist[1]=0;
		boolean hasNCycle=false;
		//���� ����� �ִܰŸ��� ã�´�
		//���ͽ�Ʈ�� ���� �������� ���� ���� : cost�� �����̱� ������
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
		//O(n)
		for(int i=1;i<=n;i++) {
			if(dist[i]==Integer.MAX_VALUE) dist[i]=-1;
		}		
		if(hasNCycle) {
			bw.write(-1 + "\n");
		}else {
			for(int i=2;i<=n;i++) {
				bw.write(dist[i]+"\n");
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