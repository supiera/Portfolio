package com.shc.isd;

import java.util.List;

import org.mybatis.spring.support.SqlSessionDaoSupport;
import org.springframework.stereotype.Repository;

@Repository
public class UserDaoImpl extends SqlSessionDaoSupport implements UserDao {
	
	@Override
	public List<User> selectUserList(User user) {
	// TODO Auto-generated method stub
		return getSqlSession().selectList("SqlUserMapper.selectUserList", user);
	}
	@Override
	public String selectUser(int userId) {
	// TODO Auto-generated method stub
		return getSqlSession().selectOne("SqlUserMapper.selectUser", userId);
	}
	
	@Override
	public int deleteUser(int userId) {
	// TODO Auto-generated method stub
		return getSqlSession().delete("SqlUserMapper.deleteUser", userId);
	}
	@Override
	public int insertUser(User user) {
	// TODO Auto-generated method stub
		return getSqlSession().insert("SqlUserMapper.insertUser", user);
	}
}