package com.shc.isd.user.service;

import java.util.List;

import com.shc.isd.user.model.Partner;

public interface PartnerService {
	
	//��Ʈ�� ����Ʈ ��ȸ
	public List<Partner> selectPartnerList(Partner partner);
	//��Ʈ�� �� ��ȸ
	public String selectPartner(int partnerId);
	//��Ʈ�� ����
	public int deletePartner(int partnerId);
	//��Ʈ�� �߰�
	public int insertPartner(Partner partner);
	
}
