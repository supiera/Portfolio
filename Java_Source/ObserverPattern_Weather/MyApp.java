package reweather;

public class MyApp implements Observer{

	@Override
	public void update(int t, int h, int p) {
		System.out.println("MyApp : " + t + "��, ���� " + h + "%, ���" + p);
	}

}
