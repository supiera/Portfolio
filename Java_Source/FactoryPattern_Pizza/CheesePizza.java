
public class CheesePizza extends Pizza{

	public CheesePizza(String name, PizzaFactory factory) {
		super(name, factory);
	}

	@Override
	public void topping() {
		System.out.println("CheeseTopping");
		this.topping = new CheeseTopping();
	}

}
