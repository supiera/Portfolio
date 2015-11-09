onmessage = pingpong;

function pingpong(event){
	if(event.data == "ping")
		postMessage("pong");
	else
		postMessage("give me ping");
	
}