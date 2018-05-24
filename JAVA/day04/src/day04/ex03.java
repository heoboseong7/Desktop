package day04;
import java.util.Scanner;
public class ex03 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int maxnow;
		for(int i = 0; i < n + 1; i++)	{
			for(int j = n; j > 0; j--)	{
				if(j > i)
					System.out.print("   ");
				else
					System.out.printf("%3d", j);
			}
			
			for(int j = 2; j < n + 1; j++) {
				if(j > i)
					break;
				else
					System.out.printf("%3d", j);
			}
			System.out.println();
		}
	}

}
