
public class Craps {

	private enum Status { CONTINUE, WON, LOST };
	private enum Numbers ( ZERO, ONE, TWO);
	
	public void play() {
		
		//Syntax Errors
		//enum의 상수와 int형은 비교 불가능하며, 따라서 대입 연산자도 사용 불가능
		int intNum1 = Status.CONTINUE; 
		int intNum2 = (int)Status.CONTINUE; 
		Status enmNum1 = 1; // 
		Status enmNum2 = (Status)1;
		
		//correct statements
		//enum 형과 enum 형의 비교이므로 오류가 나지 않는다
		Numbers enumNum = Numbers.ZERO;
		switch (enumNum) 
		{
			case ZERO:
				break;
			case ONE:
				break;
			case TWO:
				break;
		}
		
		//correct statements
		//int와 int형의 switch 연산. final은 그저 변경 불가능한 상수값임을 나타낸다.
		final int intConsNum = 0;
		int intNum3 =0;
		switch (intNum3) 
		{
			case intConsNum:
				break;
		}
		
		//syntax error
		//int(intNum4)와 enum(ZERO)형의 비교 불가능
		int intNum4 = 0;
		switch(intNum4)
		{
			case ZERO:
				break;
		}
	}
	// 2020114658 이윤서
		// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
}
