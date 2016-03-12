package exersize;

class A {
	protected int a = 10;
	void setA (int a) {
		this.a = a;
	}
	void setSuperA (int a) {
		this.a = a;
	}
	void getA() {
		System.out.println("base class : " + this.a);
	}
}

public class OverridenVariable extends A{
	
	void setA (int a) {
		this.a = a;
	}
	void getA() {
		System.out.println("subclass a : " + this.a);
	}
	
	public static void main (String argv[]) {
		
		A va = new A();
		System.out.println(va.a);
		va.setA(9); va.getA();
		OverridenVariable vb = new OverridenVariable();
		vb.getA();
		vb.setA(8); vb.getA();
		vb.setSuperA(7); vb.getA();
		
	}
}


