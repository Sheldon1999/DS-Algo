import java.util.*;
import java.lang.*;
import java.io.*;

/* 
example usage of hashmaps
*/

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
	 
		fillHm();

		long t = sc.nextLong();

		while(t-- > 0){
			long n = sc.nextLong();
			
			if(hm.containsKey(n)){
				
				System.out.println("IsFibo");

			}else{

				System.out.println("IsNotFibo");

			}
		}
	}
	
	public static HashMap<Long, Long> hm = new HashMap<>();

	public static void fillHm(){
		long a = 0;
		long b = 1;
		long c = 0;
		hm.put(a,(long)1);
		hm.put(b,(long)1);
		do{
			c = a+b;
			hm.put(c,(long)1);
			a = b;
			b = c;
		}while(c <= Math.pow(10, 10));
	}
	
}
