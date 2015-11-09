package ship;

import java.util.ArrayList;

public class ShipData implements Subject{

	private ArrayList<Observer> observers;
	private ArrayList<Ship> ships;
	
	public ShipData(){
		observers = new ArrayList<Observer>();
		ships = new ArrayList<Ship>();
	}
	
	public void addShip(Ship s){
		ships.add(s);
	}
	
	public void removeShip(Ship s){
		ships.remove(s);
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
			o.update(ships);
		}
		
	}
	
}
