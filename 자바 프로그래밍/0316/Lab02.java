package lab02;

import java.util.Scanner;


public class Lab02 {
	
	static void q1()
	
	{
		String hm;
		String jb;
		int hm_int=0, jb_int=0;
		int result =-2;
		Scanner sc = new Scanner(System.in);
		
		while (result != -1) {
			
			System.out.println("가위 바위 보 게임입니다. 가위, 바위, 보 중에서 입력하세요.");
			System.out.print("혜미 >> ");
			hm = sc.nextLine();
			System.out.print("준범 >> ");
			jb= sc.nextLine();
			
			if (hm.equals("가위")) {
				hm_int=0;
			}
			
			else if (hm.equals("바위")) {
				hm_int=1;
			}
			
			else if (hm.equals("보")) {
				hm_int=2;
			}
			
			else {
				System.out.println("잘못된 입력입니다.");
			}
			
			if (jb.equals("가위")) {
				jb_int=0;
			}
			
			else if (jb.equals("바위")) {
				jb_int=1;
			}
			
			else if (jb.equals("보")) {
				jb_int=2;
			}
			
			else {
				System.out.println("잘못된 입력입니다.");
			}
			
			result = (jb_int-hm_int+3)%3;
			
			if (result==0) {
				System.out.println("무승부입니다.");
			}
			
			else if (result==1) {
				System.out.println("준범이 이겼습니다.");
			}
			
			else {
				System.out.println("혜미가 이겼습니다.");
			}
			
			System.out.println("게임을 종료하시려면 'exit'를 입력해주세요.");
			String answer = sc.next();
			if (answer.equals("exit")) {
				result= -1;
			}
			
		}
		sc.close();
	}

		static void q2() {
			
			Scanner sc = new Scanner(System.in);
			int number = 0;
			int[] nums = new int[2];
			
			System.out.print("Enter integer : ");
			number = sc.nextInt();
			
			if (number != -1) {
			
				nums[0]=number;
				nums[1]=number;
				
				while (number != -1) {
					System.out.print("Enter integer : ");
					number = sc.nextInt();
					
					if (number ==-1)
						break;
					
					
					if (number<nums[0]) {
						nums[0] = number;
					}
					
					if (number>nums[1]) {
						nums[1] = number;
					}
				}
				 
				
				System.out.printf("Smallest Integer is : %d\n", nums[0]);
				System.out.printf("Largest Integer is : %d", nums[1]);
			}
			
			
			sc.close();
			
		}
		
		static void q3() {
			
			int x, y;
			Scanner sc = new Scanner(System.in);
			
			System.out.print("x: ");
			x = sc.nextInt();
			System.out.print("y: ");
			y = sc.nextInt();
			
			if ((x>=50 && x<=100) && (y>=50 && y<=100)) {
				System.out.printf("점 (%d,%d)는 이 직사각형 안에 있습니다.",x,y);
			}
			
			else {
				System.out.printf("점 (%d,%d)는 이 직사각형 안에 없습니다.",x,y);
			}
			
			sc.close();
			
		}
		
		static void q4() {
			int x1, y1,x2,y2;
			Scanner sc = new Scanner(System.in);
			
			System.out.print("x1: ");
			x1 = sc.nextInt();
			System.out.print("y1: ");
			y1 = sc.nextInt();
			System.out.print("x2: ");
			x2 = sc.nextInt();
			System.out.print("y2: ");
			y2 = sc.nextInt();
			
			
			//1번
			
			if ((x1<50 && x2<=50) || (y1<50 && y2<50) || (x1>100 && x2>100) || (y1>100 && y2>100)) {
				System.out.println("충돌하지 않습니다.");
			}
			
			
			
			else {
				System.out.println("충돌합니다.");
			
			}
			sc.close();
		}
	
	

	public static void main(String[] args) {
		
		/* 2020114658 이윤서 */
		// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
		//q1();
		//q2();
		//q3();
		q4();

	}

}
