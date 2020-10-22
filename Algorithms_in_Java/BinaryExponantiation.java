import java.util.*;
import java.lang.*;

class sloution{

	static long binExp(long a, long b){
		//var to keep result
		long res = 1;
		
		//iterate until power is zero
		while(b > 0){
		
			//multiply result by a if power is odd
			if(b%2 == 1)
				res *= a;
			
			//keep squaring the base
			a = a * a;
			
			//keep dividing power
			b /= 2;
		}
		
		return res;
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		System.out.println(binExp(a, b));
	}
}
