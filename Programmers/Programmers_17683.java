package coplit;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Programmers_17683 {

    public String solution(String m, String[] musicinfos) {

        String listenMelody = Music.sharpToLower(m);
        List<Music> melodyMatchedMusics = Arrays.stream(musicinfos)
                .map(Music::create)
                .filter(music -> music.hasMelody(listenMelody))
                .collect(Collectors.toList());

        int maxLength = melodyMatchedMusics.stream()
                .mapToInt(music -> music.melody.length())
                .max()
                .orElse(-1);

        for(Music music : melodyMatchedMusics){
            if(music.melody.length() == maxLength)
                return music.name;
        }

        return "(None)";
    }

    static class Music {
        private static int idIndex = 0;

        private int id;
        private String name;
        private String melody;

        public Music(int id, String name, String melody) {
            this.id = id;
            this.name = name;
            this.melody = melody;
        }

        static Music create(String musicInfo){
            int id = ++idIndex;

            String[] infos = musicInfo.split(",");
            String name = infos[2];

            int minutes = getMinutes(infos[0],infos[1]);
            String melody = getAllMelody(sharpToLower(infos[3]), minutes);

            return new Music(id,name,melody);
        }

        // #붙은거 처리하기 쉽게 소문자로 변경
        public static String sharpToLower(String melody){
            return melody.replace("C#","c")
                    .replace("D#","d")
                    .replace("F#","f")
                    .replace("G#","g")
                    .replace("A#","a");
        }

        private static int getMinutes(String start, String end){
            String[] startHM = start.split(":");
            String[] endHM = end.split(":");
            int startHour = Integer.parseInt(startHM[0]);
            int startMinute = Integer.parseInt(startHM[1]);
            int endHour = Integer.parseInt(endHM[0]);
            int endMinute = Integer.parseInt(endHM[1]);

            return (endHour*60 + endMinute) - (startHour*60 + startMinute);
        }

        private static String getAllMelody(String melody, int listenMinutes){
            if(melody.length() > listenMinutes)
                return melody.substring(0,listenMinutes);

            int quotient = listenMinutes/melody.length();
            int remainder = listenMinutes%melody.length();

            StringBuilder sb = new StringBuilder();
            for(int i=0;i<quotient;i++){
                sb.append(melody);
            }
            sb.append(melody.substring(0,remainder));
            return sb.toString();
        }

        private boolean hasMelody(String listenMelody){
            return this.melody.contains(listenMelody);
        }

        @Override
        public String toString() {
            return "Music{" +
                    "id=" + id +
                    ", name='" + name + '\'' +
                    ", melody='" + melody + '\'' +
                    '}';
        }
    }
}