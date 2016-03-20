package exercise;

public class BoundedBuffer implements Buffer{
	private final int[] buffer ={-1, -1};
	
	private int occupiedCells = 0;
	private int writeIndex = 0;
	private int readIndex = 0;
	@Override
	public synchronized void set(int value) throws InterruptedException {
		// TODO Auto-generated method stub
		while (occupiedCells == buffer.length) {
			System.out.println("buffer is full, Producer waits\n");
			wait();
		}
		buffer[writeIndex] = value;
		writeIndex = (writeIndex+1) % buffer.length;
		occupiedCells++;
		System.out.printf("Producer writes\t%2d", value);
		//notify threads waiting to read from buffer
		notify(); 											
		
	}
	@Override
	public synchronized int get() throws InterruptedException {
		// TODO Auto-generated method stub
		while (occupiedCells == 0) {
			System.out.println("buffer is empty. Consumer waits\n");
			wait();
		}
		occupiedCells--;
		int result = buffer[readIndex];
		readIndex = (readIndex+1)%buffer.length;
		notify();
		System.out.printf("Consumer reads\t%2d", result);
		return result;
	}
	

	
}
