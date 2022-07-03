import java.io.*;
import java.util.*;

public class BOJ_11437 {	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		ArrayList<Integer>[] li = new ArrayList[n+1];
		for(int i=0;i<=n;i++) {
			li[i] = new ArrayList<Integer>();
		}
		String[] str;
		boolean[] check = new boolean[n+1];
		for(int i=0;i<n-1;i++) {
			str = br.readLine().split(" ");
			int x = Integer.parseInt(str[0]);
			int y = Integer.parseInt(str[1]);
			li[x].add(y); li[y].add(x);
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

		//1�� root�� �����ϰ� parent�� level�� BFSŽ������ ���Ѵ�
		q.add(1); parent[1] = 1; level[1] = 1;
		check[1] = true;
		while(!q.isEmpty()) {
			int sz = q.size();
			for(int i=0;i<sz;i++) {
				int p = q.poll();
				for(int x : li[p]) {
					if(!check[x]) {
						parent[x] = p;
						level[x] = level[p]+1;
						q.add(x);
						check[x]=true;
					}
				}				
			}			
		}
		for(int i=0;i<m*2;i+=2) {
			int xp = ansList[i];
			int yp = ansList[i+1];
			int xl = level[xp], yl = level[yp];
			//������ �ٸ��� ������ �� ���� ������ ū ���� ��ĭ�� �ø���
			while(xl!=yl) {
				if(xl>yl) {
					xp = parent[xp];
					xl--;
				}else {
					yp = parent[yp];
					yl--;
				}
			}
			//������ �������� ������尡 �� ������ ��ĭ�� �Ƿ� �ø���.
			while(xp!=yp) {
				xp = parent[xp];
				yp = parent[yp];
			}
			System.out.println(xp);			
		}	
	}
}