package com.shc.isd;

import java.util.List;

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