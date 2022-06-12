package coplit;

import org.junit.jupiter.api.Test;

import java.util.*;

class Solution {
    public int[] solution(String[] operations) {

        MinMaxHeap minMaxHeap = new MinMaxHeap();

        for(int i=0;i<operations.length;i++){
            String operation = operations[i];
            String[] command = operation.split(" ");
            if(command[0].equals("I")){
                minMaxHeap.insert(Integer.valueOf(command[1]));
                continue;
            }
            if(command[0].equals("D")){
                if(command[1].equals("1")){
                    minMaxHeap.deleteMax();
                    continue;
                }
                if(command[1].equals("-1")){
                    minMaxHeap.deleteMin();
                    continue;
                }
            }
        }
        return minMaxHeap.result();
    }

    static class MinMaxHeap{

        private PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        private PriorityQueue<Integer> maxHeap = new PriorityQueue<>();

        public void insert(Integer value){
            minHeap.add(value);
            maxHeap.add(-value);
        }

        public void deleteMax(){
            if(minHeap.size()==0)
                return;

            Integer max = -maxHeap.poll();
            minHeap.remove(max);
        }

        public void deleteMin(){
            if(minHeap.size()==0)
                return;

            Integer min = minHeap.poll();
            maxHeap.remove(-min);
        }

        public int[] result(){
            if(minHeap.size()==0){
                return new int[]{0,0};
            }
            return new int[]{-maxHeap.poll(), minHeap.poll()};
        }
    }
}