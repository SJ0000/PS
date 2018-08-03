import java.io.*;
import java.util.*;

public class BOJ_1806 {	
	//투포인터
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int s = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[] arr = new int[n];
		for(int i=0;i<n;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int l = 0, r=0;
		int sum = arr[0];
		ArrayList<Integer> li = new ArrayList<Integer>();
		while(l<=r) {
			if(sum<s) {
				r++;
				if(r==n) break;
				sum+=arr[r];
			}else{
				li.add(r-l+1);
				sum-=arr[l];
				l++;
			}			
		}
		Collections.sort(li);
		if(li.isEmpty()) {
			System.out.println(0);
		}else {
			System.out.println(li.get(0));
		}
	}
}