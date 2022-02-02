
/* 컴퓨터학부 심화컴퓨터전공 2020114658 이윤서 */
/* 본인은 이 소스 파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다. */


class Animal {
	void show() {
		System.out.println("Animal: show()");
	}
}

class Fish extends Animal {
	void draw() {
		System.out.println("Fish: draw()");
	}
	void move() {
		System.out.println("Fish: move()");
	}
}

class GoldFish extends Fish {
	void move() {
		System.out.println("GoldFish: move()");
	}
}
public class AnimalTest {

	public static void main(String[] args) {
		Fish fish = new GoldFish(); //upcasting
		fish.move(); // GoldFish 클래스의 move 메소드가 호출

	}

}
