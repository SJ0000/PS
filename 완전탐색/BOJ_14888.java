import java.io.*;
import java.util.*;

public class BOJ_14888 {
	static int n,max,min;
	static int[] ops,num;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		num = new int[n];
		max = Integer.MIN_VALUE;
		min = Integer.MAX_VALUE;
		//0 1 2 3 :  + - * /
		int[] op = new int[4];
		boolean[] isPick = new boolean[n];
		String[] temp = br.readLine().split(" ");
		for(int i=0;i<n;i++) {
			num[i] = Integer.parseInt(temp[i]);
		}
		temp = br.readLine().split(" ");
		for(int i=0;i<4;i++) {
			op[i] = Integer.parseInt(temp[i]);
		}
		//각 연산자를 나열한 배열
		ops = setOps(op);
		ArrayList<Integer> li = new ArrayList<Integer>();
		next_permutation(li,isPick);
		System.out.println(max);
		System.out.println(min);
	}	
	static void next_permutation(ArrayList<Integer> picked, boolean[] isPick) {
		if(picked.size()==n-1) {
			//최소 최대값 계산.
			int temp=num[0];
			for(int i=0;i<n-1;i++) {
				int op = ops[picked.get(i)];
				if(op==0) {
					temp += num[i+1];
				}else if(op==1) {
					temp -= num[i+1];
				}else if(op==2) {
					temp *= num[i+1];
				}else {
					temp /= num[i+1];
				}
			}
			max = Math.max(max,temp);
			min = Math.min(min,temp);
		}
		for(int next = 0;next<n-1;next++) {
			//골라진 원소면 다음거로 넘어감
			if(isPick[next]) {
				continue;
			}
			picked.add(next);
			isPick[next] = true;
			next_permutation(new ArrayList<Integer>(picked),isPick);
			
			//가장 마지막에 선택된 원소를 지운다
			picked.remove(picked.size()-1);
			isPick[next] = false;			
		}			
	}	
	static int[] setOps(int[] op) {
		int[] ops = new int[n-1];
		int idx = 0;
		for(int i=0;i<4;i++) {
			for(int j=0;j<op[i];j++) {
				ops[idx++] = i; 
			}
		}
		return ops;
	}	
}