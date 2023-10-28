package sj;

import java.util.*;

class Solution {

    int[] dx = new int[]{0, 0, 1, -1};
    int[] dy = new int[]{1, -1, 0, 0};

    public int[] solution(String[] maps) {
        List<Integer> answers = new ArrayList<>();
        int width = maps[0].length();
        int height = maps.length;

        int[][] map = toIntMap(maps);
        boolean[][] visit = new boolean[height][width];

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (!visit[i][j] && map[i][j] != -1)
                    answers.add(dfs(map, visit, i, j));
            }
        }

        if(answers.size() == 0)
            answers.add(-1);

        return answers.stream()
                .sorted()
                .mapToInt(i -> (int) i)
                .toArray();
    }

    private int dfs(int[][] map, boolean[][] visit, int x, int y) {
        visit[x][y] = true;
        int ret = map[x][y];

        for (int i = 0; i < 4; i++) {
            int ax = x + dx[i];
            int ay = y + dy[i];

            if (!(0 <= ax && ax < map.length && 0 <= ay && ay < map[0].length))
                continue;
            if (visit[ax][ay])
                continue;
            if (map[ax][ay] == -1)
                continue;

            ret += dfs(map, visit, ax, ay);
        }

        return ret;
    }


    private int[][] toIntMap(String[] maps) {
        int width = maps[0].length();
        int height = maps.length;

        int[][] map = new int[height][width];

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                char ch = maps[i].charAt(j);
                if (ch == 'X')
                    map[i][j] = -1;
                else
                    map[i][j] = ch - '0';
            }
        }
        return map;
    }
}