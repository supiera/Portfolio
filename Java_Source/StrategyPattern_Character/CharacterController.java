
public class CharacterController {

	public static void main(String[] args) {
		Mage magicion = new Mage("¸¶¹ý»ç");
		Warrior warrior = new Warrior("Àü»ç");
		Hunter hunter = new Hunter("ÇåÅÍ");
		Paladin paladin = new Paladin("ÆÈ¶óµò");
		
		System.out.println(magicion.getName());
		magicion.performAttack();
		System.out.println("------------");
		
		System.out.println(warrior.getName());
		warrior.performAttack();
		System.out.println("------------");
		
		System.out.println(hunter.getName());
		hunter.performAttack();
		System.out.println("------------");
		
		System.out.println(paladin.getName());
		paladin.performAttack();
		System.out.println("------------");
		
	}

}
