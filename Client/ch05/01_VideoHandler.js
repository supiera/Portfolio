var playlist
var video = new Array();
var position = 0;
var combo;
window.onload = function(){
	playlist = ["media/preroll.mp4" , "media/areyoupopular.mp4", "media/destinationearth.mp4"]
	video = document.getElementById("video");
	combo = document.getElementById("videos");
	video.src = playlist[position];
	video.load();
	video.play();
	combo.onchange = videoChanged; 
	
	///video.addEventListener("ended", nextVideo, false);
	//video.src = playlist[position];
}

function videoChanged(){
	for(var i = 0; i<combo.length; i++){
		if(combo.value == i){
			video.src = playlist[i];
			video.load();
			video.play();
		}
	}
}

/*
function nextVideo(){
	position++;
	if (position >= playlist.length)
		position = 0;
	
	
}*/