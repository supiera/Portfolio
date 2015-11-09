package com.shc.isd.user.service;
import java.util.List;
import com.shc.isd.user.model.User;

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