package com.shc.isd.user.service;
import java.util.List;
import com.shc.isd.user.model.User;

public interface UserService {
	/*��Ʈ�� ����Ʈ ��ȸ*/
	public List<User> selectUserList(User user);
	/*��Ʈ�� �� ��ȸ*/
	public String selectUser(int userId);
	/* ��Ʈ�� ����*/
	public int deleteUser(int userId);
	/*��Ʈ�� �߰�*/
	public int insertUser(User user);
}