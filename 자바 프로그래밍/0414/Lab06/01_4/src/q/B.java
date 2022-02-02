/* 2020114658 이윤서 */
/* 본인은 이 소스파일 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다. */

package q;

import p.B;

class D extends B {
	void f() {
		n = 3; // pritvate 는 같은 패키지의 같은 클래스에서만 참조 가능하다.
		g(); // 메소드도 마찬가지
		
	}
}
