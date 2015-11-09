
public class Mage extends Job{
	public Mage(String name){
		super(name);
		this.attackBehavior = new MagicBehavior();
	}
}
