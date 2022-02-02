// 2020114658 이윤서
// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

//enum type Color 선언 : 4개의 상수
enum Color{
	WHITE, BLACK, YELLOW, RED
}

public class ColorTest1 {

	public static void main(String[] args) {
		
		//Color형 constant를 배열로 받아 순서대로 출력하기
		//enhanced for문 사용하기
		//for문 body는 하나의 문장으로 구성
		
		for (Color color : Color.values()) {
			System.out.println(color);
		}
	}

}
