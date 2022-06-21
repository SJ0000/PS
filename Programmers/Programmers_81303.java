package coplit;

import java.util.*;

class Solution {

    Stack<Node> removed = new Stack<>();
    Node[] nodes;
    Node currentNode;

    public String solution(int n, int k, String[] cmd) {
        init(n,k);

        for(int i=0;i<cmd.length;i++){
            if(cmd[i].equals("C")){
                remove();
            }else if(cmd[i].equals("Z")){
                rollback();
            }else{
                String[] splitted = cmd[i].split(" ");
                int x = Integer.parseInt(splitted[1]);
                if(splitted[0].equals("U"))
                    up(x);
                else
                    down(x);
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n;i++){
            if(nodes[i].isRemoved)
                sb.append('X');
            else
                sb.append('O');
        }

        return sb.toString();
    }

    private void init(int n, int k){
        nodes = new Node[n];
        nodes[0] = new Node(0);
        for(int i=1;i<n;i++){
            nodes[i] = new Node(i);
            nodes[i].prev = nodes[i-1];
            nodes[i-1].next = nodes[i];
        }
        currentNode = nodes[k];
    }

    private void up(int x){
        for(int i=0;i<x;i++){
            if(currentNode.prev == null)
                break;
            currentNode = currentNode.prev;
        }
    }

    private void down(int x){
        for(int i=0;i<x;i++){
            if(currentNode.next == null)
                break;
            currentNode = currentNode.next;
        }
    }

    private void remove(){
        Node before = currentNode.prev;
        Node next = currentNode.next;
        if(before != null)
            before.next = next;
        if(next != null)
            next.prev = before;

        removed.add(currentNode);
        currentNode.isRemoved = true;

        if(currentNode.next != null)
            currentNode = currentNode.next;
        else
            currentNode = currentNode.prev;
    }

    private void rollback(){
        Node node = removed.pop();
        node.isRemoved = false;
        Node before = node.prev;
        Node next = node.next;

        if(before!= null)
            before.next = node;
        if(next != null)
            next.prev = node;
    }

    static class Node{
        Node prev;
        Node next;
        int value;
        boolean isRemoved;
        public Node(int value) {
            this.value = value;
        }
    }
}