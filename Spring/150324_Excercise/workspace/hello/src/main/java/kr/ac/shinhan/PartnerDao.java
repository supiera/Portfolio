package kr.ac.shinhan;

import java.util.List;
import kr.ac.shinhan.Partner;

public interface PartnerDao {
	/* ��Ʈ�� ����Ʈ ��ȸ*/
	public List<Partner> selectPartnerList(Partner partner);
	/* ��Ʈ�� �� ��ȸ*/
	public String selectPartner(int partnerId);
	/* ��Ʈ�� ����*/
	public int deletePartner(int partnerId);
	/* ��Ʈ�� �߰�*/
	public int insertPartner(Partner partner);
}