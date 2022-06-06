package coplit;

import org.junit.jupiter.api.Test;

import java.util.*;

class Solution {

    private HashMap<String,Integer> dict = new HashMap<>();
    private Integer valueIndex = 0;

    public int[] solution(String msg) {
        List<Integer> answer = new ArrayList<>();
        init();
        int msgStartIndex = 0;
        while(msgStartIndex<msg.length()){
            Pair result = process(msg.substring(msgStartIndex));
            answer.add(result.output);
            msgStartIndex += result.addedItemLength;
        }
        // System.out.println("answer = " + answer);
        return answer.stream().mapToInt(Integer::valueOf)
                .toArray();
    }

    private void init(){
        int count = 'Z'-'A'+1;
        for(int i=0;i<count;i++){
            char ch = (char) ('A'+i);
            dict.put(Character.toString(ch),++valueIndex);
        }
    }

    private Pair process(String msg){
        // System.out.println("msg = " + msg);
        String before = msg.substring(0,1);
        for(int length=1;length<=msg.length();length++){
            String current = msg.substring(0,length);
            // System.out.println("before = " + before + " current = " + current);
            if(!dict.containsKey(current)){
                dict.put(current,++valueIndex);
                break;
            }
            before = current;
        }
        return new Pair(dict.get(before),before.length());
    }

    static class Pair{
        Integer output;
        Integer addedItemLength;

        public Pair(Integer output, Integer addedItemLength) {
            this.output = output;
            this.addedItemLength = addedItemLength;
        }
    }
}