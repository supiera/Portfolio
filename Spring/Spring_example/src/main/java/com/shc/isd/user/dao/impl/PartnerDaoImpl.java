package com.shc.isd.user.dao.impl;

import java.util.List;

import org.mybatis.spring.support.SqlSessionDaoSupport;
import org.springframework.stereotype.Repository;

import com.shc.isd.user.dao.PartnerDao;
import com.shc.isd.user.model.Partner;

@Repository
public class PartnerDaoImpl extends SqlSessionDaoSupport
	implements PartnerDao{

	@Override
	public List<Partner> selectPartnerList(Partner partner) {
		return getSqlSession().selectList("SqlPartnerMapper.selectPartnerList", partner);
	}
	@Override
	public String selectPartner(int partnerId) {
		return getSqlSession().selectOne("SqlPartnerMapper.selectPartner", partnerId);
	}
	@Override
	public int deletePartner(int partnerId) {
		return getSqlSession().delete("SqlPartnerMapper.deletePartner", partnerId);
	}
	@Override
	public int insertPartner(Partner partner) {
		return getSqlSession().insert("SqlPartnerMapper.insertPartner", partner);
	}
	
}
