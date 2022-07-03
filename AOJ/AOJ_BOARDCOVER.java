import java.util.*;
public class Main {
	static int[][][] block = {
			{{0,0},{1,0},{1,-1}},
			{{0,0},{1,0},{1,1}},
			{{0,0},{0,1},{1,1}},
			{{0,0},{0,1},{1,0}}			
	};
	static char[][] board;
	static int x,y;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0){
			x = sc.nextInt();
			y = sc.nextInt();
			board = new char[x][y];
			int white = 0;			
			for(int i=0;i<x;i++){
				String s = sc.next();
				for(int j=0;j<y;j++){
					char c = s.charAt(j);
					board[i][j] = c;
					if(c=='.'){
						white++;
					}
				}
			}
			if(white%3==0){
				System.out.println(getAns(board));
			}else{
				System.out.println(0);
			}
		}		
	}
	static int getAns(char[][] covered){	
		
		int firstX=-1;
		int firstY=-1;
		boolean getFirst = false;
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				if(covered[i][j]=='.'){
					firstX = i;
					firstY = j;
					getFirst = true;
					break;
				}
			}
			if(getFirst){
				break;
			}
		}		
		if(firstX==-1 && firstY==-1){
			return 1;
		}
		int ret=0;
		
		//block
		int a1,a2,b1,b2,c1,c2;
		for(int i=0;i<4;i++){
			a1 = firstX + block[i][0][0];
			a2 = firstY + block[i][0][1];
			b1 = firstX + block[i][1][0];
			b2 = firstY + block[i][1][1];
			c1 = firstX + block[i][2][0];
			c2 = firstY + block[i][2][1];
			if(0<=a1&&a1<x && 0<=a2 && a2<y && 
					0<=b1&&b1<x && 0<=b2 && b2<y &&					
					0<=c1&&c1<x && 0<=c2 && c2<y &&
					covered[a1][a2]=='.' && covered[b1][b2]=='.' && covered[c1][c2]=='.'){
				covered[a1][a2] = covered [b1][b2] = covered[c1][c2] = '#';
				ret+=getAns(covered);
				covered[a1][a2] = covered[b1][b2] = covered[c1][c2] = '.';				
			}			
		}
		return ret;
	}
}