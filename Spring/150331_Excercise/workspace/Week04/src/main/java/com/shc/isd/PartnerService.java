package com.shc.isd;

import java.util.List;

public interface PartnerService {

	/* ��Ʈ�� ����Ʈ ��ȸ*/
	public List<Partner> selectPartnerList(Partner partner);
	/* ��Ʈ�� �� ��ȸ*/
	public String selectPartner(int partnerId);
	/* ��Ʈ�� ����*/
	public int deletePartner(int partnerId);
	/* ��Ʈ�� �߰� */
	public int insertPartner(Partner partner);
	
	
}