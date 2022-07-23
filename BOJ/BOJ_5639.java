package coplit;


import org.junit.jupiter.api.Test;

import javax.swing.text.AbstractDocument;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Solution {



    @Test
    void test() {

        int[] ints = IntStream.of(50, 30, 24, 5, 28, 45, 98, 52, 60)
                .filter(x -> x < 50)
                .toArray();
        System.out.println(Arrays.toString(ints));

    }
}
