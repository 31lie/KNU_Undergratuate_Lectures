import java.util.Scanner;
public class overloading {
	
	public static int add(int a, int b) {
		return a+b;
	}
	
	public static double add(double a, double b) {
		return a+b;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int x1 = sc.nextInt();
		int y1 = sc.nextInt();
		System.out.println(add(x1,y1));
		
		double x2 = sc.nextDouble();
		double y2 = sc.nextDouble();
		System.out.printf("%.1f",add(x2,y2));
		
		sc.close(); 
	}
	// 2020114658 이윤서
		// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
}
