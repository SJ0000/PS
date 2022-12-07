package sj;

import org.junit.jupiter.api.Test;

import java.util.*;

class Solution {

    public int maxProfit(int[] prices) {
        int n = prices.length;
        // d[i] = 0번 ~ i번 중 가장 작은 값
        int[] d = new int[n];
        d[0] = prices[0];
        int answer = 0;
        for (int i = 1; i < n; i++) {
            d[i] = Integer.min(d[i-1],prices[i]);
            answer = Integer.max(answer, prices[i]-d[i-1]);
        }
        return answer;
    }
}