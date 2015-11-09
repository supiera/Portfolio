
public abstract class CarOption {
	public CarFactory factory;
	public Transmission transmission;
	public CruiseControl cruisecontrol;
	public Wheel wheel;
	public Engine engine;
	
	public CarOption(CarFactory factory){
		this.factory = factory;
		createCarOption();
	}
	
	
	public void createCarOption(){
		this.engine = factory.createEngine();
		this.wheel = factory.createWheel();
	}
}
