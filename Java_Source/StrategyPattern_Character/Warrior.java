
public class Warrior extends Job{
	Warrior(String name){
		super(name);
		this.attackBehavior = new SwordBehavior();
	}
}
