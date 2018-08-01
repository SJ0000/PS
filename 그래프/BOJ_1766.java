import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_1766 {	
	//DAG(Directed Acyclic Graph 위상정렬	
	static ArrayList<Integer>[] li;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		PriorityQueue<Integer> q = new PriorityQueue<Integer>();
		li = new ArrayList[n+1];
		for(int i=0;i<=n;i++) {
			li[i] = new ArrayList<Integer>();
		}
		int[] inDegree = new int[n+1];
		boolean[] check = new boolean[n+1];
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			li[x].add(y);
			inDegree[y]++;
		}
		for(int i=1;i<=n;i++) {
			if(inDegree[i]==0) {
				q.add(i);
				check[i] = true;
			}			
		}
		while(!q.isEmpty()) {
			int x = q.poll();
			System.out.print(x+" ");
			int xSize = li[x].size();
			for(int i=0;i<xSize;i++) {
				int value = li[x].get(i);
				inDegree[value]--;
				if(inDegree[value]==0) {
					q.add(value);
					check[value]=true;					
				}
			}
		}	
	}				
}