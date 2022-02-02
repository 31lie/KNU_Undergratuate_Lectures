
public class Test {
	
	private static int num1; // num1은 static 변수
	private int num2;

	public static void show1(){
		System.out.println(num1); // O
		System.out.println(num2); // X : static 메소드 안에서는 static 변수만 호출 가능하다.
		show4(); //O
		show5(); //X : static 이 아니기 때문에 static 메소드에서 호출 불가능하다.
	}
	
	public void show() {
		System.out.println(num1); //O
		System.out.println(num2); //O
		show4(); //O
		show5(); //O
	}
	public static void show4() { }
	public void show5() { }
	
	
	// 2020114658 이윤서
	// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
	

}
