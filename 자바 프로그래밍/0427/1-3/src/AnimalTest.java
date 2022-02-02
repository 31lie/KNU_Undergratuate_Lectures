
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
}

class GoldFish extends Fish {
	void move() {
		System.out.println("GoldFish: move()");
	}
}


public class AnimalTest {

	public static void main(String[] args) {
		Fish fish = new Fish();
		fish.move(); 
		// fish 클래스나, fish 가 상속받고 있는 Animal 클래스나 move 메소드가 없음. Goldfish.move() 로 바꿔야 한다.
		// Both of fish class and Animal class which is inherited by class Fish, don't have move method. So we should change it to Goldfish.move()
	}

}
