
public class Superior extends CarOption{
	public Superior(CarFactory factory){
		super(factory);
		this.cruisecontrol = new CruiseControl();
		this.transmission = new AutomaticTransmission();
		System.out.println("�ڵ� ���� ����");
		System.out.println("ũ���� ��Ʈ�� ����");
	}

}
