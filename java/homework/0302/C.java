package exersize;

public class C {
	
	void method1() {
		System.out.println("method1 in C");
	}
	public interface Inter {
		void method2();
	} 
	
	public class Temp extends C implements Inter {

		@Override
		public void method2() {
			// TODO Auto-generated method stub
			System.out.println("realise interface");
		}
		
	}
	public static void main (String argv[]) {
		C c = new C();
		C.Temp temp = c.new Temp();
		temp.method2();
		temp.method1();
	}
}
