package exersize;

public class D {
	
	void testException (int a, int b) throws Exception {
		try {
			System.out.println("i am in try block");
			int c = a/b;
		} catch (ArithmeticException e) {
			// TODO: handle exception
			System.out.println("i am in catch block");
			//throw new Exception();
			System.exit(0);
		} finally {
			System.out.println("i am in finally block");
		}
	}
	
	public static void main (String argv[]) {
		D d = new D();
		try {
			d.testException(1, 0);
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("reset the numbers");
		}
	}
}
