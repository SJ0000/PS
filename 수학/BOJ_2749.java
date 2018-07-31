import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_2749 {		
	static final int mod = 1000000;
	public static void main(String[] args) throws Exception {	
		//n�� �ʹ� ŭ : �ǻ�� �ֱ� �̿�
		//�ǻ�� �ֱ� : N��° �Ǻ���ġ ���� M���� ���� �������� N%K��° �Ǻ���ġ ���� ����.
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long n = sc.nextLong();	
		long[] fib = new long[1500001];
		fib[0] = 0; fib[1] = 1;
		for(int i=2;i<1500000;i++) {
			fib[i] = fib[i-2]+fib[i-1];
			fib[i]%=mod;
		}
		System.out.println(fib[(int)(n%1500000)]);
	}	
}