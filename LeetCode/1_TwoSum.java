package sj;

import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {

        List<Node> li = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            li.add(new Node(i,nums[i]));
        }

        li.sort(Comparator.comparingInt((x) -> x.value));

        int l = 0;
        int r = nums.length-1;

        while(l<r){
            int result = li.get(l).value + li.get(r).value;
            if(result == target)
                break;
            if(result < target)
                l++;
            if(result > target)
                r--;
        }
        return new int[]{li.get(l).index,li.get(r).index};
    }

    static class Node{
        int index;
        int value;

        public Node(int index, int value) {
            this.index = index;
            this.value = value;
        }
    }
}