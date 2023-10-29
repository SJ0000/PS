package sj;

import java.util.*;

class Solution {

    public int[] solution(int n, long left, long right) {
        left++; right++;
        int[] answer = new int[(int)(right-left+1)];
        for(int i=0;i<answer.length;i++){
            answer[i] = getNumber(n, left+i);
        }

        return answer;
    }


    int getNumber(long n, long i){
        long block = i/n + (i%n == 0 ? 0 : 1);
        long segment = -1;
        if(i%n == 0){
            segment = n;
        }
        else{
            segment = i%n;
        }
        return (int) Long.max(block,segment);
    }
}