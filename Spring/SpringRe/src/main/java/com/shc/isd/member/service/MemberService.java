package com.shc.isd.member.service;

import java.util.List;

import com.shc.isd.member.model.Member;

public interface MemberService {
	public List<Member> selectMemberList(Member member);
	public String selectMember(int userId);
	public int deleteMember(int userId);
	public int insertMember(Member member);
}
