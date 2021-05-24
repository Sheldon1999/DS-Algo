import java.util.Scanner;

class SelectionSort{

    public static void swapInArray(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void SelectionSort(int[] arr){
        int len = arr.length;

        for(int i = 0;i < len-1;++i){
            for(int j = i+1;j < len;++j){
                if(arr[i] > arr[j]){
                    swapInArray(arr, i, j);
                }
            }

            System.out.println("after interation-"+(i+1)+": ");
            for(int m : arr){
                System.out.print(m + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0;i < n;++i){
            arr[i] = sc.nextInt();
        }
        SelectionSort(arr);
        System.out.println("\nhence final sorted array: ");
        for(int i : arr){
            System.out.print(i+" ");
        }
    }
}
