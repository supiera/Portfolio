
public class DuckController {

	public static void main(String[] args) {
		MallordDuck duck1 = new MallordDuck("û�տ���");
		System.out.println(duck1.getName());
		duck1.swim();
		duck1.performFly();
		System.out.println("------------");
		
		RubberDuck duck2 = new RubberDuck("������");
		System.out.println(duck2.getName());
		duck2.swim();
		duck2.performFly();
		System.out.println("------------");
	}

}
