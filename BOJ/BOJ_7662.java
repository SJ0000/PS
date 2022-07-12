package coplit;


import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine());
        for (int tc = 0; tc < t; tc++) {
            int n = Integer.parseInt(reader.readLine());
            MinMaxPriorityQueue q = new MinMaxPriorityQueue();
            for (int i = 0; i < n; i++) {
                String[] query = reader.readLine().split(" ");
                String command = query[0];
                Long value = Long.parseLong(query[1]);
                if (command.equals("I"))
                    q.add(value);
                if (command.equals("D")) {
                    if (value == 1) {
                        q.removeMax();
                    } else {
                        q.removeMin();
                    }
                }
            }
            String result = q.isEmpty() ? "EMPTY" : q.getMaxValue() + " " + q.getMinValue();
            System.out.println(result);
        }
    }

    static class MinMaxPriorityQueue {
        private final PriorityQueue<Long> min,max;
        private final PriorityQueue<Long> minRemove,maxRemove;
        public MinMaxPriorityQueue() {
            this.min = new PriorityQueue<>();
            this.max = new PriorityQueue<>();
            this.minRemove = new PriorityQueue<>();
            this.maxRemove = new PriorityQueue<>();
        }

        public void add(Long value) {
            min.add(value);
            max.add(-value);
        }

        public void removeMin() {
            if (isEmpty())
                return;
            Long target = getMinValue();
            minRemove.add(target);
            maxRemove.add(-target);
        }

        public void removeMax() {
            if (isEmpty())
                return;
            Long target = getMaxValue();
            minRemove.add(target);
            maxRemove.add(-target);
        }

        public boolean isEmpty() {
            cleanRemoveQueue();
            return min.isEmpty() && max.isEmpty();
        }

        public Long getMinValue() {
            cleanRemoveQueue();
            return min.peek();
        }

        public Long getMaxValue() {
            cleanRemoveQueue();
            return -max.peek();
        }

        private void cleanRemoveQueue(){
            // min에 대해
            while(!minRemove.isEmpty()){
                if(min.isEmpty())
                    break;
                if(min.peek().equals(minRemove.peek())){
                    min.poll();
                    minRemove.poll();
                }else{
                    break;
                }
            }
            // max에 대해
            while(!maxRemove.isEmpty()){
                if(max.isEmpty())
                    break;
                if(max.peek().equals(maxRemove.peek())){
                    max.poll();
                    maxRemove.poll();
                }else{
                    break;
                }
            }
        }
    }
}