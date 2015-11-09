package reweather;

public class YahooApp implements Observer{

	@Override
	public void update(int t, int h, int p) {
		System.out.println("YahooApp : " + t + "µµ/" + h + "%");
	}

}
