
public abstract class Car {
	public CarOption option;
	public CarFactory factory;
	public CruiseControl cruisecontrol;
	public Transmission transmission;
	
	public Car(){
	
	}
	public abstract void setOption(String type);
}
