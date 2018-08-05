import java.io.*;
import java.util.*;

public class BOJ_10986 {	
	//RSQ ДЉРћЧе
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] nm = br.readLine().split(" ");
		int n = Integer.parseInt(nm[0]);
		int m = Integer.parseInt(nm[1]);
		int mCnt[]=new int[1000];
		int[][] C = new int[1000][2];
		int s =0;
		mCnt[0]++;
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			s += Integer.parseInt(st.nextToken());
			s%=m;
			mCnt[s]++;
		}
		long ans = 0;
		//combination dp
		//nCr = n-1Cr-1 + n-1Cr

		for(int k=0;k<m;k++) {
			ans += (mCnt[k]*(mCnt[k]-1))/2;
		}
		System.out.println(ans);
	}
}