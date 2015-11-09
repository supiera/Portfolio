package reweather;
import java.util.ArrayList;

public class WeatherData implements Subject{
	private ArrayList<Observer> observers;
	private int cel;
	private int hum;
	private int atm;
	
	public WeatherData(){
		observers = new ArrayList<Observer>();
	}
		
	public void setMeasurement(int cel, int hum, int atm){
		this.cel = cel;
		this.hum = hum;
		this.atm = atm;
	}
	
	@Override
	public void registerObserver(Observer o) {
		observers.add(o);
	}

	@Override
	public void removeObserver(Observer o) {
		observers.remove(o);
		
	}

	@Override
	public void notifyObserver() {
		for(int i=0; i<observers.size(); i++){
			Observer o = observers.get(i);
			o.update(this.cel, this.hum, this.atm);
	}

	}
}
