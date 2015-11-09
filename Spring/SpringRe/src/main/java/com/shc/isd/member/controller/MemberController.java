package com.shc.isd.member.controller;

import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;

import com.shc.isd.member.model.Member;
import com.shc.isd.member.service.MemberService;

@Controller
@RequestMapping(value = "/login")
public class MemberController {
	private static final Logger log = LoggerFactory.getLogger(MemberController.class);
	@Autowired
	private MemberService memberService;
	
/*	@RequestMapping(value = {"/List/"})
	public String getUserList(ModelMap map, @ModelAttribute Member member){
		//사용자 목록 가져오기
		List<Member> memberList = memberService.selectMemberList(member);
		log.debug("User List Count : " + memberList.size());
		map.addAttribute("searchData", member);
		map.addAttribute("memberList", memberList);
		return "memberList";
	}*/
	
	@RequestMapping(value = {"/memberJoin/"})
	public String memberJoin(ModelMap map, @ModelAttribute Member member){
		
		return "memberList";
	}
	
	@RequestMapping(value = {"/loginProcess/"})
	public String loginProcess(ModelMap map, @ModelAttribute Member member){
		
		return "memberList";
	}
	
	
	@RequestMapping(value = {"/Save/"})
	public String saveMember(ModelMap map, @ModelAttribute Member member){
		log.info("Member List Count(Save) : ");
		memberService.insertMember(member);
		
		member = new Member();
		List<Member> memberData = memberService.selectMemberList(member);
		log.debug("Member List Count(Save) :"+ memberData.size());
		map.addAttribute("searchData", member);
		map.addAttribute("memberData", memberData);

		return "memberList";
	}
}
