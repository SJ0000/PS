package sj;

import org.junit.jupiter.api.Test;

import java.util.*;
import java.util.stream.Collectors;

class Solution {

    public int maxArea(int[] height) {

        int l = 0;
        int r = height.length-1;
        int max = 0;
        while(l<r){
            int current = (r-l)*Integer.min(height[l],height[r]);
            max = Integer.max(current,max);

            if(height[l] < height[r]){
                l++;
                continue;
            }
            r--;
        }
        return max;
    }
}