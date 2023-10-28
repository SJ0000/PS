package sj;

import java.util.*;

class Solution {


    public int solution(int x, int y, int n) {
        int answer = 0;
        boolean[] visit = new boolean[1000001];
        Queue<Integer> q = new LinkedList<>();
        q.add(x);
        visit[x] = true;
        while(!q.isEmpty()){
            System.out.println(q);
            int qs = q.size();
            for(int i=0;i<qs;i++){
                int value = q.poll();
                if(value == y)
                    return answer;

                addIfPossible(q, visit, value+n, value*2, value*3);
            }
            answer++;
        }
        return -1;
    }

    private void addIfPossible(Queue<Integer> q, boolean[] visit, int... values){
        for (int value : values) {
            if(value > 1000000)
                continue;
            if(visit[value])
                continue;

            visit[value] = true;
            q.add(value);
        }
    }
}