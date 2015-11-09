package ship;

import java.util.ArrayList;

public class MarinePolice implements Observer{

	@Override
	public void update(ArrayList<Ship> ships) {
		System.out.println("-------MarinePolice--------");
		for(int i =0; i<ships.size(); i++){
			Ship s = ships.get(i);
			if(!s.nation.equals("KOR"))
			System.out.println(s.shipName + " : " + s.nation + " : " + s.location);
		}
		
	}

}
