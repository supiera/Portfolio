package com.shc.isd;

import java.util.List;

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