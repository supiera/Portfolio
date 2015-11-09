package com.shc.isd;

import java.util.List;

public interface UserService {
	/*파트너 리스트 조회*/
	public List<User> selectUserList(User user);
	/*파트너 상세 조회*/
	public String selectUser(int userId);
	/* 파트너 삭제*/
	public int deleteUser(int userId);
	/*파트너 추가*/
	public int insertUser(User user);
}