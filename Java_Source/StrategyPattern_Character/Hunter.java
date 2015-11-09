
public class Hunter extends Job{
	
	Hunter(String name){
		super(name);
		this.attackBehavior = new BowBehavior();
	}
}
