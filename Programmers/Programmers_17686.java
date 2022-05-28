package coplit;


import java.util.Arrays;

public class Programmers_17686 {

    public String[] solution(String[] files) {

        String[] sortedFiles = Arrays.stream(files)
                .map(FileName::createFileName)
                .sorted()
                .map(FileName::getFullName)
                .toArray(String[]::new);

        return sortedFiles;
    }

    static class FileName implements Comparable<FileName> {

        private String head;
        private String number;
        private String tail;

        public FileName(String head, String number, String tail) {
            this.head = head;
            this.number = number;
            this.tail = tail;
        }

        @Override
        public String toString() {
            return String.format("head = [%s], number = [%s], tail = [%s]", head, number, tail);
        }

        @Override
        public int compareTo(FileName o) {
            int headCompareResult = head.toUpperCase().compareTo(o.head.toUpperCase());
            if (headCompareResult != 0)
                return headCompareResult;

            if (getNumberInt() != o.getNumberInt())
                return getNumberInt() - o.getNumberInt();
            return 0;
        }

        private int getNumberInt() {
            return Integer.parseInt(number);
        }

        private String getFullName() {
            StringBuilder sb = new StringBuilder();
            sb.append(head);
            sb.append(number);
            sb.append(tail);
            return sb.toString();
        }

        static FileName createFileName(String fullName) {
            int headEnd = -1;
            int numberEnd = -1;

            // get head end
            for (int i = 0; i < fullName.length(); i++) {
                char ch = fullName.charAt(i);
                if ('0' <= ch && ch <= '9') {
                    headEnd = i - 1;
                    break;
                }
            }

            // get number end
            for (int i = headEnd + 1; i < Math.min(headEnd + 6, fullName.length()); i++) {
                char ch = fullName.charAt(i);
                if (!('0' <= ch && ch <= '9')) {
                    numberEnd = i - 1;
                    break;
                }
            }
            if (numberEnd == -1)
                numberEnd = Math.min(headEnd + 5, fullName.length() - 1);

            String head = fullName.substring(0, headEnd + 1);
            String number = fullName.substring(headEnd + 1, numberEnd + 1);
            String tail = fullName.substring(numberEnd + 1);

            return new FileName(head, number, tail);
        }
    }
}