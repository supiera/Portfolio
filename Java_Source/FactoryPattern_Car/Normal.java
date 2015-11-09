
public class Normal extends CarOption{
	public Normal(CarFactory factory){
		super(factory);
		this.transmission = new AutomaticTransmission();
		System.out.println("수동기어 장착");
	}
}
