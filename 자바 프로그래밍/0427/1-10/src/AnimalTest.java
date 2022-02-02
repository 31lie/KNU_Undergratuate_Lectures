
/* 컴퓨터학부 심화컴퓨터전공 2020114658 이윤서 */
/* 본인은 이 소스 파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다. */


class Animal {
	void show() {
		System.out.println("Animal: show()");
	}
	void move() {
		System.out.println("Animal: move()");
	}
}

class Fish extends Animal {
	void draw() {
		System.out.println("Fish: draw()");
	}
	void show() {
		System.out.println("Fish: show()");
	}
	void move() {
		System.out.println("Fish: move()");
	}
	
}

class GoldFish extends Fish {
	void move() {
		System.out.println("GoldFish: move()");
	}
	void draw() {
		System.out.println("GoldFish: draw()");
	}
	
}
public class AnimalTest {

	public static void main(String[] args) {
		GoldFish goldFish = new GoldFish();
		goldFish.show();
		
		Animal animal = new Fish()
		animal.draw();
		// There is no draw method in animal class. We shoud downcasting for Fish class.
		//animal 클래스에는 draw 메소드가 없다. Fish 클래스로 downcasting 해주어야 함.
		
		Animal animal2 = new Fish();
		animal2.show();
		animal2.move();
		
		Animal animal3 = new GoldFish();
		((Fish)animal3).draw();

	}

}
