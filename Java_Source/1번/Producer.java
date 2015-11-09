package dd;

// 생산자 클래스
public class Producer implements Runnable{
	private Buffer buffer;
	
	public Producer(Buffer buffer) {
		this.buffer = buffer;
	}
	@Override
	public void run() {
		for(int i = 0; i<10; i++){
			buffer.put(i);	// 버퍼에 케익을 가져다 놓는다
			System.out.println("생산자 : " + i + " 번 케익을 생산");
			try {
				Thread.sleep((int)(Math.random() * 100));
			} catch(InterruptedException e){}
		}
		
	}

}
