package com.shc.isd;

import java.util.List;

import org.mybatis.spring.support.SqlSessionDaoSupport;
import org.springframework.stereotype.Repository;

@Repository
public class PartnerDaoImpl extends SqlSessionDaoSupport implements PartnerDao {
	@Override
	public List<Partner> selectPartnerList(Partner partner) {
	// TODO Auto-generated method stub
	return getSqlSession().selectList("SqlPartnerMapper.selectPartnerList", partner);
	}

	@Override
	public String selectPartner(int partnerId) {
	// TODO Auto-generated method stub
	return getSqlSession().selectOne("SqlPartnerMapper.selectPartner", partnerId);
	}
	
	@Override
	public int deletePartner(int partnerId) {
	// TODO Auto-generated method stub
	return getSqlSession().delete("SqlPartnerMapper.deletePartner", partnerId);
	}
	@Override
	public int insertPartner(Partner partner) {
	// TODO Auto-generated method stub
	return getSqlSession().insert("SqlPartnerMapper.insertPartner", partner);
	}
}

