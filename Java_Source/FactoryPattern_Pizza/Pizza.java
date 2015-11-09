
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
		System.out.println("���ڸ� ���´�");
	}
	public void cut(){
		System.out.println("���ڸ� �ڸ���");
	}
	public void box(){
		System.out.println("���ڸ� �����Ѵ�");
	}
	
}
