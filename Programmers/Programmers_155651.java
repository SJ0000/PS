package sj;

import java.util.*;
import java.util.stream.Collectors;

class Solution {

    public int solution(String[][] book_time) {
        Reservation reservation = new Reservation();

        List<String> bookTimes = Arrays.stream(book_time)
                .map(times -> times[0] + "," + times[1])
                .sorted()
                .collect(Collectors.toList());

        for(int i=0;i<bookTimes.size();i++){
            String[] fromTo = bookTimes.get(i).split(",");
            int from = toMinutes(fromTo[0]);
            int to = toMinutes(fromTo[1]);
            reservation.reserve(from, to + 10);
        }

        return reservation.getRoomCount();
    }

    private int toMinutes(String time) {
        String[] hm = time.split(":");
        return Integer.parseInt(hm[0]) * 60 + Integer.parseInt(hm[1]);
    }

    static class Reservation {
        List<Room> rooms = new ArrayList<>();

        public void reserve(int from, int to) {
            for (Room room : rooms) {
                if (room.can(from, to)) {
                    room.reserve(from, to);
                    return;
                }
            }

            Room room = new Room();
            room.reserve(from, to);
            rooms.add(room);
        }

        public int getRoomCount() {
            return rooms.size();
        }

    }

    static class Room {
        List<Time> times = new ArrayList<>();

        public boolean can(int from, int to) {
            for (Time time : times) {
                if (time.in(from, to))
                    return false;
            }
            return true;
        }

        public void reserve(int from, int to) {
            times.add(new Time(from, to));
        }
    }

    static class Time {
        public int from;
        public int to;

        public Time(int from, int to) {
            this.from = from;
            this.to = to;
        }

        public boolean in(int from, int to) {
            return !(to <= this.from || this.to <= from);
        }
    }
}