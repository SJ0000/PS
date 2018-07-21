import java.util.*;
public class Main {
	static boolean[][] isFriend;
	static boolean[] check;	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0){			
			int n = sc.nextInt();
			int m = sc.nextInt();
			isFriend = new boolean[n][n];
			check = new boolean[n];
			for(int i=0;i<m;i++){
				int x = sc.nextInt();
				int y = sc.nextInt();
				isFriend[x][y] = true;
				isFriend[y][x] = true;
			}			
			System.out.println(countPairs(check));			
		}
	}
	static int countPairs(boolean[] taken){
		int first = -1;
		int n = taken.length;
		for(int i=0;i<n;i++){
			if(!taken[i]){
				first = i;
				break;
			}
		}
		if(first==-1){
			return 1;
		}		
		int ret = 0;
		for(int pairWith = first+1 ; pairWith<n;pairWith++){
			if(!taken[pairWith] && isFriend[first][pairWith]){
				taken[first] = taken[pairWith] = true;			
				ret += countPairs(taken);				
				taken[first] = taken[pairWith] = false;
			}			
		}		
		return ret;		
	}	
}