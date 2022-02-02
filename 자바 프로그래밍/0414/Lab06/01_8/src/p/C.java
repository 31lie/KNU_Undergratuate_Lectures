/* 2020114658 이윤서 */
/* 본인은 이 소스파일 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다. */

package p;

class C {
	public void k() {
		B b= new B();
		// default 클래스에서 private 변수가 선언되면 클래스에서만 참조 가능하다.
		b.n=7;
		// 메소드도 마찬가지
		b.g();
	}
}
