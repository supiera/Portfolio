
public class ChicagoPizzaFactory implements PizzaFactory{

	@Override
	public Dough createDough() {
		System.out.println("ThickDough Created");
		Dough d = new ThickDough();
		return d;
	}

	@Override
	public Source createSauce() {
		System.out.println("TomatoSauce Created");
		Source s = new TomatoSauce();
		return s;
	}

	@Override
	public Chese createCheese() {
		System.out.println("MozzarellaCheese Created");
		Chese c = new MozzarellaCheese();
		return c;
	}

}
