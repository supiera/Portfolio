package kr.ac.shinhan;

import java.util.List;
import kr.ac.shinhan.Partner;

public interface PartnerDao {
	/* 파트너 리스트 조회*/
	public List<Partner> selectPartnerList(Partner partner);
	/* 파트너 상세 조회*/
	public String selectPartner(int partnerId);
	/* 파트너 삭제*/
	public int deletePartner(int partnerId);
	/* 파트너 추가*/
	public int insertPartner(Partner partner);
}