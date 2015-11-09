    window.onload = function() {
		var url = "http://jsonplaceholder.typicode.com/users.json";
		var request = new XMLHttpRequest();
		request.open("GET", url);
	}
	
    request.onload = function () {
	    if (request.status == 200) {
	        alert(request.responseText);
	    }
	    request.send(null);
	}	