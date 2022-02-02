// 2020114658 이윤서
// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

import java.util.EnumSet;

//enum type MyColor 선언 : 4개의 상수
//1개의 String field, Constructor, field를 리턴하는 get 메소드로 구성됨

enum MyColor{
	WHITE("Nina"), BLACK("Yuna"), YELLOW("Sumi"), RED("Mimi");
	
	private final String name;
	
	MyColor(String name){
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
}

public class ColorTest2 {

	public static void main(String[] args) {
		// MyColor형 constant를 배열로 받아 순서대로 출력하기
		// enhanced for문 사용하기
		// for문 body는 하나의 문장으로 구성됨
		for (MyColor myColor : MyColor.values()) {
			System.out.printf("%s-%s\n", myColor,myColor.getName());
		}
	
		System.out.println();
		
		// MyColor형 constant 중 2~3번째를 배열로 받아 순서대로 출력하기
		// enhanced for문 사용하기
		// for문 body는 하나의 문장으로 구성됨
		for (MyColor myColor : EnumSet.range(MyColor.BLACK, MyColor.YELLOW)) {
			System.out.printf("%s-%s\n", myColor, myColor.getName());
		}
	}

}
