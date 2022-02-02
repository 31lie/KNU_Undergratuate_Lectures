import java.util.Scanner;

public class multiple {
	
	public static void correct(int num){
		if (num==1) {
			System.out.println("Very good!");
		}
		if (num==2) {
			System.out.println("Excellent!");
		}
		if (num==3) {
			System.out.println("Nice work!");
		}
		if (num==4) {
			System.out.println("Keep up the good work!");
		}
	}

	
	public static void wrong(int num){
		if (num==1) {
			System.out.println("No. Please try again");
		}
		if (num==2) {
			System.out.println("Wrong. Try once more.");
		}
		if (num==3) {
			System.out.println("Don't give up!");
		}
		if (num==4) {
			System.out.println("No. Keep trying");
		}
	}
	
	
	public static void main(String[] args) {

		int answer = 0;
		Scanner sc = new Scanner(System.in);
		
		while (answer>=0) {
			int a = (int)((Math.random()*10000)%9+1);
			int b = (int)((Math.random()*10000)%9+1);
			
			
			System.out.printf("How much is %d times %d?\n",a,b);
			System.out.println("Enter your anwer (-1 to exit): ");

			answer = sc.nextInt();
			
			if (answer!=-1) {
				int result = (int)((Math.random()*10000)%4+1);
				
				while (answer!=a*b) {
					wrong(result);
					System.out.println("Enter your anwer (-1 to exit): ");
					answer = sc.nextInt();
					if (answer==-1) {
						break;
					}
					result = (int)((Math.random()*10000)%4+1);
					
				}
				if (answer==a*b) {
					correct(result);
				}
				
			}
			
			
		}
		
		System.out.println("Finish");
		sc.close();
		
		
		
		
	}
	// 2020114658 이윤서
	// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

}
