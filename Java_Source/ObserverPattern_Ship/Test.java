package ship;

public class Test {

	public static void main(String[] args) {
		ShipData sd = new ShipData();
		sd.registerObserver(new Navy());
		sd.registerObserver(new MarinePolice());
		sd.registerObserver(new MinOfMF());
		
		sd.addShip(new Ship("Shinhan", "KOR", "A"));
		sd.addShip(new Ship("Chinahoho", "CHN", "F"));
		sd.addShip(new Ship("Pyoung", "PRK", "D"));
		sd.addShip(new Ship("Kokomong", "KOR", "B"));
		
		sd.notifyObserver();
	}

}

