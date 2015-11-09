
public class Paladin extends Job{
	
	Paladin(String name){
		super(name);
		this.attackBehavior = new SwordBehavior();
	}
}
