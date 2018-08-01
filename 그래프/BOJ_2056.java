import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_2056 {	
	//DAG(Directed Acyclic Graph 위상정렬 응용
	static ArrayList<Integer>[] li,back;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		Queue<Integer> q = new LinkedList<Integer>();
		li = new ArrayList[n+1];
		back = new ArrayList[n+1];
		for(int i=0;i<=n;i++) {
			li[i] = new ArrayList<Integer>();
			back[i] = new ArrayList<Integer>();
		}
		int[] time = new int[n+1];
		int[] inDegree = new int[n+1];
		boolean[] check = new boolean[n+1];
		for(int i=1;i<=n;i++) {
			st = new StringTokenizer(br.readLine());
			time[i] = Integer.parseInt(st.nextToken());
			int preNum = Integer.parseInt(st.nextToken());
			for(int j=0;j<preNum;j++) {
				int pre = Integer.parseInt(st.nextToken());
				li[pre].add(i);
				back[i].add(pre);
				inDegree[i]++;
			}	
		}
		for(int i=1;i<=n;i++) {
			if(inDegree[i]==0) {
				q.add(i);
			}			
		}
		while(!q.isEmpty()) {
			int x = q.poll();
			int xSize = li[x].size();
			for(int i=0;i<xSize;i++) {
				int value = li[x].get(i);
				inDegree[value]--;
				if(inDegree[value]==0) {					
					q.add(value);
					int max = 0;
					for(int tmp : back[value]) {
						max = Math.max(max, time[tmp]);
					}
					time[value]+=max;
				}
			}
		}
		int ans=0;
		for(int tmp : time) {
			ans = Math.max(ans, tmp);
		}
		System.out.println(ans);
	}				
}