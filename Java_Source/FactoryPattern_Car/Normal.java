
public class Normal extends CarOption{
	public Normal(CarFactory factory){
		super(factory);
		this.transmission = new AutomaticTransmission();
		System.out.println("������� ����");
	}
}
