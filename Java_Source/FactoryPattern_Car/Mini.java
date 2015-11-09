
public class Mini extends Car{

	@Override
	public void setOption(String type) {
		if(type.equals("superior")){
			this.option = new Superior(new MiniFactory());
		}
		else if(type.equals("normal")){
			this.option = new Normal(new MiniFactory());
			
		}
		
	}

}
