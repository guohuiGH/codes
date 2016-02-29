
public class CalculatePi {
	public double calculate(int terms) {
		double pi = 0.0;
		for (int i = 1; i <= terms; i++) {
			if (i%2==0) {
				pi -= (double)4/(i*2-1);
			}else {
				pi += (double)4/(i*2-1);
			}
			//System.out.print(pi);
		}
		return pi;
	}
	
	public int terms (double target) {
		int i = 1;
		double pi = 0.0;
		int t = (int)(target*100000);
		//System.out.print("hi");
		while(true) {
			if (i%2==0) {
				pi -= (double)4/(i*2-1);
			}else {
				pi += (double)4/(i*2-1);
			}
			int temp = (int)(pi*100000);
			if (temp == t)
				return i;
			i++;
		}
	}
	public static void main(String[] s) {
		CalculatePi c = new CalculatePi();
		System.out.println(c.calculate(200000));
		System.out.print(c.terms(3.14159));
	}
}
