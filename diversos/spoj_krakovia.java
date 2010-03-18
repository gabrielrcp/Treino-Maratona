import java.util.Scanner;
import java.io.*;
import java.math.BigInteger;

public class Main
{
    public static void main(String args[]) throws Exception
    {
	Scanner sc = new Scanner(System.in);

	while(1){
	    int n = sc.nextInt();
	    if(n == 0) break;
	    BigInteger f = BigInteger.valueOf(sc.nextInt());

	    BigInteger s = BigInteger.ZERO;
	    for(int i = 0; i < n; i++){
		s = s.sum(new BigInteger(sc.next()));
	    }
	    System.out.println(s);
	}
    }
}