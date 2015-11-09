
class Job {
	private String name;
	protected AttackBehavior attackBehavior;
	
	Job(String characterName){
		this.name = characterName;
	}
	
	public String getName(){
		return this.name;
	}
	
	public void performAttack(){
		this.attackBehavior.attack();
	}
	
}
