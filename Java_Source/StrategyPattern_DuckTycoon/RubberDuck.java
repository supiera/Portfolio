
public class RubberDuck extends Duck{
	RubberDuck(String name){
		super(name);
		this.flyBehavior = new FlyNoWay();
	}
}
