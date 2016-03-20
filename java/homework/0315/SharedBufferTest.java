package exercise;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class SharedBufferTest {
	public static void main (String []args) {
		ExecutorService application = Executors.newCachedThreadPool();
		BoundedBuffer sharedLocation = new BoundedBuffer();
		//UnsynchronizedBuffer unsynchronizedBuffer = new Buffer();
		System.out.println("Action\t\tValue\tSum of Produced\tSum of Consumed");
		application.execute(new Producer(sharedLocation));
		application.execute(new Consumer(sharedLocation));
		
		application.shutdown();
	}
}
