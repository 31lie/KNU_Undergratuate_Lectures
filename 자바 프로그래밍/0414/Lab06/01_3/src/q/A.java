/* 2020114658 이윤서 */
/* 본인은 이 소스파일 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다. */

package q;

import p.B;

public class A {
	void f() {
		B b = new B();
		b.n=3;	//public 클래스에서 선언된 default 변수는 다른 패키지에서 참조할 수 없다.
		b.g(); // 메소드도 마찬가지
	}
}
