import java.util.*;
public class Main {
	
	static int[][] sw = {
			{0,1,2,-1,-1},
			{3,7,9,11,-1},
			{4,10,14,15,-1},
			{0,4,5,6,7},
			{6,7,8,10,12},
			{0,2,14,15,-1},
			{3,14,15,-1,-1},
			{4,5,7,14,15},
			{1,2,3,4,5},
			{3,4,5,9,13}			
	};
	static int[] clock;
	static final int MAX = 9999;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		clock = new int[16];
		int t = sc.nextInt();
		while(t-->0){
			for(int i=0;i<16;i++){
				clock[i] = sc.nextInt();
			}
			int ans= getAns(clock,0);
			if(ans >= MAX){
				ans = -1;
			}
			System.out.println(ans);
		}
		
	}
	
	static void click(int[] cl,int swNum){
		for(int i=0;i<5;i++){
			int x = sw[swNum][i];
			if(x==-1) continue;
			cl[x] += 3;
			if(cl[x]==15) cl[x]=3;			
		}		
	}
	
	static boolean isAllTwelve(int[] arr){
		for(int i=0;i<arr.length;i++){
			if(arr[i]<12){
				return false;
			}
		}
		return true;
	}
	
	static int getAns(int[] cl, int swNum){
		if(swNum==10){
			return isAllTwelve(cl) ? 0 : MAX;
		}
		int ret = MAX;
		for(int cnt =0;cnt<4;++cnt){
			ret = Math.min(ret , cnt + getAns(cl,swNum+1));
			click(cl,swNum);
		}
		return ret;
	}	
}