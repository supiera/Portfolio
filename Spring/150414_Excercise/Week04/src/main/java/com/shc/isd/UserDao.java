package com.shc.isd;

import java.util.List;

public interface UserDao {
	/* 사용자 리스트 조회*/
	public List<User> selectUserList(User user);
	/* 사용자 상세 조회*/
	public String selectUser(int userId);
	/* 사용자 삭제*/
	public int deleteUser(int userId);
	/* 사용자 추가*/
	public int insertUser(User user);
}