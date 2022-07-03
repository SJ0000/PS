//이해가 더 필요함 (18.07.23)
import java.util.*;

public class Main {		
	static final long NEGINF = Long.MIN_VALUE;
	static int n,m,A[],B[];
	static int[][] cache;
	public static void main(String[] args) {		
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0) {
			cache = new int[101][101];			
			n = sc.nextInt();
			m = sc.nextInt();			
			A = new int[n];
			B = new int[m];
			for(int i=0;i<101;i++) {
				Arrays.fill(cache[i],-1);
			}
			for(int i=0;i<n;i++) {
				A[i] = sc.nextInt();
			}
			for(int i=0;i<m;i++) {
				B[i] = sc.nextInt();
			}
			System.out.println(jlis(-1,-1)-2);
		}		
	}
	static int jlis(int indexA,int indexB) {
		if(cache[indexA+1][indexB+1] != -1) return cache[indexA+1][indexB+1];		
		long a = indexA == -1 ? NEGINF : A[indexA];
		long b = indexB == -1 ? NEGINF : B[indexB];	
		int ret = 2;
		long maxElement = Math.max(a,b);
		for(int nextA = indexA+1;nextA<n;nextA++) {
			if(maxElement <A[nextA]) {
				ret = Math.max(ret, jlis(nextA,indexB)+1);
			}			
		}
		for(int nextB = indexB+1;nextB<m;nextB++) {
			if(maxElement <B[nextB]) {
				ret = Math.max(ret, jlis(indexA,nextB)+1);
			}
		}		
		return cache[indexA+1][indexB+1] = ret;		
	}
}