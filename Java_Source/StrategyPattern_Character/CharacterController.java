
public class CharacterController {

	public static void main(String[] args) {
		Mage magicion = new Mage("������");
		Warrior warrior = new Warrior("����");
		Hunter hunter = new Hunter("����");
		Paladin paladin = new Paladin("�ȶ��");
		
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
