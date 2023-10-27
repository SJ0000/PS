package sj;

import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int n = numbers.length;
        int[] ans = new int[n];
        Stack<Integer> s = new Stack<>();
        ans[n-1] = -1;
        s.add(numbers[n-1]);
        for(int i=n-2;i>=0;i--){
            int number = numbers[i];
            while(!s.isEmpty() && number >= s.peek())
                s.pop();
            if(s.isEmpty()){
                ans[i] = -1;
            }else{
                ans[i] = s.peek();
            }
            s.add(number);
        }
        return ans;
    }
}