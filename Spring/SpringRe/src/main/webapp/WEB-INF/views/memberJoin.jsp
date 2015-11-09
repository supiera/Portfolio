<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ page language="java" contentType="text/html; charset=UTF-8"pageEncoding="UTF-8"%>
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form"%>
<%@ page session="false" %>
<!DOCTYPE html>
<html>
	<head>
	<script type="text/javascript" src="/resources/js/StringUtils.js"/></script>
	<script type="text/javascript" src="/resources/js/jquery-1.9.1.min.js"></script>
	<script type="text/javascript">
		function goRegister() {
		// 객체 ltrim rtrim 적용
			StringUtils.obj_trim( document.getElementById("loginPw") );
			StringUtils.obj_trim( document.getElementById("loginPwCfm") );
			if($("#loginPw").val() != $("#loginPwCfm").val()){
				alert('비밀번호가 일치하지 않습니다.');
				return;
			}
		}
		
		function goCancel() {
		}
	</script>
	
	<link href="/resources/css/style.css"rel="stylesheet" type="text/css">
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<title>회원가입</title>
	</head>
	
	<body>
		<form:form modelAttribute="member" id="insertForm" method="post">
		<div align="center" style="width: 100%;">
			<table id="newspaper-a" summary="Member List">
				<thead>
					<tr>
						<th scope="col">회원가입</th>
						<th scope="col"></th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td>*아이디</td>
						<td>
							<form:input type="text" path="loginId" maxlength="20" />
							<form:errors path="loginId" cssClass="verify"></form:errors>
						</td>
					</tr>
				
					<tr>
						<td>*비밀번호</td>
						<td>
							<form:password path="loginPw" maxlength="20" />
							<form:errors path="loginPw" cssClass="verify"></form:errors>
						</td>
					</tr>
					<tr>
						<td>*비밀번호 확인</td>
						<td><form:password path="loginPwCfm" maxlength="20" /></td>
					</tr>
					<tr>
						<td>*아이디찾기용 이메일</td>
						<td>
							<form:input type="text" path="email" maxlength="30" />
							<form:errors path="email" cssClass="verify"></form:errors>
						</td>
					</tr>
					<tr>
						<td>닉네임</td>
						<td>
							<form:input type="text" path="nickName" maxlength="10" />
							<form:errors path="nickName" cssClass="verify"></form:errors>
						</td>
					</tr>
				</tbody>
			</table>
				<div align="right" style="width: 600px;">
					<input type="button" onclick="goRegister();" value="가입">
					<input type="button" onclick="goCancel();" value="취소">
				</div>
			</div>
		</form:form>
	</body>
</html>