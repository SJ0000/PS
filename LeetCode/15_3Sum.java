package sj;

import org.junit.jupiter.api.Test;

import java.util.*;
import java.util.stream.Collectors;

class Solution {

    public List<List<Integer>> threeSum(int[] nums) {

        Set<AnswerSet> answers = new HashSet<>();
        Arrays.sort(nums);

        for(int i=0;i<nums.length-2;i++){
            List<List<Integer>> twoSums = findTwoSums(nums[i] * -1, i + 1, nums);

            for (List<Integer> twoSum : twoSums) {
                answers.add(new AnswerSet(List.of(nums[i],twoSum.get(0),twoSum.get(1))));
            }
        }

        return answers.stream().map(answerSet-> answerSet.list)
                .collect(Collectors.toList());
    }

    private List<List<Integer>> findTwoSums(int target, int st, int[] nums){

        List<List<Integer>> twoSums = new ArrayList<>();

        int l = st;
        int r = nums.length-1;

        while(l<r){
            int current = nums[l]+nums[r];
            if(current == target){
                twoSums.add(List.of(nums[l],nums[r]));
                l++;
            }

            if(current > target){
                r--;
                continue;
            }

            if(current < target){
                l++;
            }
        }
        return twoSums;
    }

    static class AnswerSet{
        List<Integer> list;

        public AnswerSet(List<Integer> list) {
            this.list = list;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            AnswerSet answerSet = (AnswerSet) o;

            for(int i=0;i<list.size();i++){
                if(!Objects.equals(list.get(i), answerSet.list.get(i)))
                    return false;
            }
            return true;
        }

        @Override
        public int hashCode() {
            return Objects.hash(list);
        }
    }
}