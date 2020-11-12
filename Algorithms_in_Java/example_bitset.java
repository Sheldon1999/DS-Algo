import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// Scanner sc = new Scanner(System.in);

		// long t = sc.nextLong();

		// long cas = t;

		// while(t-- > 0){
		// 	long n = sc.nextLong();
			
		// }

		isPrime = new BitSet((int)n+1);

		long k = 8 * (long)Math.pow(10, 6);

		arr = new long[(int)k];

		long i , j;

		//setting 0 and 1 as non prime
		isPrime.set(0);
		isPrime.set(1);

		//setting all even no except 2 to non prime
		for(i = 4;i <= n;i += 2){
			isPrime.set((int)i);
		}

		//using Sieve of Eratosthenes
		//and also skipping every even no
		for(i = 3;i*i <= n;i += 2){

			//if not set -> is prime
			if(isPrime.get((int)i) == false){

				//starting from i^2 cuz
				//all the previous must be covered
				//and here we are jumping to 2*i
				//cuz all in between are even and 
				//has covered previously
				for(j = i*i;j <= n;j += 2*i){
					isPrime.set((int)j);
				}

			}

		}

		j = 0;
		//now filling the array of primes to be printed
		arr[0] = 2;
		for(i = 3;i <= n;i += 2){

			if(isPrime.get((int)i) == false){

				arr[(int)++j] = i;

			}

		}

		//finally print it:
		for(i = 0;i <= j;i += 100){
			System.out.println(arr[(int)i]);
		}

	}

	public static long[] arr;

	public static long n = (long)Math.pow(10, 8);

	public static BitSet isPrime;
	
}
