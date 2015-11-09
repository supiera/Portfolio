package com.shc.isd;

import java.util.List;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

//import org.springframework.beans.factory.annotation.Required;

@Service
public class PartnerServiceImpl implements PartnerService{
	
	@Resource
	private PartnerDao partnerDao;
	
	@Override
	public List<Partner> selectPartnerList(Partner partner){
		return partnerDao.selectPartnerList(partner);
	}
	
	@Override
	public String selectPartner(int partnerId) {
	// TODO Auto-generated method stub
	return partnerDao.selectPartner(partnerId);
	}
	
	@Override
	public int deletePartner(int partnerId) {
	// TODO Auto-generated method stub
	return partnerDao.deletePartner(partnerId);
	}
	@Override
	public int insertPartner(Partner partner) {
	// TODO Auto-generated method stub
	return partnerDao.insertPartner(partner);
	}

}
