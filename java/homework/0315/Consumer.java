package exercise;

import java.util.Random;

public class Consumer implements Runnable{
	private final static Random generator = new Random();
	private final BoundedBuffer sharedLocation;
	public Consumer(BoundedBuffer shared) {
		// TODO Auto-generated constructor stub
		sharedLocation = shared;
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		int sum = 0;
		for (int i = 1; i <= 10; i++) {
			try {
				Thread.sleep(generator.nextInt(3000));
				sum += sharedLocation.get();
				System.out.printf("\t %2d\n", sum);
				
			} catch (InterruptedException e) {
				// TODO: handle exception
				e.printStackTrace();
			}
		}
		System.out.printf("\n%s %s\n%s\n", "Consumer read values totaing", sum, "Terminating Consumer");
	}
}
