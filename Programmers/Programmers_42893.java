package coplit;

import org.junit.jupiter.api.Test;


import java.util.*;
import java.util.stream.Collectors;

class Solution {

    public int solution(String word, String[] pages) {

        List<Page> pageList = Arrays.stream(pages)
                .map(html -> new Page(html, word))
                .collect(Collectors.toList());

        for(int i=0;i<pages.length;i++){
            Page a = pageList.get(i);
            for(int j=0;j<pages.length;j++){
                if(i==j)
                    continue;
                Page b = pageList.get(j);
                for(String link : b.externalLinks){
                    if(link.equals(a.url)){
                        a.linkPoint += b.basicPoint/b.externalLinks.size();
                    }
                }
            }
        }

        double maxMatchPoint = pageList.stream().mapToDouble(Page::getMatchPoint)
                .max()
                .getAsDouble();

        int answer = 0;
        for(int i=0;i<pageList.size();i++){
            Page p = pageList.get(i);
            if(p.getMatchPoint() == maxMatchPoint){
                answer = i;
                break;
            }
        }

        return answer;
    }

    static class Page{
        String url;
        double basicPoint;
        double linkPoint = 0;
        List<String> externalLinks;

        public Page(String html, String searchWord){
            html = html.toLowerCase();
            searchWord = searchWord.toLowerCase();

            this.url = parseUrl(html);
            this.basicPoint = calculateBasicPoint(html,searchWord);
            this.externalLinks = parseExternalLinks(html);
        }

        public double getMatchPoint(){
            return basicPoint + linkPoint;
        }

        private String parseUrl(String html){
            String tag = "<meta property=\"og:url\" content=";
            int start = html.indexOf(tag) + tag.length();
            int end = html.indexOf("/>",start);
            return html.substring(start+1, end-1);
        }

        private double calculateBasicPoint(String html,String searchWord){
            List<String> words = new ArrayList<>();
            StringBuilder sb = new StringBuilder();
            for(int i = 0;i<html.length();i++){
                char ch = html.charAt(i);
                if('a' <= ch && ch <= 'z'){
                    sb.append(ch);
                }else{
                    if(sb.length()==0)
                        continue;
                    words.add(sb.toString());
                    sb = new StringBuilder();
                }
            }
            long count = words.stream()
                    .filter(word -> word.equals(searchWord))
                    .count();
            return (double) count;
        }

        private List<String> parseExternalLinks(String html){
            List<String> links = new ArrayList<>();
            String tag = "<a href=";
            int start = 0;
            int end = 0;
            while(true){
                int index = html.indexOf(tag,end);
                if(index == -1)
                    break;
                start = index+tag.length();
                end = html.indexOf(">",start);
                String link = html.substring(start + 1, end - 1);
                links.add(link);
            }
            return links;
        }
    }
}