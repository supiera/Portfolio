
public class RomaPizzaStore extends PizzaStore{

	@Override
	public Pizza createPizza(String type) {
		Pizza pizza = null;
		if(type.equals("Peperoni")){
			pizza = new PeperoniPizza("���۷δ� ����", new ItallianPizzaFactory());
		}
		else if(type.equals("Cheese")){
			pizza = new CheesePizza("ġ�� ����", new ItallianPizzaFactory());
		}
		return pizza;
	}

}
