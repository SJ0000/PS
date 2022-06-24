package coplit;

import org.junit.jupiter.api.Test;

import java.util.*;
import java.util.stream.Collectors;

class Solution {

    long[] user = new long[360001];
    long[] userPsum = new long[360001];

    public String solution(String play_time, String adv_time, String[] logs) {

        int playTime = toSeconds(play_time);
        int advTime = toSeconds(adv_time);

        List<Log> logList = Arrays.stream(logs).map(Log::new)
                .collect(Collectors.toList());

        init(playTime, logList);

        long maxValue = 0;
        int maxSeconds = 0;
        for(int t=0;t<=playTime-advTime;t++){
            int start = t;
            int end = t+advTime-1;
            long users = start==0 ? userPsum[end] : userPsum[end] - userPsum[start-1];
            if(users > maxValue){
                maxValue = users;
                maxSeconds = t;
            }
        }
        System.out.println("maxValue = " + maxValue);
        return toTime(maxSeconds);
    }

    private void init(int playTime, List<Log> logList) {
        PriorityQueue<Integer> startQueue = new PriorityQueue<>();
        PriorityQueue<Integer> endQueue = new PriorityQueue<>();

        for(Log log : logList){
            startQueue.add(log.start);
            endQueue.add(log.end);
        }
        int current = 0;
        for(int t = 0; t<= playTime; t++){
            while(!startQueue.isEmpty() && startQueue.peek() == t){
                startQueue.poll();
                current +=1;
            }
            while(!endQueue.isEmpty() && endQueue.peek() == t){
                endQueue.poll();
                current -=1;
            }
            user[t] = current;
        }

        userPsum[0] = user[0];
        for(int t = 1; t<= playTime; t++){
            userPsum[t] = userPsum[t-1] + user[t];
        }
    }

    private static int toSeconds(String time){
        String[] s = time.split(":");
        int hh = Integer.parseInt(s[0]);
        int mm = Integer.parseInt(s[1]);
        int ss = Integer.parseInt(s[2]);
        return (hh*60*60) + (mm * 60) + ss;
    }

    private static String toTime(int seconds){
        String hh = Integer.toString(seconds/3600);
        seconds%=3600;
        String mm = Integer.toString(seconds/60);
        String ss = Integer.toString(seconds%60);

        if(hh.length()==1)
            hh = "0"+hh;
        if(mm.length()==1)
            mm = "0"+mm;
        if(ss.length()==1)
            ss = "0"+ss;

        return hh+":"+mm+":"+ss;
    }


    static class Log{
        int start;
        int end;
        public Log(String time) {
            String[] split = time.split("-");
            start = toSeconds(split[0]);
            end = toSeconds(split[1]);
        }
    }
}