

/* 컴퓨터학부 심화컴퓨터전공 2020114658 이윤서 */
/* 본인은 이 소스 파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다. */


class Animal {
	void move() {
		System.out.println("Animal: move()");
	}
}

class Fish extends Animal {
	void move() {
		System.out.println("Fish: move()");
	}
}

class Frog extends Animal {
	void move() {
		System.out.println("Frog: move()");
	}
}

class Bird extends Animal {
	void move() {
		System.out.println("Bird: move()");
	}
}




public class AnimalTest {

	public static void main(String[] args) {
		Animal[] animal = new Animal[3];
		animal[0] = new Fish();
		animal[1] = new Frog();
		animal[2] = new Bird();
		
		for (int i=0;i<animal.length;i++) {
			animal[i].move();
		}
	}

}
