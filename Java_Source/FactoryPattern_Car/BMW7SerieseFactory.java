
public class BMW7SerieseFactory implements CarFactory{

	@Override
	public Wheel createWheel() {
		System.out.println("10ÀÎÄ¡ ÈÙ ÀåÂø");
		Wheel w = new Wheel16();
		return w;
	}

	@Override
	public Engine createEngine() {
		System.out.println("3.0 ±âÅë ¿£Áø ÀåÂø");
		Engine e = new Engine30();
		return e;
	}

}
