import java.io.*;

public class task2{
    static void maxSub(int A[], int N){
        int start=0,end=0,max_so_far = A[0],current_max = A[0];
        int i;
        for(i = 1; i < N; i++){
            if(A[i] > current_max + A[i]){
                start = i;
                current_max = A[i];
            }
            else
                current_max = current_max + A[i];

            if(current_max > max_so_far){
                end = i;
                max_so_far = current_max;
            }

        }
        for(i = start; i <= end; i++){
            System.out.print(A[i] + " ");
        }
        System.out.printf("\n");
    }
    public static void main(String[] args) {
        int a[] = {4 ,-30 ,0 ,7 ,42 ,-20 ,18 ,400 ,-123 ,-6};
        int size = a.length;
        maxSub(a, size);
    }
}