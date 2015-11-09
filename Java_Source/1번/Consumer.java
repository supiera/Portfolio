package dd;

public class Consumer implements Runnable{
	private Buffer buffer;
	
	public Consumer(Buffer drop) {
		this.buffer = drop;
	}
	
	@Override
	public void run() {
		for(int i = 0; i< 10; i++){
			int data = buffer.get();
			System.out.println("소비자 : " + data + " 번 케익을 소비");
			try {
				Thread.sleep((int)(Math.random() * 100));
			} catch(InterruptedException e){}
		}
		
	}

}
