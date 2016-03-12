package exersize;

interface In1 {
	int method(int a, int b);
}

interface In2 {
	double method(int a, int b);
	int method(double a, double b);
}

public class B implements In1, In2{

	@Override
	public int method(int a, int b) {
		// TODO Auto-generated method stub
		return 0;
	}
	@Override
	public double method(int a, int b) {
		// TODO Auto-generated method stub
		return 0;
	}
	@Override
	public int method(double a, double b) {
		// TODO Auto-generated method stub
		return 0;
	}
	
	public static void main (String argv[]) {
		B b = new B();
		b.method(1, 2);
	}
}
