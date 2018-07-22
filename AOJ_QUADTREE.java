import java.util.*;

public class Main {

	static int pointer = 0;
	static String qTree;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();
		while(t-->0) {
			pointer = 0;
			qTree = sc.next();
			System.out.println(reverse());			
		}
	}
	public static String reverse() {
		if(qTree.charAt(pointer)!='x') {
			pointer++;
			return qTree.charAt(pointer-1)+"";
		}else {
			pointer++;
			String rev[] = new String[4];
			rev[0] = reverse();
			rev[1] = reverse();
			rev[2] = reverse();
			rev[3] = reverse();
			
			return "x" + rev[2]+rev[3]+rev[0]+rev[1];
		}		
	}
}