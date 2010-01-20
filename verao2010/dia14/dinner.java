import java.util.Scanner;
import java.io.*;
import java.math.BigInteger;

public class dinner
{
    public static void main(String args[]) throws Exception
    {
	Scanner sc = new Scanner(new File("dinner.in"));

	BufferedWriter outS = 
            new BufferedWriter(new FileWriter("dinner.out"));

	int k = sc.nextInt();
	int n = sc.nextInt();

	BigInteger table[][] = new BigInteger[n+1][k+1];

	table[0][0] = BigInteger.ONE;
	for(int i = 1; i <= n; i++)
	    table[i][0] = BigInteger.ZERO;
	for(int j = 1; j <= k; j++)
	    table[0][j] = BigInteger.ZERO;
	for(int i = 1; i <= n; i++)
	    for(int j = 1; j <= k; j++){
		table[i][j] = table[i-1][j].add(table[i-1][j-1]);
		Integer jj = new Integer(j);
		table[i][j] = table[i][j].multiply(new BigInteger(jj.toString()));
	    }
	outS.write(table[n][k].toString());
	outS.newLine();
	outS.close();
    }
}