import java.io.*;
import java.util.*;
public class AOJ_EDITORWARS {
	static int[] parent,rank,enemy,size; //rank[i]= i�� ���� Ʈ���� ����.
	static boolean error;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringTokenizer st;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			//parent, rank �ʱ�ȭ
			parent = new int[n];
			rank = new int[n];
			enemy = new int[n];
			size = new int[n];
			int errorCnt = 0;
			error = false;
			Arrays.fill(rank,0);
			Arrays.fill(enemy, -1);
			Arrays.fill(size,1);
			for(int i=0;i<n;i++) {
				parent[i] = i;
			}
			for(int i=0;i<k;i++) {
				st = new StringTokenizer(br.readLine());
				String cmd = st.nextToken();
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				if(cmd.equals("ACK")) {
					if(!ack(x,y)) {
						error = true;
						errorCnt = i+1;
					}
				}else {
					if(!dis(x,y)) {
						error = true;
						errorCnt = i+1;
					}
				}
			}
			//error�� false�� ��� ���� ����ؾ���
			if(!error) {
				int ret = 0;
				for(int node = 0;node<n;node++) {
					if(parent[node]==node) {
						int e = enemy[node];
						//���� ���� ���� �ι� ���� �ʱ� ���� enemy<node�� ��츸 ����.
						if(e>node)continue;
						int mySize = size[node];
						int enemySize = (e== -1 ? 0 : size[e]);
						ret += Math.max(mySize, enemySize);
					}
				}
				System.out.println("MAX PARTY SIZE IS " + ret);			
			}else {
				System.out.println("CONTRADICTION AT " + errorCnt);
			}			
		}
	}
	static int find(int u) {
		if(u==parent[u]) {
			return u;
		}
		return parent[u] = find(parent[u]);
	}
	//���̰� �� ���� Ʈ���� Ʈ���� ���� Ʈ���� ��ģ��.
	//u�� ����Ʈ��, v�� ū Ʈ��
	static int union(int u,int v) {
		//u�� v�� �������� ��� ������ �ϳ� ��ȯ
		if(u==-1||v==-1) return Math.max(u, v);
		u = find(u);
		v = find(v);
		//�̹� ���� Ʈ���� ���� ���
		if(u==v) return u;

		//�� ���� Ʈ���� ū Ʈ���� ���ľ� �ϹǷ� v�� �׻� ū Ʈ���� ����� �ش�.
		if(rank[u]>rank[v]) {
			int tmp = u;
			u = v;
			v = tmp;
		}
		//u�� v�� �ڽ����� �ִ´�.
		parent[u] = v;
		size[v]+=size[u];
		if(rank[u]==rank[v]) rank[v]++;

		return v;
	}
	static boolean dis(int u,int v) {
		u = find(u); v = find(v);
		//u�� v�� �������տ� ���������� ����̴�.
		if(u==v) {			
			return false;
		}		
		int a = union(u,enemy[v]);
		int b = union(v,enemy[u]);
		enemy[a] = b; enemy[b] = a;
		return true;
	}
	static boolean ack(int u, int v) {
		u = find(u); v = find(v);
		if(enemy[u]==v) {
			return false;
		}
		int a =  union(u,v), b = union(enemy[u],enemy[v]);
		//b�� u�� v�� ���� ��ģ ���̴� u��v�� ��ģ a�� ���̾�� �Ѵ�.
		enemy[a] = b;
		//������ �� �����ϴ� ������ ������ b�� -1�� ���� ����.
		if(b!=-1) {
			enemy[b] = a;
		}
		return true;
	}
}