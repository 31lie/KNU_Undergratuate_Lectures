/* 2020114658 이윤서 */
/* 본인은 이 소스파일 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다. */

package q;

import p.B; //default 클래스는 다른 패키지에서 접근하지 못한다.

public class A {
	//마찬가지의 이유로, default 이더라도 오류 발생
	
	B b = new B();
	b.n=3;
	b.g();

}
