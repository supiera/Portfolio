
public class RomaPizzaStore extends PizzaStore{

	@Override
	public Pizza createPizza(String type) {
		Pizza pizza = null;
		if(type.equals("Peperoni")){
			pizza = new PeperoniPizza("페퍼로니 피자", new ItallianPizzaFactory());
		}
		else if(type.equals("Cheese")){
			pizza = new CheesePizza("치즈 피자", new ItallianPizzaFactory());
		}
		return pizza;
	}

}
