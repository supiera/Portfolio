package dd;

// 임시적으로 보관하는  buffer class
public class Buffer {
	private int data;		//생산자로부터 소비자로 전해지는 데이터
	private boolean empty = true;	//소비자가 기다리고 있으면  T, 생산자가 기다리고 있으면 F
	
	public synchronized int get(){
		while(empty){
			try{
				wait();
			} catch (InterruptedException e){
				
			}
		}
		empty = true;		//상태 토글
		notifyAll(); 	//생산자에게 알림
		return data;
	}
	
	public synchronized void put(int data){
		while(!empty){
			try {
				wait();
			} catch(InterruptedException e) {
				
			}
		}
		empty = false;
		this.data = data;
		notifyAll();	// 소비자에게 알림
	}
}
