
public class ItallianPizzaFactory implements PizzaFactory{

	@Override
	public Dough createDough() {
		System.out.println("ThinDough Created");
		Dough d = new ThinDough();
		return d;
	}

	@Override
	public Source createSauce() {
		System.out.println("MarianaSauce Created");
		Source s = new MarianaSauce();
		return s;
	}

	@Override
	public Chese createCheese() {
		System.out.println("PizzaCheese Created");
		Chese c = new PizzaCheese();
		return c;
	}


}
