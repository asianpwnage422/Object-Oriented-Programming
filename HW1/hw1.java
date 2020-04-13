import java.util.*;

public class hw1{
    public static void main(String[] args) {
        Map<Character, Integer> map = new LinkedHashMap<>();
        String str = new String("");
        Integer i, j;
        Integer count;
        for(i = 0; i < args.length; i++){
            str = str.concat(args[i]);
        }
        char[] data = str.toCharArray();
        for(i = 0; i < data.length; i++){
            if(map.containsKey(data[i]) == true){
                count = map.get(data[i]);
                map.put(data[i],count+1);
            }
            else{
                map.put(data[i],1);
            }
        }
        for (Character key : map.keySet()) {
            System.out.print(key + "-" + map.get(key) + ",");
        }
    }
}