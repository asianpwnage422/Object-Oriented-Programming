import java.util.*;

public class CharFreq {
    public static void main(String args[]){
        Map<Character , Integer> list = new LinkedHashMap<Character , Integer>();
        String str_data;
        int len;
        Scanner scanf = new Scanner(System.in);
        str_data = scanf.next();
        char [] data = str_data.toCharArray();
        for(int i = 0 ; i < data.length ; i++){
            if(list.containsKey(data[i]) == true){
                int num = list.get(data[i]);
                list.put(data[i] , num + 1);
            }
            else{
                list.put(data[i] , 1);
            }
        }

        for(char key : list.keySet()){
            System.out.println(key + "-" + list.get(key));
        }
    }
}
