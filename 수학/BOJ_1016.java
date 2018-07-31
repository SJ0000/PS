import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_1016 {	
	public static void main(String[] args) throws Exception {			
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long st = sc.nextLong();
		long ed = sc.nextLong();
		boolean[] a = new boolean[(int)(ed-st+1)];
		//첫번째 for문 대신에 에라토스테네스 체로 소수만 구하면 더 빨리 계산 가능할거같다
		for(long i = 2 ; i*i<=ed;i++) {
			long w = i*i - st%(i*i);
			if(w==i*i) {
				w=0;
			}
			while(w <= ed - st) {
				a[(int) w] = true;
				w += i*i;
			}			
		}
		int ans = 0;
		for(int i=0;i<=ed-st;i++) {
			if(!a[i]) ans++;
		}
		System.out.println(ans);
	}
}