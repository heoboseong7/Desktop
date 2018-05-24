package day04;
import java.util.Scanner;
public class ex02 {
	public static void main(String[] args)	{
		Scanner input = new Scanner(System.in);
		int a, total = 0;
		
		while(true) {
			System.out.print("Input value : ");
			a = input.nextInt();
			if(a != 0)	{
				total += a;
				System.out.println("Total : "+total);
			}
			else
				break;
		}
		
		System.out.println("End");
		input.close();
	}
}