package sj;

import java.util.*;

class Solution {

    public int solution(int[] queue1, int[] queue2) {
        SumQueue q1 = new SumQueue(queue1);
        SumQueue q2 = new SumQueue(queue2);

        // 불가능
        if((q1.sum + q2.sum)%2 != 0)
            return -1;

        int maxCount = queue1.length*3;
        for(int count=0;count<maxCount;count++){

            if(q1.sum == q2.sum)
                return count;

            if(q1.sum> q2.sum) {
                q2.insert(q1.pop());
            }else{
                q1.insert(q2.pop());
            }
        }

        return -1;
    }

    static class SumQueue{
        private Queue<Long> queue = new LinkedList<>();
        public long sum;

        public SumQueue(int[] values) {
            sum = 0;
            for(int i=0;i<values.length;i++){
                queue.add((long)values[i]);
                sum += values[i];
            }
        }

        public void insert(long value){
            queue.add(value);
            sum += value;
        }

        public long pop(){
            if(queue.size() == 0)
                throw new RuntimeException("queue empty");

            long value = queue.poll();
            sum -= value;
            return value;
        }
    }
}