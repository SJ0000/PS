package coplit;

import org.junit.jupiter.api.Test;


import java.util.*;

class Solution {

    List<Node> allNodes = new ArrayList<>();
    List<Node>[] edgeInfo;
    static boolean[] visit;
    long total = 0;
    public long solution(int[] a, int[][] edges) {
        if(!isPossible(a))
            return -1;
        init(a, edges);
        dfs(0, -1);
        return total;
    }

    private void dfs(int node, int parent){
        visit[node] = true;

        List<Node> nextNodes = edgeInfo[node];
        for(int i=0;i<nextNodes.size();i++){
            Node next = nextNodes.get(i);
            if(!visit[next.num])
                dfs(next.num, node);
        }
        if(parent==-1)
            return;

        Node p = allNodes.get(parent);
        Node n = allNodes.get(node);
        p.weight += n.weight;
        total += Math.abs(n.weight);
    }

    private boolean isPossible(int[] a){
        long sum = 0;
        for(int i=0;i<a.length;i++){
            sum += a[i];
        }
        return sum == 0;
    }

    private void init(int[] a, int[][] edges) {
        edgeInfo = new ArrayList[a.length];
        visit = new boolean[a.length];

        for(int i=0;i<edgeInfo.length;i++){
            edgeInfo[i] = new ArrayList<>();
        }

        for (int i = 0; i < a.length; i++) {
            allNodes.add(new Node(i, a[i]));
        }
        for (int[] edge : edges) {
            Node x = allNodes.get(edge[0]);
            Node y = allNodes.get(edge[1]);
            edgeInfo[x.num].add(y);
            edgeInfo[y.num].add(x);
        }
    }

    static class Node {
        int num;
        long weight;
        public Node(int num, long weight) {
            this.num = num;
            this.weight = weight;
        }
    }

    @Test
    void test(){
        int[] a = new int[]{-2,8,-5,-5,-3,0,5,2};
        int[][] edges = new int[][]{
                new int[]{0,1},
                new int[]{0,2},
                new int[]{1,3},
                new int[]{1,4},
                new int[]{1,5},
                new int[]{2,6},
                new int[]{2,7}
        };
        long result = solution(a, edges);
        System.out.println("result = " + result);
    }
}