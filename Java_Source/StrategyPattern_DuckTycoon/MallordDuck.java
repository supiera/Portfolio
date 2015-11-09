
public class MallordDuck extends Duck{
	
	public MallordDuck(String name){
		super(name);
		this.flyBehavior = new FlyWithWings();
	}
}
