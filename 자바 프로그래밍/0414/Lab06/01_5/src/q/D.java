/* 2020114658 이윤서 */
/* 본인은 이 소스파일 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다. */

package q;

import p.B; // default 클래스는 다른 패키지에서 접근하지 못한다.


class D extends B { // 그러니 상속도 불가능하고,
	void f() {	//import 되지 못함
		n=3;
		g();
	}

}
