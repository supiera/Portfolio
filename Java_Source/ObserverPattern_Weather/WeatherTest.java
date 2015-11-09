package reweather;

public class WeatherTest {

	public static void main(String[] args) {
		WeatherData weatherData = new WeatherData();
		
		YahooApp yahooApp = new YahooApp();
		MyApp myApp = new MyApp();
		weatherData.registerObserver(yahooApp);
		weatherData.registerObserver(myApp);
		
		weatherData.setMeasurement(25, 60, 30);
		weatherData.notifyObserver();
		weatherData.setMeasurement(27, 55, 32);
		weatherData.notifyObserver();

	}

}
