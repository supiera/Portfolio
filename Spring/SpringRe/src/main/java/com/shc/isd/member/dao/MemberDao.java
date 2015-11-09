package com.shc.isd.member.dao;

import java.util.List;

import com.shc.isd.member.model.Member;

public interface MemberDao {
		//사용자 리스트 조회
		public List<Member> selectMemberList(Member member);
		//사용자 상세 조회
		public String selectMember(int userId);
		//사용자 삭제
		public int deleteMember(int userId);
		//사용자 추가
		public int insertMember(Member member);
}
