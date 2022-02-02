/* 2020114658 이윤서 */
/* 본인은 이 소스파일 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다. */

package q;

import p.B;

public class A {
	void f() {
		B b = new B();
		b.n = 3;	//Private 는 같은 패키지 같은 클래스 안에서만 참조 가능하다.
		b.g(); //메소드도 마찬가지
	}
}
