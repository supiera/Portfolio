
public class PeperoniPizza extends Pizza{

	public PeperoniPizza(String name, PizzaFactory factory) {
		super(name, factory);
	}

	@Override
	public void topping() {
		System.out.println("HamTopping");
		this.topping = new HamTopping();
	}

}
