package coplit;

import org.junit.jupiter.api.Test;

import java.util.*;

class Solution {

    int[] original;

    public int solution(int[] stones, int k) {
        original = stones;

        int l = 1;
        int r = Arrays.stream(stones).max().getAsInt();
        int answer = 0;

        while(l<=r){
            int mid = (l+r)/2;
            if(possible(mid,k)){
                answer = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return answer;
    }

    private boolean possible(int n,int k){
        int zeroCount = 0;
        int[] copied = new int[original.length];
        System.arraycopy(original,0,copied,0,original.length);

        for(int i=0;i<copied.length;i++){
            copied[i] -= n-1;
            zeroCount = copied[i] > 0 ? 0 : zeroCount+1;
            if(zeroCount==k)
                return false;
        }
        return true;
    }

    @Test
    void test(){
        int result = solution(new int[]{1,2,3,4,5,6,7},3);
        System.out.println("result = " + result);
    }
}