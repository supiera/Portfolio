
public class Superior extends CarOption{
	public Superior(CarFactory factory){
		super(factory);
		this.cruisecontrol = new CruiseControl();
		this.transmission = new AutomaticTransmission();
		System.out.println("자동 변속 장착");
		System.out.println("크루즈 컨트롤 장착");
	}

}
