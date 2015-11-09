package dd;

// �ӽ������� �����ϴ�  buffer class
public class Buffer {
	private int data;		//�����ڷκ��� �Һ��ڷ� �������� ������
	private boolean empty = true;	//�Һ��ڰ� ��ٸ��� ������  T, �����ڰ� ��ٸ��� ������ F
	
	public synchronized int get(){
		while(empty){
			try{
				wait();
			} catch (InterruptedException e){
				
			}
		}
		empty = true;		//���� ���
		notifyAll(); 	//�����ڿ��� �˸�
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
		notifyAll();	// �Һ��ڿ��� �˸�
	}
}
