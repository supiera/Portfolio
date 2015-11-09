package com.shc.isd.user.dao.impl;

import java.util.List;

import org.mybatis.spring.support.SqlSessionDaoSupport;
import org.springframework.stereotype.Repository;

import com.shc.isd.user.dao.UserDao;
import com.shc.isd.user.model.User;

@Repository
public class UserDaoImpl extends SqlSessionDaoSupport implements UserDao {
	@Override
	public List<User> selectUserList(User user) {
		return getSqlSession().selectList("SqlUserMapper.selectUserList", user);
	}
	@Override
	public String selectUser(int userId) {
		return getSqlSession().selectOne("SqlUserMapper.selectUser", userId);
	}
	@Override
	public int deleteUser(int userId) {
		return getSqlSession().delete("SqlUserMapper.deleteUser", userId);
	}
	@Override
	public int insertUser(User user) {
		return getSqlSession().insert("SqlUserMapper.insertUser", user);
	}
}
