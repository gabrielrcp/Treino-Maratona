import java.util.Scanner;
import java.io.*;
import java.math.BigInteger;

public class Main
{
    public static void main(String args[]) throws Exception
    {
	Scanner sc = new Scanner(System.in);

	int casos = sc.nextInt();

	BigInteger fat[] = new BigInteger[101];
	fat[0] = BigInteger.ONE;

	for(int n = 1; n <= 100; n++)
	    fat[n] = fat[n-1].multiply(BigInteger.valueOf(n));

	while(casos-- > 0){
	    int n = sc.nextInt();
	    System.out.println(fat[n]);
	}
    }
}