package com.shc.isd.user.service.impl;

import java.util.List;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.shc.isd.user.dao.UserDao;
import com.shc.isd.user.model.User;
import com.shc.isd.user.service.UserService;

@Service
public class UserServiceImpl implements UserService{

	@Resource
	private UserDao userDao;
	@Override
	public List<User> selectUserList(User user) {
		return userDao.selectUserList(user);
	}

	@Override
	public String selectUser(int userId) {
		return userDao.selectUser(userId);
	}

	@Override
	public int deleteUser(int userId) {
		return userDao.deleteUser(userId);
	}

	@Override
	public int insertUser(User user) {
		return userDao.insertUser(user);
	}
	
}
