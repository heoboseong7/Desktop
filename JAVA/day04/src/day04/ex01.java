package day04;

import java.util.Scanner;
public class ex01 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int i = 0;
		int sum = 0;
		while(n > i) {
			sum += ++i;
			if(i != n)
				System.out.print(i+"+");
			else
				System.out.print(i);
		}
		
		System.out.println("=" +sum);
		input.close();
	}
}