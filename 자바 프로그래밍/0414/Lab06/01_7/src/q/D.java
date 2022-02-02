/* 2020114658 이윤서 */
/* 본인은 이 소스파일 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다. */

package q;

import p.B; // default 클래스는 다른 패키지에서 접근하지 못한다.

public class D extends B { //그러므로 상속 또한 안되고,
	
	void f() { //오류가 발생함은 자명.
		n=3;
		g();
	}

}
