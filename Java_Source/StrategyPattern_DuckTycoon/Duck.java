
public abstract class Duck {
	private String name;
	protected FlyBehavior flyBehavior;
	
	public Duck(String duckName){
		this.name = duckName;
	}
	
	public String getName(){
		return this.name;
	}
	
	public void swim(){
		System.out.println("헤엄친다");
	}
	
	public void performFly(){
		this.flyBehavior.fly();
	}
}
