
public class NewYorkPizzaStore extends PizzaStore{

	@Override
	public Pizza createPizza(String type) {
		Pizza pizza = null;
		if(type.equals("Peperoni")){
			pizza = new PeperoniPizza("���۷δ� ����", new ChicagoPizzaFactory());
		}
		else if(type.equals("Cheese")){
			pizza = new CheesePizza("ġ�� ����", new ChicagoPizzaFactory());
		}
		return pizza;
	}
	

}
