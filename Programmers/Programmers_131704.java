package sj;

import java.util.*;

class Solution {

    public int solution(int[] order) {
        int n = order.length;
        List<Integer> container = new ArrayList<>();
        Stack<Integer> subContainer = new Stack<>();

        int requiredIndex = 0;
        for(int current=1;current<=n;current++){
            System.out.println("container = " + container + " subContainer = " + subContainer);
            boolean containerAdded = false;
            // container에서 바로 꺼내는 경우
            if(current == order[requiredIndex]){
                container.add(current);
                requiredIndex++;
                containerAdded = true;
            }

            // 보조컨테이너에서 빼는 경우
            while(!subContainer.isEmpty()){
                if(subContainer.peek() != order[requiredIndex])
                    break;
                container.add(subContainer.pop());
                requiredIndex++;
            }
            if(!containerAdded){
                subContainer.add(current);
                while(!subContainer.isEmpty()){
                    if(requiredIndex == order.length || subContainer.peek() != order[requiredIndex])
                        break;
                    container.add(subContainer.pop());
                    requiredIndex++;
                }
            }
        }

        return container.size();
    }
}