import java.io.*;
import java.util.*;
public class AOJ_EDITORWARS {
	static int[] parent,rank,enemy,size; //rank[i]= i가 속한 트리의 높이.
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
			//parent, rank 초기화
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
			//error가 false일 경우 답을 계산해야함
			if(!error) {
				int ret = 0;
				for(int node = 0;node<n;node++) {
					if(parent[node]==node) {
						int e = enemy[node];
						//같은 모임 쌍을 두번 세지 않기 위해 enemy<node일 경우만 센다.
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
	//높이가 더 낮은 트리를 트리를 높은 트리에 합친다.
	//u가 작은트리, v가 큰 트리
	static int union(int u,int v) {
		//u나 v가 공집합인 경우 나머지 하나 반환
		if(u==-1||v==-1) return Math.max(u, v);
		u = find(u);
		v = find(v);
		//이미 같은 트리에 속한 경우
		if(u==v) return u;

		//더 작은 트리를 큰 트리에 합쳐야 하므로 v를 항상 큰 트리로 만들어 준다.
		if(rank[u]>rank[v]) {
			int tmp = u;
			u = v;
			v = tmp;
		}
		//u를 v의 자식으로 넣는다.
		parent[u] = v;
		size[v]+=size[u];
		if(rank[u]==rank[v]) rank[v]++;

		return v;
	}
	static boolean dis(int u,int v) {
		u = find(u); v = find(v);
		//u와 v가 같은집합에 속해있으면 모순이다.
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
		//b는 u와 v의 적을 합친 것이니 u와v를 합친 a의 적이어야 한다.
		enemy[a] = b;
		//두집합 다 적대하는 집합이 없으면 b는 -1일 수도 있음.
		if(b!=-1) {
			enemy[b] = a;
		}
		return true;
	}
}