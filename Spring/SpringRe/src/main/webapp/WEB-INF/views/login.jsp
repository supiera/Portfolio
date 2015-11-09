<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ page language="java" contentType="text/html; charset=UTF-8"pageEncoding="UTF-8"%>
<%@ page trimDirectiveWhitespaces="true" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form"%>
<%@ taglib prefix="spring" uri="http://www.springframework.org/tags"%>
<%@ page session="false" %>
<!DOCTYPE html>
<html>
	<head>
	<script type="text/javascript" src="/resources/js/jquery-1.9.1.min.js"/></script>
	<script type="text/javascript" src="/resources/js/StringUtils.js"/></script>
	<link href="/resources/css/style.css"rel="stylesheet" type="text/css">
	<script type="text/javascript">
		
		$(function() {
			$("#goLoginBtn").click(function() {
				// 객체 ltrim rtrim 적용
				StringUtils.obj_trim( document.getElementById("loginId") );
				StringUtils.obj_trim( document.getElementById("loginPw") );
			$("#loginForm").attr({
				action : "<%=request.getContextPath()%>/login/loginProcess/",
				target : "_self",
				method : "post"
			}).submit();
			});
		});
		function goJoin() {
		}
	</script>
	
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<title>로그인 페이지</title>
	
	</head>
	<body>
		<form:form id="loginForm" name="loginForm" modelAttribute="member" method="post">
			<div class="login">
				<!-- [s]content -->
				<div class="loginbox">
					<p class="write">
						<span class="txt">아이디</span>
						<!-- 오류 메세지 <p class="verify">아이디를 입력해 주세요.</p>-->
						<form:errors path="loginId" cssClass="verify"></form:errors>
						<form:errors path="authSt" cssClass="verify"></form:errors>
						<!-- 아이디 입력란 --><form:input path="loginId" />
					</p>
					
					<p class="write">
						<span class="txt">비밀번호</span>
						<!-- 오류 메세지 <p class="verify">비밀번호를 입력해 주세요.</p>-->
						<form:errors path="loginPw" cssClass="verify"></form:errors>
						<!-- 비밀번호 입력란 --><form:password path="loginPw" />
					</p>
					
					<p class="join">
						<label style="margin-left: 10px;"><a href="javascript:goJoin();return false;">회원가입</a></label>
					</p>
					
					<p class="btn"><span>
						<button type="button" id="goLoginBtn">Log In</button></span>
					</p>
				</div>
			</div>
		</form:form>
	</body>
</html>