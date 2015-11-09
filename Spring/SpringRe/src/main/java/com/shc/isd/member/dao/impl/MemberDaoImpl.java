package com.shc.isd.member.dao.impl;

import java.util.List;

import org.mybatis.spring.support.SqlSessionDaoSupport;
import org.springframework.stereotype.Repository;

import com.shc.isd.member.dao.MemberDao;
import com.shc.isd.member.model.Member;

@Repository
public class MemberDaoImpl extends SqlSessionDaoSupport 
	implements MemberDao {
	@Override
	public List<Member> selectMemberList(Member member) {
		return getSqlSession().selectList("SqlMemberMapper.selectMemberList", member);
	}
	@Override
	public String selectMember(int userId) {
		return getSqlSession().selectOne("SqlMemberMapper.selectMember", userId);
	}
	@Override
	public int deleteMember(int userId) {
		return getSqlSession().delete("SqlMemberMapper.deleteMember", userId);
	}
	@Override
	public int insertMember(Member member) {
		return getSqlSession().insert("SqlMemberMapper.insertMember", member);
	}
}
