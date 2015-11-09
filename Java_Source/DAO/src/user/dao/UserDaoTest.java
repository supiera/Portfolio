package user.dao;

import java.sql.SQLException;
import user.domain.User;

public class UserDaoTest {
	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		UserDao dao = new NUserDao();
		User user = new User();
		user.setId("����");
		user.setName("����");
		user.setPassword("12344");
		
		dao.add(user);
		
		System.out.println(user.getId() + "��ϼ���!");
		
		User user2 = dao.get(user.getId());
		System.out.println(user2.getName());
		System.out.println(user2.getPassword());
		
		System.out.println(user2.getId() + "��ȸ����!");
	}
}