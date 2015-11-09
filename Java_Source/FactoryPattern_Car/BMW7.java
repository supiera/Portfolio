
public class BMW7 extends Car{


	@Override
	public void setOption(String type) {
		if(type.equals("superior")){
			this.option = new Superior(new BMW7SerieseFactory());
		}
		else if(type.equals("normal")){
			this.option = new Normal(new BMW7SerieseFactory());
		}
	}
	
	/*
	 * public BMW(){this.factory = new BNWFactory;}
	 * */

}
