package coplit;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_2042 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        int k = Integer.parseInt(s[2]);

        long[] arr = new long[n];
        for(int i=0;i<n;i++){
            arr[i] = Long.parseLong(br.readLine());
        }
        SegmentTree segmentTree = new SegmentTree(arr);

        for(int i=0;i<m+k;i++){
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            if(a==1){
                int b = Integer.parseInt(input[1]);
                long c = Long.parseLong(input[2]);
                segmentTree.update(b-1,c);
            }else{
                int b = Integer.parseInt(input[1]);
                int c = Integer.parseInt(input[2]);
                System.out.println(segmentTree.query(b-1,c-1));
            }
        }
    }

    static class SegmentTree {
        private long[] arr;
        private long[] psum;
        private long[] tree;

        public SegmentTree(long[] arr) {
            this.arr = arr;

            this.psum = new long[arr.length];
            psum[0] = arr[0];
            for(int i=1;i<psum.length;i++){
                psum[i] = psum[i-1] + arr[i];
            }

            this.tree = new long[getTreeSize(arr.length)];
            init(0, arr.length - 1, 1);
        }

        private int getTreeSize(int n) {
            int i = 0;
            while (n > (1 << i)) {
                i++;
            }
            return 1 << (i + 1);
        }

        private void init(int l, int r, int node) {
            if(l==r){
                tree[node] = arr[l];
                return;
            }
            if(l==0)
                tree[node] = psum[r];
            else{
                tree[node] = psum[r]-psum[l-1];
            }
            int mid = (l+r)/2;
            init(l, mid, node * 2);
            init(mid + 1, r, node * 2 + 1);
        }

        public long query(int left, int right) {
            return this.query(left, right, 1, 0, arr.length - 1);
        }

        // [l,r]과 [nodeLeft,nodeRight]의 공집합
        private long query(int l, int r, int node, int nodeLeft, int nodeRight) {
            if (l > nodeRight || r < nodeLeft)
                return 0;

            if (l <= nodeLeft && nodeRight <= r)
                return tree[node];

            int mid = (nodeLeft + nodeRight) / 2;
            long leftSum = query(l, r, node * 2, nodeLeft, mid);
            long rightSum = query(l, r, node * 2 + 1, mid + 1, nodeRight);

            return leftSum+rightSum;
        }

        public void update(int index, long value) {
            update(index, value, 1, 0, arr.length - 1);
            arr[index] = value;
        }

        private void update(int index, long value, int node, int nodeLeft, int nodeRight) {
            if (nodeLeft > index || nodeRight < index)
                return;
            if (nodeLeft == nodeRight){
                tree[node] = value;
                return;
            }

            long diff = value - arr[index];
            tree[node] += diff;
            int mid = (nodeLeft + nodeRight) / 2;
            update(index, value, node * 2, nodeLeft, mid);
            update(index, value, node * 2 + 1, mid + 1, nodeRight);
        }
    }
}