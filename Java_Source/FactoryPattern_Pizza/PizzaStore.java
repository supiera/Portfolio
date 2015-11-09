
public abstract class PizzaStore {
	public PizzaFactory factory;
	
	public Pizza orderPizza(String type){
		Pizza p = this.createPizza(type);
		p.prefare();
		p.topping();
		p.bake();
		p.cut();
		p.box();
		
		return p;
	}
	
	public abstract Pizza createPizza(String type);
}
