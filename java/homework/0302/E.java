package exersize;

public class E {

	public static void main (String argv[]) {
		
		int a[] = {1,2};
		int b = 0;
		try {
			a[3] = 1;
			b = a[0]/b;
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("I am wrong");
		}
		
		try {
			a[3] = 1;
			b = a[0]/b;
		} catch ( ArithmeticException e) {
			// TODO: handle exception
			System.out.print("Arithmetic Exception! ");
		} catch (ArrayIndexOutOfBoundsException e) {
			// TODO: handle exception
			System.out.println("Array index out of Bound");
		}
	}
}
