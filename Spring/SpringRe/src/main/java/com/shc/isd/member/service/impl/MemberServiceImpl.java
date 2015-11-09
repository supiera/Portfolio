package com.shc.isd.member.service.impl;

import java.util.List;

import javax.annotation.Resource;
import org.springframework.stereotype.Service;
import com.shc.isd.member.dao.MemberDao;
import com.shc.isd.member.model.Member;
import com.shc.isd.member.service.MemberService;


@Service
public class MemberServiceImpl implements MemberService{

	@Resource
	private MemberDao memberDao;
	
	@Override
	public List<Member> selectMemberList(Member member) {
		return memberDao.selectMemberList(member);
	}

	@Override
	public String selectMember(int userId) {
		return memberDao.selectMember(userId);
	}

	@Override
	public int deleteMember(int userId) {
		return memberDao.deleteMember(userId);
	}

	@Override
	public int insertMember(Member member) {
		return memberDao.insertMember(member);
	}
}
