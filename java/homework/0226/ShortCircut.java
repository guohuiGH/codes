
public class ShortCircut {
	
	public void testAnd(boolean statement1, boolean statement2) {
		if (!(statement1 && statement2))
			System.out.println("this is the test of &&");
	}
	
	public void testOr (boolean statement1, boolean statement2) {
		if (statement1 || statement2)
			System.out.println("this is the test of ||");
	}
	
	public static void main(String args[]) {
		ShortCircut sc = new ShortCircut();
		boolean st1 = false, st2 = false, st3 = true, st4 = true;
		sc.testAnd(st1, st2);
		st2 = true;
		sc.testAnd(st1, st2);
		sc.testOr(st3, st4);
		st4 = false;
		sc.testOr(st3, st4);
	}
}
