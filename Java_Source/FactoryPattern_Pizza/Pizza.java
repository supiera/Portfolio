
public abstract class Pizza {
	public String name;
	public Dough dough;
	public Source sauce;
	public Chese cheese;
	public Topping topping;
	public PizzaFactory factory;
	
	public Pizza(String name, PizzaFactory factory){
		this.name = name;
		this.factory = factory;
	}
	
	public void prefare(){
		this.cheese = factory.createCheese();
		this.dough = factory.createDough();
		this.sauce = factory.createSauce();
	}
	
	public abstract void topping();
	
	public void bake(){
		System.out.println("피자를 굽는다");
	}
	public void cut(){
		System.out.println("피자를 자른다");
	}
	public void box(){
		System.out.println("피자를 포장한다");
	}
	
}
