import java.util.Scanner;
import java.io.*;
import java.math.BigInteger;

public class b
{
    public static BigInteger tempos[];
    public static int n;


    public static BigInteger diff(int i)
    {
	return tempos[i].subtract(tempos[i-1]).abs();
    }
    public static BigInteger mdc(BigInteger a, BigInteger b)
    {
	if(a.compareTo(b) > 0) // a > b
	    return mdc(b, a);
	if(a.equals(BigInteger.ZERO))
	    return b;
	return mdc(b.mod(a), a);
    }

    public static void main(String args[]) throws Exception
    {
	Scanner sc = new Scanner(System.in);
	int casos = sc.nextInt();

	for(int h = 1; h <= casos; h++){
	    n = sc.nextInt();
	    tempos = new BigInteger[n];
	    for(int i = 0; i < n; i++)
		tempos[i] = sc.nextBigInteger();
	    BigInteger T = diff(1);
	    for(int i = 2; i < n; i++)
		T = mdc(T, diff(i));
	    BigInteger y = tempos[0].mod(T);
	    if(!y.equals(BigInteger.ZERO))
		y = T.subtract(y);
	    System.out.println("Case #"+h+": "+y.toString());
	}
    }
}