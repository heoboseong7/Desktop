package day04;

public class ex04 {
	public static void main(String[] args)	{
		for (int a = 1; a < 4; a++) {
			System.out.println("a:"+a);
			for (int b = 1; b < 4; b++) {
				System.out.println("b:"+b);
				if (a*b > 2)
					break;
				System.out.println("a*b="+a*b);
			}
		}

		BLABEL:
			for (int a = 1; a < 4; a++) {
				System.out.println("a:"+a);
				for (int b = 1; b < 4; b++) {
					System.out.println("b:"+b);
					if (a*b > 2)
						break BLABEL;
					System.out.println("a*b="+a*b);
				}
			}

		for (int a = 1; a < 4; a++) {
			System.out.println("a:"+a);
			for (int b = 1; b < 4; b++) {
				System.out.println("b:"+b);
				if (a*b > 2)
					continue;
				System.out.println("a*b="+a*b);
			}
		}

	
	
	CLABEL:
		for (int a = 1; a < 4; a++) {
			System.out.println("a:"+a);
			for (int b = 1; b < 4; b++) {
				System.out.println("b:"+b);
				if (a*b > 2)
					continue CLABEL;
				System.out.println("a*b="+a*b);
			}
		}

}
}
