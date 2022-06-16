package coplit;

import org.junit.jupiter.api.Test;

import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int solution(String[] lines) {

        List<RequestInfo> infos = Arrays.stream(lines)
                .map(RequestInfo::new)
                .collect(Collectors.toList());

        long answer = -1;
        for(int candidate : RequestInfo.candidates){
            long count = infos.stream()
                    .filter(info -> info.include(candidate))
                    .count();
            answer = Long.max(answer,count);
        }

        return (int)answer;
    }

    static class RequestInfo {

        int startMillis;
        int endMillis;

        static Set<Integer> candidates = new HashSet<>();

        public RequestInfo(String logText) {

            String[] logs = logText.split(" ");
            String[] timeInfo = logs[1].split(":");
            int hh = Integer.parseInt(timeInfo[0]);
            int mm = Integer.parseInt(timeInfo[1]);
            int ssfff = (int)(Double.parseDouble(timeInfo[2])*1000);

            int processTime = (int)(Double.parseDouble(logs[2].replace("s", ""))*1000);
            endMillis = (hh * 3600 + mm * 60) * 1000 + ssfff;
            startMillis = (endMillis - processTime) + 1;

            candidates.add(endMillis);
        }

        public boolean include(int rangeStart){
            int rangeEnd = rangeStart+1000-1;
            return !(rangeStart > endMillis || rangeEnd< startMillis);
        }

        @Override
        public String toString() {
            return "RequestInfo{" +
                    "startMillis=" + startMillis +
                    ", endMillis=" + endMillis +
                    '}';
        }
    }
}