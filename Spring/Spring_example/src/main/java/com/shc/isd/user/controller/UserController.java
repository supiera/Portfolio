package com.shc.isd.user.controller;

import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;

import com.shc.isd.user.model.Partner;
import com.shc.isd.user.model.User;
import com.shc.isd.user.service.PartnerService;
import com.shc.isd.user.service.UserService;

@Controller
@RequestMapping(value = "/user")
public class UserController {
	private static final Logger log = LoggerFactory.getLogger(UserController.class);
	@Autowired
	private PartnerService partnerService;
	@Autowired
	private UserService userService;
	@RequestMapping(value = {"/List/"})
	public String getUserList(ModelMap map, @ModelAttribute User user ){
		Partner partner = new Partner();
		//��Ʈ�� ��� ��������
		List<Partner> partnerList = partnerService.selectPartnerList(partner);
		//����� ��� ��������
		List<User> userList = userService.selectUserList(user);
		log.debug("User List Count : " + userList.size());
		map.addAttribute("searchData", user);
		map.addAttribute("partnerList", partnerList);
		map.addAttribute("userList", userList);
		return "userList";
	}
	@RequestMapping(value = {"/Create/"})
	public String getUserCreate(ModelMap map, @ModelAttribute User user){
	Partner partner = new Partner();
	List<Partner> partnerData = partnerService.selectPartnerList(partner);
	log.debug("User List Count(Create) : " + partnerData.size());
	map.addAttribute("partnerData", partnerData);
	map.addAttribute("searchData", user);
	return "createUser";      
	}
	@RequestMapping(value = {"/Delete/"})
	public String deleteUser(ModelMap map, @ModelAttribute User user){
	log.debug("Delete User ID : " + user.getDelId());

	userService.deleteUser(user.getDelId());

	List<User> userData = userService.selectUserList(user);
	log.debug("User List Count(Delete) : " + userData.size());
	map.addAttribute("searchData", user);
	map.addAttribute("userData", userData);
	return "userList";
	}
	@RequestMapping(value = {"/Save/"})
	public String saveUser(ModelMap map, @ModelAttribute User user){
	log.info("User List Count(Save) : ");
	userService.insertUser(user);
	Partner partner = new Partner();
	user = new User();
	List<User> userData = userService.selectUserList(user);
	List<Partner> partnerData = partnerService.selectPartnerList(partner);
	log.debug("User List Count(Save) :"+ userData.size());
	map.addAttribute("searchData", user);
	map.addAttribute("userData", userData);
	map.addAttribute("partnerData", partnerData);
	return "userList";
	}
}
