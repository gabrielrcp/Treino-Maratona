import java.util.Scanner;
import java.io.*;
import java.math.BigInteger;

public class Main
{
    public static void main(String args[]) throws Exception
    {
	Scanner sc = new Scanner(System.in);

	int casos = 10;
	BigInteger dois = BigInteger.valueOf(2);

	while(casos-- > 0){
	    BigInteger a = new BigInteger(sc.next());
	    BigInteger b = new BigInteger(sc.next());
	    BigInteger y = (a.subtract(b)).divide(dois);
	    BigInteger x = y.add(b);

	    System.out.println(x);
	    System.out.println(y);
	}
    }
}