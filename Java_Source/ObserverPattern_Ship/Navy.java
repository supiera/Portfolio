package ship;

import java.util.ArrayList;

public class Navy implements Observer{

	@Override
	public void update(ArrayList<Ship> ships) {
		System.out.println("-------Navy--------");
		for(int i =0; i<ships.size(); i++){
			Ship s = ships.get(i);
			System.out.println(s.shipName + " : " + s.nation + " : " + s.location);
		}
	}

}
