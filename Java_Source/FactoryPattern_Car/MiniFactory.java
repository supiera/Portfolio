
public class MiniFactory implements CarFactory{

	@Override
	public Wheel createWheel() {
		System.out.println("8��ġ �� ����");
		Wheel w = new Wheel8();
		return w;
	}

	@Override
	public Engine createEngine() {
		System.out.println("1.6 ���� ���� ����");
		Engine e = new Engine16();
		return e;
	}

}
