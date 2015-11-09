package user.dao;

import java.sql.SQLException;
import user.domain.User;

public class UserDaoTest {
	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		UserDao dao = new NUserDao();
		User user = new User();
		user.setId("연주");
		user.setName("연중");
		user.setPassword("12344");
		
		dao.add(user);
		
		System.out.println(user.getId() + "등록성공!");
		
		User user2 = dao.get(user.getId());
		System.out.println(user2.getName());
		System.out.println(user2.getPassword());
		
		System.out.println(user2.getId() + "조회성공!");
	}
}