<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form"%>
<%@ page session="false"%>
<!DOCTYPE html>
<html>
<head>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script> 
	
</script>
<script type="text/javascript">
	function goRegister() {
		if ($("#userName").val() == '') {
			alert('회원 이름을 입력하세요.');
			return;
		}
		if ($("#userAge").val() == 0) {
			alert('나이를 입력하세요.');
			return;
		}
		if ($("#userNickName").val() == '') {
			alert('회원 닉네임을 입력하세요.');
			return;
		}
		$("#insertForm").attr({
			action : "/shinhan/user/Save/",
			method : "post"
		}).submit();
	}
	function goCancel() {
		$("#insertForm").attr({
			action : "/shinhan/user/List/",
			method : "post"
		}).submit();
	}
</script>
<style type="text/css">
<!--
body {
	line-height: 1.6em;
}

#newspaper-a {
	font-family: "Lucida Sans Unicode", "Lucida Grande", Sans-Serif;
	font-size: 12px;
	margin: 45px;
	width: 600px;
	text-align: left;
	border-collapse: collapse;
	border: 1px solid #69c;
}

#newspaper-a th {
	padding: 12px 17px 12px 17px;
	font-weight: normal;
	font-size: 14px;
	color: #039;
	border-bottom: 1px dashed #69c;
}

#newspaper-a td {
	padding: 7px 17px 7px 17px;
	color: #669;
}

#newspaper-a tbody tr:hover td {
	color: #339;
	background: #d0dafd;
}
-->
</style>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>신규 회원 입력</title>
</head>
<body>
	<form:form modelAttribute="searchData" id="insertForm" method="post">
		<div align="center" style="width: 100%;"></div>
		<table id="newspaper-a" summary="User List">
			<thead>
				<tr>
					<th scope="col">항목</th>
					<th scope="col"></th>
				</tr>
			</thead>
			<tbody>
				<tr>
					<td>파트너명</td>
					<td><form:select path="partnerId">
							<c:forEach var="data" items="${partnerData}" varStatus="status">
								<form:option value="${data.partnerId}"
									label="${data.partnerName}" />
							</c:forEach>
						</form:select></td>
				</tr>
				<tr>
					<td>사용자명</td>
					<td><form:input type="text" path="userName" maxlength="10" /></td>
				</tr>
				<tr>
					<td>나이</td>
					<td><form:input type="text" path="userAge" maxlength="2" /></td>
				</tr>
				<tr>
					<td>닉네임</td>
					<td><form:input type="text" path="userNickName" maxlength="10" /></td>
				</tr>
			</tbody>
		</table>
		<div align="right" style="width: 600px;">
			<input type="button" onclick="goRegister();" value="저장"> <input
				type="button" onclick="goCancel();" value="취소">
		</div>
	</form:form>
</body>
</html>