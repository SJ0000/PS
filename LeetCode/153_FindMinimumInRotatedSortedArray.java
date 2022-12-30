package sj;

import org.junit.jupiter.api.Test;

import java.util.*;

class Solution {

    public int findMin(int[] nums) {
        int n = nums.length;
        return find(0,n-1,nums);
    }

    private int find(int st, int ed, int[] nums){
        int mid = (st+ed)/2;

        if(ed-st+1 <= 4){
            int min = 5001;
            for(int i=st;i<=ed;i++){
                min = Integer.min(nums[i],min);
            }
            return min;
        }

        if(nums[mid] > nums[mid+1])
            return nums[mid+1];

        if(nums[st] > nums[mid-1])
            return find(st,mid-1,nums);

        if(nums[mid+1] > nums[ed])
            return find(mid+1,ed,nums);

        return Integer.min(nums[st],nums[mid]);
    }
}