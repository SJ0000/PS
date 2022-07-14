package coplit;


import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        String s = br.readLine();

        List<Integer> counts = new ArrayList<>();
        int ioCount = 0;
        for(int i=0;i<m;i++){
            if(i==m-1){
                if(s.charAt(i-1) != s.charAt(i))
                    ioCount++;
                counts.add(ioCount);
                ioCount = 0;
                break;
            }
            if(s.charAt(i) == 'I' && s.charAt(i+1) == 'O'){
                ioCount+=2;
                i++;
                continue;
            }
            if(s.charAt(i) == 'I'){
                ioCount++;
            }
            counts.add(ioCount);
            ioCount = 0;
        }
        counts.add(ioCount);
        // System.out.println(counts);
        List<Integer> pnList = counts.stream()
                                      .map(x -> (x-1) / 2)
                                      .collect(Collectors.toList());
        // System.out.println(pnList);
        int answer = 0;
        for (Integer px : pnList) {
            // Px 로는 Pn을 x+1-N개 만들 수 있다.
            int possibleCount = px+1-n;
            if(possibleCount > 0)
                answer += possibleCount;
        }
        System.out.println(answer);
    }
}