/* 2020114658 ������ */

public class Test {
	
	public static void main(String[] args) {
		F f = new F();
		f.methodA();
		f.methodB();
		f.methodC();
		f.methodD();
	}
}

interface A {
	public void methodA();
}

class B {
	public void methodB() {
		System.out.println("methodB");
	}
}

interface C extends A {
	public void methodC();
}

interface D {
	public void methodD();
}

abstract class E extends B implements C, D {
	public void methodA() {
		System.out.println("implementation of methodA in class E");
	}
}

class F extends E {
	public void methodC() {
		System.out.println("implementation of methodC in class F");
	}
	public void methodD() {
		System.out.println("implementation of methodD in class F");
	}
}
