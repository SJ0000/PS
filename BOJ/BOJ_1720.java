import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_1720 {		

	//대칭포함해서 1개 답 구하고 대칭없는거만 따로 1개더 구해서
	//양쪽 더하고 2로나누면됨
	
	public static void main(String[] args) throws Exception {		
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		long[] a = new long[31];
		long[] d = new long[31];
		
 		a[1] = 1; a[2] = 3;
		for(int i=3;i<=30;i++){
			a[i] = a[i-1] + a[i-2]*2;
		}
		d[1] = 1; d[2] = 3;
		for(int i=3;i<=30;i++) {
			long b = 0;
			if(i%2==1) {
				b = a[(i-1)/2];
			}else {
				b = a[i/2] + 2*a[(i-2)/2];
			}
			d[i] = (a[i]+b)/2;
		}		
		System.out.println(d[n]);
	}
}