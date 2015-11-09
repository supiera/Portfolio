package kr.ac.shinhan;

import java.util.List;
import kr.ac.shinhan.User;

public interface UserDao {
	/* ����� ����Ʈ ��ȸ*/
	public List<User> selectUserList(User user);
	/* ����� �� ��ȸ*/
	public String selectUser(int userId);
	/* ����� ����*/
	public int deleteUser(int userId);
	/* ����� �߰�*/
	public int insertUser(User user);
}