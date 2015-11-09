package com.shc.isd.member.dao;

import java.util.List;

import com.shc.isd.member.model.Member;

public interface MemberDao {
		//����� ����Ʈ ��ȸ
		public List<Member> selectMemberList(Member member);
		//����� �� ��ȸ
		public String selectMember(int userId);
		//����� ����
		public int deleteMember(int userId);
		//����� �߰�
		public int insertMember(Member member);
}
