package coplit;

import org.junit.jupiter.api.Test;

import java.util.*;

class Solution {

    List<Node> nodes = new ArrayList<>();
    List<Node>[] nodeLevel;

    List<Integer> preOrders = new ArrayList<>();
    List<Integer> postOrders = new ArrayList<>();
    public int[][] solution(int[][] nodeInfo) {

        init(nodeInfo);
        setParent();

        Node root = nodes.get(0);
        preOrder(root);
        postOrder(root);

        int[] preOrderArray = preOrders.stream()
                .mapToInt(Integer::valueOf)
                .toArray();
        int[] postOrderArray = postOrders.stream()
                .mapToInt(Integer::valueOf)
                .toArray();
        return new int[][]{preOrderArray,postOrderArray};
    }

    private void init(int[][] nodeInfo){
        for(int i=0;i<nodeInfo.length;i++){
            int[] xy = nodeInfo[i];
            Node node = new Node(i + 1, xy[0], xy[1]);
            nodes.add(node);
        }
        Collections.sort(nodes);

        int maxY = nodes.get(0).y;
        nodeLevel = new ArrayList[maxY+1];
        for(int i=0;i< nodeLevel.length;i++){
            nodeLevel[i] = new ArrayList<>();
        }

        for(Node node : nodes){
            nodeLevel[node.y].add(node);
        }
    }

    private void setParent(){
        if(nodes.size()<=1)
            return;

        int parentY = nodes.get(0).y;
        int currentY = nodes.get(1).y;
        for(int i=1;i<nodes.size();i++) {
            Node node = nodes.get(i);
            // y가 바뀐 경우
            if (currentY != node.y) {
                parentY = currentY;
                currentY = node.y;
            }

            for (Node parent : nodeLevel[parentY]) {
                if (parent.leftChild != null && parent.rightChild != null)
                    continue;
                if (isPossibleLeftChild(parent,node)) {
                    parent.leftChild = node;
                    node.parent = parent;
                    break;
                }
                if (isPossibleRightChild(parent,node)) {
                    parent.rightChild = node;
                    node.parent = parent;
                    break;
                }
            }
        }
    }

    private boolean isPossibleLeftChild(Node parent, Node child){
        if(parent.leftChild != null)
            return false;

        return child.x < parent.x;
    }

    private boolean isPossibleRightChild(Node parent, Node child){
        if(parent.rightChild!= null || parent.x > child.x)
            return false;

        // leftChild인 부모를 찾는다
        Node leftChildParent = null;
        while(parent.parent != null){
            if(parent.parent.leftChild == parent){
                leftChildParent = parent.parent;
                break;
            }
            parent = parent.parent;
        }
        if(leftChildParent == null){
            return true;
        }
        return leftChildParent.x > child.x;
    }


    private void preOrder(Node node){
        if(node == null)
            return;
        // root l r
        preOrders.add(node.value);
        preOrder(node.leftChild);
        preOrder(node.rightChild);
    }

    private void postOrder(Node node){
        if(node == null)
            return;
        // l,r,root
        postOrder(node.leftChild);
        postOrder(node.rightChild);
        postOrders.add(node.value);
    }

    static class Node implements Comparable<Node>{
        int value;
        int x;
        int y;
        Node parent;
        Node leftChild;
        Node rightChild;

        public Node(int value, int x, int y) {
            this.value = value;
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Node o) {
            if(y!=o.y){
                return Integer.compare(o.y,y);
            }
            return Integer.compare(x,o.x);
        }

        @Override
        public String toString() {
            return "Node{" +
                    "value=" + value +
                    ", x=" + x +
                    ", y=" + y +
                    ", leftChild=" + (leftChild==null ? null : leftChild.value) +
                    ", rightChild=" + (rightChild==null ? null : rightChild.value)
                    + "}";
        }
    }
}