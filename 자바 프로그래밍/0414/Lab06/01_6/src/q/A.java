/* 2020114658 이윤서 */
/* 본인은 이 소스파일 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다. */


package q;

import p.B;// default 클래스는 다른 패키지에서 접근하지 못한다.


public class A {
	
	//마찬가지의 이유로, 일단 default 클래스에서 선언되었기 때문에 public 이던 protected 던 차이가 없다.
	

	B b = new B();
	b.n=3;
	b.g();
}
