package dd;

// ������ Ŭ����
public class Producer implements Runnable{
	private Buffer buffer;
	
	public Producer(Buffer buffer) {
		this.buffer = buffer;
	}
	@Override
	public void run() {
		for(int i = 0; i<10; i++){
			buffer.put(i);	// ���ۿ� ������ ������ ���´�
			System.out.println("������ : " + i + " �� ������ ����");
			try {
				Thread.sleep((int)(Math.random() * 100));
			} catch(InterruptedException e){}
		}
		
	}

}
